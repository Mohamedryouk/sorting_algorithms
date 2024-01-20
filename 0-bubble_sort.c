#include <stdio.h>
#include <stdbool.h>
#include "sort.h"
/**
 *swap - swap function to swap between two addresses
 *@xp: pointer integer to be sawped
 *@yp: pointer integer
 */
void swap(int *xp, int *yp)
{
	int temp;

	temp = *xp;
	*xp = *yp;
	*yp = temp;
}
/**
 *bubble_sort- bubble sort algorithem function
 *@array: array of numbers to be sorted.
 *@size: size of array to be sorted
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, len = size;
	bool sawpped = false;

	if (array == NULL || size < 2)
		return;

	while (sawpped == false)
	{
		sawpped = true;
		for (i = 0; i < len - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				swap(array + i, array + i + 1);
				print_array(array, size);
				sawpped = false;
			}
		}
		len--;
	}
}
