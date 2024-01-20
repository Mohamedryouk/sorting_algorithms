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
	int swapped;
	size_t i, j, k;

	for (i = 0; i < size - 1; i++)
	{
		swapped = 0;

		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(&array[j], &array[j + 1]);
				swapped = 1;
			}
		}


		for (k = 0; k < size; k++)
		{
			printf("%d", array[k]);
			if (k < size - 1)
			{
				printf(", ");
			}
		}
		printf("\n");

		if (swapped == 0)
		{
			break;
		}
	}
}
