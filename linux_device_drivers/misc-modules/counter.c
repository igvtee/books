#include <linux/init.h>		/* module_init */
#include <linux/module.h>	/* MODULE_XXXX */
#include <linux/kthread.h>	/* kthread_run */
#include <linux/delay.h>	/* ssleep */
#include <linux/proc_fs.h>	/* proc_create */
#include <asm/uaccess.h>	/* copy_*_user */

#define PROC_NAME "counter"

static struct task_struct *kthread;
static int counter;

static int counter_run(void *data)
{
	while (!kthread_should_stop()) {
		ssleep(1);
		counter++;
	}
	printk(KERN_INFO "The counter thread has terminated\n");
	return counter;
}

static ssize_t counter_proc_read(struct file *file, char __user *buf,
				 size_t size, loff_t *offset)
{
	char msg[64];
	int len;

	/* only read once. then EOF */
	if (*offset)
		return 0;

	len = snprintf(msg, sizeof(msg), "The counter is now at: %d\n",
		       counter);
	msg[sizeof(msg) - 1] = '\0';

	if (len > size)
		len = size;
	if (copy_to_user(buf, msg, len))
		return -EFAULT;

	return len;
}

static struct file_operations counter_proc_ops = {
        .owner   = THIS_MODULE,
        .read    = counter_proc_read,
};

static int __init counter_init(void)
{
	kthread = kthread_run(counter_run, NULL, "kcounter");
	if (IS_ERR(kthread)) {
		printk(KERN_ERR "kthread_run failed\n");
		return PTR_ERR(kthread);
	}

	if (!proc_create(PROC_NAME, 0, NULL, &counter_proc_ops)) {
		printk(KERN_ERR "proc_create failed\n");
		return -ENOMEM;
	}

	return 0;
}

static void __exit counter_exit(void)
{
	remove_proc_entry(PROC_NAME, NULL);

	if (kthread_stop(kthread) != -EINTR)
		printk(KERN_INFO "Counter thread has stopped\n");
}

module_init(counter_init);
module_exit(counter_exit);

MODULE_AUTHOR("Michael Lee");
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("demo module for kthread counter");
