#include "sort.h"
/**
 * counting_sort - counting sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 */
void counting_sort(int *array, size_t size)
{
	int i, *count, *sorted, k;

	if (array == NULL || size < 2)
		return;
	sorted = malloc(sizeof(int) * size);
	if (sorted == NULL)
		return;
	k = find_max(array, size);
	count = malloc(sizeof(int) * (k + 1));
	if (count == NULL)
	{
		free(sorted);
		return;
	}
	for (i = 0; i <= k; i++)
	{
		count[i] = 0;
	}
	for (i = 0; i < (int)size; i++)
	{
		count[array[i]] += 1;
	}
	for (i = 0; i < (k + 1); i++)
	{
		count[i] += count[i - 1];
	}
	print_array(count, k + 1);
	for (i = 0; i < (int)size; i++)
	{
		sorted[count[array[i]] - 1] = array[i];
		count[array[i]] -= 1;
	}
	for (i = 0; i < (int)size; i++)
	{
		array[i] = sorted[i];
	}
	free(sorted);
	free(count);
}
/**
 * find_max - find max num
 * @array: array
 * @size: size of the array
 * Return: return the max
 */
int find_max(int *array, size_t size)
{
	int k = array[0];
	size_t i;

	for (i = 1; i < size; i++)
	{
		if (array[i] > k)
		{
			k = array[i];
		}
	}
	return (k);
}
