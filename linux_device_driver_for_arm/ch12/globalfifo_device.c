#include <linux/miscdevice.h>
#include <linux/platform_device.h>
#include <linux/module.h>

static struct platform_device *globalfifo_pdev;

static int __init globalfifodev_init(void)
{
	int ret;

	globalfifo_pdev = platform_device_alloc("globalfifo", -1);
	if (!globalfifo_pdev)
		return -ENOMEM;

	ret = platform_device_add(globalfifo_pdev);
	if (ret) {
		platform_device_put(globalfifo_pdev);
		return ret;
	}

	return 0;
}
module_init(globalfifodev_init);

static void __exit globalfifodev_exit(void)
{
	platform_device_unregister(globalfifo_pdev);
}
module_exit(globalfifodev_exit);
MODULE_LICENSE("GPL v2");
