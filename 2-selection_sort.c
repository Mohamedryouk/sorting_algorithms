#include "sort.h"
/**
 * selection_sort - algorithm to sort by selection
 * @array: array that needs sorting
 * @size: size of the array
 */
void selection_sort(int *array, size_t size)
{
  size_t i, j;
  size_t min_idx;

  if (array == NULL || size < 2)
    return;
  for (i = 0; i < size - 1; i++)
  {
    min_idx = i;
    for (j = i + 1; j < size; j++)
    {
      min_idx = (array[j] < array[min_idx]) ? j : min_idx;
    }
      if (i != min_idx)
      {
        swap_indx(&array[min_idx], &array[i]);
        print_array(array, size);
      }
  }
}
/**
 * swap_indx - swap betweem two indexs
 * @a: int number 1
 * @b: int number 2
 */
void swap_indx(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
