#ifndef __SORT__
#define __SORT__
#include <stdio.h>
#include <stdbool.h>
/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
    const int n;
    struct listint_s *prev;
    struct listint_s *next;
} listint_t;
void swap_nodes(listint_t **h, listint_t **data1, listint_t *data2);
void print_array(const int *array, size_t size);
void swap(int *xp, int *yp);
void bubble_sort(int *array, size_t size);
void print_list(const listint_t *list);
void insertion_sort_list(listint_t **list);
void swap_indx(int *a, int *b);
void selection_sort(int *array, size_t size);
#endif