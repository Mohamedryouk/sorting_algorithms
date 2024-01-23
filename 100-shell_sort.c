#include "sort.h"
/**
 *shell_sort - shill sort algorithm
 *@array: array to be sorted
 *@length: length of array
 */
void shell_sort(int *array, size_t size)
{
	size_t outer, inner, gap = 1;
	int insertion_value;

	while (gap <= size / 3)
	{
		gap = gap * 3 + 1;
	}
	while (gap > 0)
	{
		for (outer = gap; outer < size; outer++)
		{
			insertion_value = array[outer];
			inner = outer;

			while(inner >= gap && array[inner - gap] > insertion_value)
			{
				array[inner] = array[inner - gap];
				inner -= gap;
			}
			array[inner] = insertion_value;
		}
		print_array(array, size);
		gap = (gap - 1) / 3;
	}
}
	
