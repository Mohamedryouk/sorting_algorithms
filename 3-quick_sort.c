#include "sort.h"
/**
 *swap - swaps two elements
 *@x: element one
 *@y: element two
 */
void swap(int *x, int *y)
{
  int temp;
  temp = *x;
  *x = *y;
  *y = temp;
}
/**
 * lomuto_partition- lomuto way
 *@array: array of element
 *@size: size of array
 *@low: low value of pivot
 *@high: high value of index of pivot
 *Return: returns the last pivot value
 */
int lomuto_partition(int *array, size_t size, int low, int high)
{
  int *pivot_value, j/*below*/, i/*above*/;

  pivot_value = array + high;
  for (i = j = low; j < high; j++)
  {
    if (array[j] < *pivot_value)
    {
      if (i < j)
      {
        swap(array + j, array + i);
        print_array(array, size);
      }
      i++;
    }
  }
  if (array[i] > *pivot_value)
  {
    swap(array + i, pivot_value);
    print_array(array, size);
  }
  return i;
}
/**
 *quick_sort_recursion - recursion step after pivot returned
 *@array: array to be sorted
 *@size: size of the array
 *@low: low value of pivot or index
 *@high: high value of pivot or index
 */
void quick_sort_recursion(int *array, size_t size, int low, int high)
{
  int pivot_index;

  if (high - low > 0)
  {
    pivot_index = lomuto_partition(array, size, low, high);
    quick_sort_recursion(array, size, low, pivot_index - 1);
    quick_sort_recursion(array, size, pivot_index + 1, high);
  }
}
/**
 *quick_sort - quick sort algorithm function
 *@array: array to be sorted
 *@size: size of the array
 */
void quick_sort(int *array, size_t size)
{
  if (array == NULL || size < 2)
      return;
  quick_sort_recursion(array, size, 0, size -1);
}
