struct node *p, *start, *tmp;
for (p = start; p ; p = tmp)
{
	tmp = p->next;
	free(p);
}
