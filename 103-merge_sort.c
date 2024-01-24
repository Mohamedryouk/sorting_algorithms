#include "sort.h"
/**
 * print_subarray
 * @label: label of the array
 * @array: the array
 * @size: length or size of the array
 */
void print_subarray(const char *label, const int *array, size_t size)
{
	printf("[%s]: ", label);
	print_array(array, size);
}
/**
 * merge - merge the arrays
 * @array: the array
 * @left: left side
 * @L_size: left length or size
 * @right: right side
 * @R_size: right lenght or size
 */
void merge(int *array, int *left, size_t L_size, int *right, size_t R_size)
{
	size_t i = 0, j = 0, k = 0;

	printf("Merging...\n");
	print_subarray("left", left, L_size);
	print_subarray("right", right, R_size);

	while (i < L_size && j < R_size)
	{
		if (left[i] <= right[j])
		{
			array[k] = left[i];
			i++;
		}
		else
		{
			array[k] = right[j];
			j++;
		}
		k++;
	}

	while (i < L_size)
	{
		array[k] = left[i];
		i++;
		k++;
	}

	while (j < R_size)
	{
		array[k] = right[j];
		j++;
		k++;
	}
	print_subarray("Done", array, L_size + R_size);
}
/**
 * merge_sort - merge sort algorithm using top down
 * @array: array to be sorted
 * @size: size of the array to be sorted
 */
void merge_sort(int *array, size_t size)
{
	size_t i;

	if (size > 1)
	{
		size_t middle = size / 2;
		size_t L_size = middle;
		size_t R_size = size - middle;

		int *left = malloc(L_size * sizeof(int));
		int *right = malloc(R_size * sizeof(int));

		for (i = 0; i < L_size; i++)
		{
			left[i] = array[i];
		}

		for (i = 0; i < R_size; i++)
		{
			right[i] = array[middle + i];
		}

		merge_sort(left, L_size);
		merge_sort(right, R_size);
		merge(array, left, L_size, right, R_size);

		free(left);
		free(right);
		}
}
