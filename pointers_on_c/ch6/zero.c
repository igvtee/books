#define N_VALUES 5

void zero(void)
{
	float values[N_VALUES];
	float *vp;

	for (vp = &values[0]; vp < &values[N_VALUES]; )
		*vp++ = 0;
}

void zero_reverse(void)
{
	float values[N_VALUES];
	float *vp;

	for (vp = &values[N_VALUES]; vp > &values[0]; )
		*--vp = 0;
}

void zero_bad(void)
{
	float values[N_VALUES];
	float *vp;

	for (vp = &values[N_VALUES-1]; vp >= &values[0]; vp--)
		*vp = 0;
}
