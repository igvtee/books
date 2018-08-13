#define pr_fmt(fmt) "slub test: %s " fmt, __func__

#include <linux/init.h>		/* module_init */
#include <linux/module.h>	/* MODULE_XXXX */
#include <linux/slab.h>		/* kmalloc */

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

	ptr = kmem_cache_alloc(slab, GFP_KERNEL);
	if (!ptr) {
		pr_err("Allocation failed\n");
		return;
	}
	pr_info("in object padding no error. size: %zu\n", ksize(ptr));

	/* we need 32. but system gave us 64. so it fine to use
	 * up to 64 without error
	 */
	memset(ptr, 'E', ksize(ptr));
	kmem_cache_free(slab, ptr);
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

static int __init test_slub_init(void)
{
	slab = kmem_cache_create("test_slub", 17, 0, 0, NULL);
	if (!slab)
		return -ENOMEM;

	kmalloc_object_padding();
	kmalloc_oob_right();
	kmalloc_oob_left();
	kmalloc_oob_fp();
	kmalloc_oob_padding();
	kmalloc_uaf();
	kmalloc_double_free();

	return 0;
}

static void __exit test_slub_exit(void)
{
	kmem_cache_destroy(slab);
}

module_init(test_slub_init);
module_exit(test_slub_exit);

MODULE_AUTHOR("Michael Lee");
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("demo module for test slub debug");
