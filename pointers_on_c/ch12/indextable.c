#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct chnode {
	char ch;
	struct chnode *nextch;
	struct wordnode *wlist;
};

struct wordnode {
	char *word;
	struct wordnode *nextword;
};

int init_ch(struct chnode **list)
{
	int ret = 1;
	char ch = 'a';
	struct chnode *this = NULL, *new;

	while (ch <= 'z') {
		new = (struct chnode *)malloc(sizeof(*new));
		if (!new)
			goto err;
		new->ch = ch;
		new->nextch = NULL;
		new->wlist = NULL;
		if (this)
			this->nextch = new;
		else
			*list = new;
		this = new;
		ch++;
	}

	ret = 0;
	return ret;

err:
	this = *list;
	while (this) {
		new = this;
		this = this->nextch;
		free(new);
	}

	return ret;
}

int insert_word(struct chnode **list, char *word)
{
	int ret = 1, cmpret;
	struct chnode *root;
	struct wordnode *this, *next;
	struct wordnode *newnode;

	if (!('a' <= *word && *word <= 'z'))
		goto err;

	root = *list;
	while (root) {
		if (root->ch == *word)
			break;
		root = root->nextch;
	}
	if (!root)
		goto err;

	this = NULL;
	next = root->wlist;
	while (next) {
		cmpret = strcmp(next->word, word);
		if (cmpret == 0)
			goto err;
		else if (cmpret > 0)
			break;
		else {
			this = next;
			next = next->nextword;
		}
	}

	newnode = (struct wordnode *)malloc(sizeof(*newnode));
	if (!newnode)
		goto err;
	newnode->word = strdup(word);
	if (!newnode->word) {
		free(newnode);
		goto err;
	}

	newnode->nextword = next;
	if (this)
		this->nextword = newnode;
	else
		root->wlist = newnode;

	ret = 0;
err:
	return ret;
}

void print_table(struct chnode *root)
{
	struct wordnode *node;

	while (root) {
		printf("%c: ", root->ch);
		node = root->wlist;
		while (node) {
			printf("%s ", node->word);
			node = node->nextword;
		}
		putchar('\n');
		root = root->nextch;
	}
}

void free_table(struct chnode *root)
{
	struct wordnode *node;
	void *freep;

	while (root) {
		node = root->wlist;
		while (node) {
			if (node->word)
				free(node->word);
			freep = node;
			node = node->nextword;
			free(freep);
		}
		freep = root;
		root = root->nextch;
		free(freep);
	}
}

int main(void)
{
	struct chnode *root;
	int ret = 1;

	ret = init_ch(&root);
	if (ret)
		goto err;

	insert_word(&root, "a");
	insert_word(&root, "an");
	insert_word(&root, "be");
	insert_word(&root, "bag");
	print_table(root);
	free_table(root);

	ret = 0;
err:
	return ret;
}
