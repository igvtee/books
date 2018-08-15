#define pr_fmt(fmt) "slub test: %s " fmt, __func__

#include <linux/init.h>		/* module_init */
#include <linux/module.h>	/* MODULE_XXXX */
#include <linux/slab.h>		/* kmalloc */
#include <linux/proc_fs.h>	/* proc_create */
#include <asm/uaccess.h>	/* copy_XXXX_user */
#include <linux/stat.h>		/* S_IRUGO */
#include <linux/gfp.h>		/* __get_free_page */

#define PROC_NAME "test_slub"

#define TRACK_ADDRS_COUNT 16
struct track {
	unsigned long addr;     /* Called from address */
#ifdef CONFIG_STACKTRACE
	unsigned long addrs[TRACK_ADDRS_COUNT]; /* Called from address */
#endif
	int cpu;                /* Was running on cpu */
	int pid;                /* Pid context */
	unsigned long when;     /* When did the operation occur */
};

static struct kmem_cache *slab;

/* Redzone overwritten */
static void kmalloc_oob_right(void)
{
        char *ptr;

        ptr = kmem_cache_alloc(slab, GFP_KERNEL);
        if (!ptr) {
                pr_err("Allocation failed\n");
                return;
        }
        pr_info("out-of-bounds to right. size: %zu\n", ksize(ptr));

        ptr[ksize(ptr)] = 'E';
        kmem_cache_free(slab, ptr);
}

/* Redzone overwritten */
static void kmalloc_oob_left(void)
{
        char *ptr;

        ptr = kmem_cache_alloc(slab, GFP_KERNEL);
        if (!ptr) {
                pr_err("Allocation failed\n");
                return;
        }
        pr_info("out-of-bounds to left. size: %zu\n", ksize(ptr));

	ptr[-1] = 'E';
        kmem_cache_free(slab, ptr);
}

/* Freepointer corrupt */
static void kmalloc_oob_fp(void)
{
        char *ptr;
	size_t size;

        ptr = kmem_cache_alloc(slab, GFP_KERNEL);
        if (!ptr) {
                pr_err("Allocation failed\n");
                return;
        }
        pr_info("out-of-bounds at freepointer. size: %zu\n", ksize(ptr));

	size = ksize(ptr);
	/* redzone */
	size += sizeof(void *);
        ptr[size] = 'E';
        kmem_cache_free(slab, ptr);
}

/* Object padding overwritten */
static void kmalloc_oob_padding(void)
{
	char *ptr;
	size_t size;

	ptr = kmem_cache_alloc(slab, GFP_KERNEL);
	if (!ptr) {
		pr_err("Allocation failed\n");
		return;
	}
        pr_info("out-of-bounds in padding. size: %zu\n", ksize(ptr));

	size = 0;
	/* objsize */
	size += ksize(ptr);
	/* redzone */
	size += sizeof(void *);
	/* freepointer */
	size += sizeof(void *);
	/* stacktrace */
#ifdef CONFIG_STACKTRACE
	size += 2 * sizeof(struct track);
#endif
        ptr[size] = 'E';
	kmem_cache_free(slab, ptr);
}

static void kmalloc_object_padding(void)
{
	char *ptr;
	size_t size = 32;

	ptr = kmalloc(size, GFP_KERNEL);
	if (!ptr) {
		pr_err("Allocation failed\n");
		return;
	}
	pr_info("kmalloc size %zu. got size: %zu\n", size, ksize(ptr));

	/* we need 32. but system gave us 64. so it fine to use
	 * up to 64 without error
	 */
	memset(ptr, 'E', ksize(ptr));
	kfree(ptr);
}

/* Poison overwritten */
static void kmalloc_uaf(void)
{
	char *ptr;

	ptr = kmem_cache_alloc(slab, GFP_KERNEL);
	if (!ptr) {
		pr_err("Allocation failed\n");
		return;
	}
	pr_info("use-after-free. size: %zu\n", ksize(ptr));

	kmem_cache_free(slab, ptr);
	ptr[0] = 'E';
}

/* Sanity checks: double free */
static void kmalloc_double_free(void)
{
	char *ptr;

	ptr = kmem_cache_alloc(slab, GFP_KERNEL);
	if (!ptr) {
		pr_err("Allocation failed\n");
		return;
	}
	pr_info("Sanity checks: double free. size: %zu\n", ksize(ptr));

	kmem_cache_free(slab, ptr);
	kmem_cache_free(slab, ptr);
}

/* CONFIG_DEBUG_PAGEALLOC */
static void debug_page_alloc(void)
{
	char *buf;

	pr_info("pagealloc: use-after-free\n");
	buf = (char *)__get_free_page(GFP_KERNEL);
	if (!buf)
		return;
	free_page((unsigned long)buf);
	buf[0] = 'E';
}

static ssize_t test_slub_proc_read(struct file *file, char __user *buf,
				 size_t size, loff_t *offset)
{
	char *msg = "1: object padding test no error.\n"
		"2: out-of-bounds to right.\n"
		"3: out-of-bounds to left.\n"
		"4: out-of-bounds to free pointer.\n"
		"5: out-of-bounds to padding.\n"
		"6: use-after-free.\n"
		"7: double-free.\n"
		"8: debug pagealloc.\n";
	int len;

	/* only read once. then EOF */
	if (*offset)
		return 0;

	len = strlen(msg);
	if (len > size)
		len = size;
	if (copy_to_user(buf, msg, len))
		return -EFAULT;

	return len;
}

static ssize_t test_slub_proc_write(struct file *filp, const char __user *buf,
			      size_t count, loff_t *pos)
{
	unsigned char *kbuf;
	unsigned long item;
	ssize_t retval;

	kbuf = kmalloc(count, GFP_KERNEL);
	if (!kbuf)
		return -ENOMEM;

	if (copy_from_user(kbuf, buf, count)) {
		retval = -EFAULT;
		goto out;
	}
	kbuf[count-1] = '\0';
	if (kstrtoul(kbuf, 0, &item)) {
		retval = -EINVAL;
		goto out;
	}

	switch (item) {
	case 1:
		kmalloc_object_padding();
		break;
	case 2:
		kmalloc_oob_right();
		break;
	case 3:
		kmalloc_oob_left();
		break;
	case 4:
		kmalloc_oob_fp();
		break;
	case 5:
		kmalloc_oob_padding();
		break;
	case 6:
		kmalloc_uaf();
		break;
	case 7:
		kmalloc_double_free();
		break;
	case 8:
		debug_page_alloc();
		break;
	default:
		printk("c");
		retval = -EINVAL;
		goto out;
		break;
	}

	retval = count;
out:
	kfree(kbuf);
	return retval; /* succeed, to avoid retrial */
}

static struct file_operations test_slub_proc_ops = {
        .owner	= THIS_MODULE,
        .read	= test_slub_proc_read,
        .write	= test_slub_proc_write,
};


static int __init test_slub_init(void)
{
	slab = kmem_cache_create("test_slub", 17, 0, 0, NULL);
	if (!slab)
		return -ENOMEM;

	if (!proc_create(PROC_NAME, S_IRUGO | S_IWUGO, NULL,
			 &test_slub_proc_ops)) {
		printk(KERN_ERR "proc_create failed\n");
		return -ENOMEM;
	}

	return 0;
}

static void __exit test_slub_exit(void)
{
	remove_proc_entry(PROC_NAME, NULL);
	kmem_cache_destroy(slab);
}

module_init(test_slub_init);
module_exit(test_slub_exit);

MODULE_AUTHOR("Michael Lee");
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("demo module for test slub debug");
