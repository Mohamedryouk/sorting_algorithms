#include "sort.h"
/**
 * swap_heaps - swaps between two nodes
 * @a: first node
 * @b: second node
 */
void swap_heaps(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
/**
 * heapify - creates a heap
 * @array: array to be sorted
 * @size: size of the array
 * @parent: parent of the nodes
 * @root: root of the node
 */
void heapify(int *array, size_t size, size_t parent, size_t root)
{
	size_t largest = root;
	size_t left = 2 * root + 1;
	size_t right = 2 * root + 2;

	if (left < parent && array[left] > array[largest])
		largest = left;
	if (right < parent && array[right] > array[largest])
		largest = right;
	if (largest != root)
	{
		swap_heaps(array + root, array + largest);
		print_array(array, size);
		heapify(array, size, parent, largest);
	}
}
/**
 * heap_sort - heap sort algorithm function
 * @array: array to be sorted
 * @size: size of the array
 */
void heap_sort(int *array, size_t size)
{
	int i;

	if (array == NULL || size < 2)
		return;

	for (i = (size / 2) - 1; i >= 0; i--)
	{
		heapify(array, size, size, i);
	}
	for (i = size - 1; i >= 0; i--)
	{
		swap_heaps(array, array + i);
		print_array(array, size);
		heapify(array, size, i, 0);
	}
}
