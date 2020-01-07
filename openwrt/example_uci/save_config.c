#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <uci.h>

#define CONFIG_DIR "./config"

int main(void)
{
	struct uci_context *ctx;
	struct uci_package *pkg;
	struct uci_ptr ptr, tptr;
	int ret = 1;

	ctx = uci_alloc_context();
	if (!ctx) {
		printf("Out of memory\n");
		return 1;
	}

	if ((ret = uci_set_confdir(ctx, CONFIG_DIR))) {
		uci_perror(ctx, "uci_set_confdir");
		goto error;
	}

	if (UCI_OK != uci_load(ctx, "network", &pkg)) {
		uci_perror(ctx, "uci_load");
		goto error;
	}

	/* find wan section */
	memset(&ptr, 0, sizeof(struct uci_ptr));
	ptr.p = pkg;
	ptr.section = "wan";
	if (UCI_OK != uci_lookup_ptr(ctx, &ptr, NULL, false))
		goto error;

	/* set string option */
	ptr.option = "value";
	ptr.value = "1";
	uci_set(ctx, &ptr);

	ptr.option = "value2";
	ptr.value = "2";
	uci_set(ctx, &ptr);

	/* create section */
	memset(&tptr, 0, sizeof(struct uci_ptr));
	tptr.p = pkg;
	tptr.section = "wlan24";
	tptr.value = "interface";
	uci_set(ctx, &tptr);

	tptr.option = "value2";
	tptr.value = "2";
	uci_set(ctx, &tptr);

	/* set list option */
	tptr.option = "dns";
	tptr.value = "8.8.8.8";
	uci_add_list(ctx, &tptr);

	/* create anonymous section */
	memset(&tptr, 0, sizeof(struct uci_ptr));
	tptr.p = pkg;
	uci_add_section(ctx, pkg, "interface", &tptr.s);

	/* set list option */
	tptr.option = "dns";
	tptr.value = "8.8.8.8";
	uci_add_list(ctx, &tptr);

	uci_commit(ctx, &ptr.p, false);
	uci_unload(ctx, pkg);
	ret = 0;
error:
	if (ctx)
		uci_free_context(ctx);
	return ret;
}
