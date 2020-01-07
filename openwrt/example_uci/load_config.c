#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <uci.h>

#define CONFIG_DIR "./config"

int main(void)
{
	struct uci_context *ctx;
	struct uci_package *pkg;
	struct uci_element *e;
	struct uci_section *s;
	struct uci_option *o;
	const char *value;
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

	/* string option */
	uci_foreach_element(&pkg->sections, e) {
		s = uci_to_section(e);
		printf("section:'%s %s'\n", s->type, s->e.name);
		if ((value = uci_lookup_option_string(ctx, s, "ipaddr"))) {
			printf("\tipaddr:'%s'\n", value);
		}
	}

	/* list option */
	uci_foreach_element(&pkg->sections, e) {
		s = uci_to_section(e);
		printf("section:'%s'\n", s->e.name);
		if ((o = uci_lookup_option(ctx, s, "dns"))) {
			if (UCI_TYPE_LIST == o->type) {
				struct uci_element *oe;
				printf("\tdns:");
				uci_foreach_element(&o->v.list, oe)
				{
					printf("'%s'", oe->name);
				}
			}
		}
		putchar('\n');
	}


	uci_unload(ctx, pkg);
	ret = 0;
error:
	if (ctx)
		uci_free_context(ctx);
	return ret;
}
