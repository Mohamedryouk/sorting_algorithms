#include "sort.h"
/**
 * insertion_sort_list - function to sort
 *@list: list to be sorted
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current;

	if (list == NULL || (*list) == NULL || (*list)->next == NULL)
	{
		return;
	}
	current = (*list)->next;
	while (current != NULL)
	{
		listint_t *prev = current->prev;
		listint_t *temp = current;

		while (prev != NULL && prev->n > current->n)
		{
			swap_nodes(list, prev, current);
			print_list(*list);
			prev = temp->prev;
		}
		current = current->next;
	}
}
/**
 * swap_nodes - swap nodes with data
 * @list: header of the node
 * @node1: data of node one
 * @node2: data of node two
 */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
	if (node1->prev != NULL)
	{
		node1->prev->next = node2;
	}
	else
	{
		*list = node2;
	}
	if (node2->next != NULL)
	{
		node2->next->prev = node1;
	}
	node1->next = node2->next;
	node2->prev = node1->prev;
	node1->prev = node2;
	node2->next = node1;
}
