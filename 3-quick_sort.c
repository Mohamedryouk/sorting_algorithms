#include "sort.h"
void swap(int *x, int *y)
{
  int temp;
  temp = *x;
  *x = *y;
  *y = temp;
}
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
void quick_sort(int *array, size_t size)
{
  if (array == NULL || size < 2)
      return;
  quick_sort_recursion(array, size, 0, size -1);
}