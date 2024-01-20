#include "sort.h"
/**
 *print_array - to print array after every swap
 *@array: array to be printed
 *@n: n number of elements
 */
void print_array(int *array, size_t n)
{
	size_t i;

	printf(" ");
	for (i = 0; i < n; i++)
	{
		printf("%d", array[i]);
		if (i < n - 1)
		{
			printf(", ");
		}
	}
	printf(" \n");
}
