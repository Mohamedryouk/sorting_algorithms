#include "sort.h"
void print_subarray(const char *label, const int *array, size_t size)
{
    printf("[%s]: ", label);
    print_array(array, size);
}

void merge(int *array, int *left, size_t left_size, int *right, size_t right_size)
{
	size_t i = 0, j = 0, k = 0;

	printf("Merging...\n");
	print_subarray("left", left, left_size);
	print_subarray("right", right, right_size);

	while (i < left_size && j < right_size)
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

	while (i < left_size)
	{
		array[k] = left[i];
		i++;
		k++;
	}

	while (j < right_size)
	{
		array[k] = right[j];
		j++;
		k++;
	}
	print_subarray("Done", array, left_size + right_size);
}

void merge_sort(int *array, size_t size)
{
	size_t i;

	if (size > 1)
	{
		size_t middle = size / 2;
		size_t left_size = middle;
		size_t right_size = size - middle;

		int *left = malloc(left_size * sizeof(int));
		int *right = malloc(right_size * sizeof(int));

        	for (i = 0; i < left_size; i++)
		{
			left[i] = array[i];
		}

		for (i = 0; i < right_size; i++)
		{
			right[i] = array[middle + i];
		}

		merge_sort(left, left_size);
		merge_sort(right, right_size);
		merge(array, left, left_size, right, right_size);

		free(left);
		free(right);
		}
}