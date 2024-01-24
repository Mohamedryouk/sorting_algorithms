#ifndef __SORT__
#define __SORT__
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
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
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2);
void print_array(const int *array, size_t size);
void shell_sort(int *array, size_t length);
void swap(int *xp, int *yp);
void bubble_sort(int *array, size_t size);
void print_list(const listint_t *list);
void insertion_sort_list(listint_t **list);
void swap_indx(int *a, int *b);
void swap(int *x, int *y);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
int lomuto_partition(int *array, size_t size, int low, int high);
void quick_sort_recursion(int *array, size_t size, int low, int high);
void cocktail_sort_list(listint_t **list);
void swap_node_behind(listint_t **list, listint_t **tail, listint_t **Head);
void swap_node_ahead(listint_t **list, listint_t **tail, listint_t **Head);
void counting_sort(int *array, size_t size);
int find_max(int *array, size_t size);
void print_counting_array(int *array, size_t size);
void print_subarray(const char *label, const int *array, size_t size);
void merge(int *array, int *left, size_t L_size, int *right, size_t R_size);
void merge_sort(int *array, size_t size);

#endif