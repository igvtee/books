/* old style definition, but has prototype */
int olddef(float d, char i);

int main(void)
{
	float d = 10.0;
	char j = 3;

	olddef(d, j);

	/* new style definition, but no prototype */
	newdef(d, j);

	return 0;
}
