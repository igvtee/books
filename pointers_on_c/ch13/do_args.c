#include <stdio.h>

char ** do_args(int argc, char **argv, char *control,
		void (*do_arg)(int ch, char *value),
		void (*illegal_arg)(int ch))
{
	char *ctr;

	printf("control: %s\n", control);

	argv++;
	while (*argv != NULL && *(*argv)++ == '-') {
		while (**argv != '\0') {
			ctr = control;
			while (*ctr != '\0') {
				if ((*ctr != '+') && (**argv == *ctr)) {
					if (*(ctr + 1) == '+') {
						if (*((*argv) + 1) != '\0') {
							(*argv)++;
							do_arg(*ctr, *argv);
							goto next_arg;
						} else {
							if (*(argv + 1) == NULL)
								goto err;
							else {
								do_arg(*ctr, *++argv);
								goto next_arg;
							}
						}
					} else {
						do_arg(*ctr, NULL);
						break;
					}
				}
				ctr++;
			}
			if (*ctr == '\0') {
err:
				illegal_arg(**argv);
				break;
			}
			(*argv)++;
		}
next_arg:
		argv++;
	}

	return argv;
};

void print_cmd(char **argv)
{
	printf("command: ");
	while (*argv) {
		printf("%s ", *argv);
		argv++;
	}
	putchar('\n');
}

void print_arg(int ch, char *value)
{
	printf("do_arg: %c, %s\n", ch, value);
}

void print_illegal(int ch)
{
	printf("illegal_arg: %c\n", ch);
}

int main(void)
{
	char **ret;
	char *argv1[] = {"prog", "-x", "-y", "z", NULL};
	char *argv2[] = {"prog", "-x", "-y", "-z", NULL};
	char *argv3[] = {"prog", "-abcd", "-ef", "ghi", "jkl",  NULL};
	char *argv4[] = {"prog", "-a", "b", "-c", "-d", "-e", "-f",  NULL};

	print_cmd(argv1);
	ret = do_args(sizeof(argv1)/sizeof(argv1[0]),
			argv1, "x", print_arg, print_illegal);
	if (ret == &argv1[3])
		printf("ret: &argv[3]\n");
	putchar('\n');

	print_cmd(argv2);
	ret = do_args(sizeof(argv2)/sizeof(argv2[0]),
			argv2, "x+y+z+", print_arg, print_illegal);
	if (ret == &argv2[4])
		printf("ret: &argv[4]\n");
	putchar('\n');

	print_cmd(argv3);
	ret = do_args(sizeof(argv3)/sizeof(argv3[0]),
			argv3, "ab+cdef+g", print_arg, print_illegal);
	if (ret == &argv3[4])
		printf("ret: &argv[4]\n");
	putchar('\n');


	print_cmd(argv4);
	ret = do_args(sizeof(argv4)/sizeof(argv4[0]),
			argv4, "abcdef", print_arg, print_illegal);
	if (ret == &argv4[2])
		printf("ret: &argv[2]\n");
	putchar('\n');

	return 0;
}
