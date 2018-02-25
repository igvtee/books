/* sum to the first NaN in the vector.
 * sets error to zero on a clean summation, 1 if a NaN is hit. 
 */
double sum_to_first_nan(double *vector, int vector_size,
		double *vector2, int vector2_size, int *error)
{
	double sum = 0;
	*error = 1;

	for (int i=0; i < vector_size; i++) {
		if (isnan(vector[i]))
			goto outro;
		sum += vector[i];
	}

	for (int i=0; i < vector2_size; i++) {
		if (isnan(vector2[i]))
			goto outro;
		sum += vector2[i];
	}
	*error = 0;

outro:
	printf("The sum until the first NaN (if any) was %g\n", sum);
	free(vector);
	free(vector2);
	return sum;
}
