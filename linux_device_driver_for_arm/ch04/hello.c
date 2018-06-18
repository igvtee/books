/*
 * a simple kernel module: hello
 */

#include <linux/init.h>
#include <linux/module.h>

static int hello_data __initdata = 1;

static int __init hello_init(void)
{
	printk(KERN_INFO "Hello World enter %d\n", hello_data);
	return 0;
}
module_init(hello_init);

static void __exit hello_exit(void)
{
	printk(KERN_INFO "Hello World exit\n");
}
module_exit(hello_exit);

MODULE_AUTHOR("Michael Lee <igvtee@gmail.com>");
MODULE_LICENSE("GPL v2");
MODULE_DESCRIPTION("A simple Hello World Module");
MODULE_ALIAS("a simplest module");
