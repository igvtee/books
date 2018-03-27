#include <linux/module.h>
#include <linux/slab.h>

static struct kmem_cache *fcache;
static void *buf;

static int __init fcache_init(void)
{
	fcache = kmem_cache_create("figo_object", 20, 8, 0, NULL);
	if (!fcache) {
		kmem_cache_destroy(fcache);
		return -ENOMEM;
	}

	buf = kmem_cache_zalloc(fcache, GFP_KERNEL);
	return 0;
}

static void __exit fcache_exit(void)
{
	kmem_cache_free(fcache, buf);
	kmem_cache_destroy(fcache);
}

module_init(fcache_init);
module_exit(fcache_exit);
MODULE_LICENSE("GPL");
