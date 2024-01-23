#include "sort.h"
/**
 *cocktail_sort_list- algorithm function
 *@list: list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *tail, *ahead;
	bool isswap = false;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (tail = *list; tail->next != NULL;)
		tail = tail->next;

	while (isswap == false)
	{
		isswap = true;
		for (ahead = *list; ahead != tail; ahead = ahead->next)
		{
			if (ahead->n > ahead->next->n)
			{
				swap_node_ahead(list, &tail, &ahead);
				print_list((const listint_t *)*list);
				isswap = false;
			}
		}
		for (ahead = tail; ahead != *list; ahead = ahead->prev)
		{
			if (ahead->n < ahead->prev->n)
			{
				swap_node_behind(list, &tail, &ahead);
				print_list((const listint_t *)*list);
				isswap = false;
			}
		}
	}
}
/**
 * swap_node_ahead- swap node ahead
 * @list: list
 * @tail: tail of the node
 * @Head: Head
 */
void swap_node_ahead(listint_t **list, listint_t **tail, listint_t **Head)
{
	listint_t *tmp = (*Head)->next;

	if ((*Head)->prev != NULL)
		(*Head)->prev->next = tmp;
	else
		*list = tmp;
	tmp->prev = (*Head)->prev;
	(*Head)->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = *Head;
	else
		*tail = *Head;
	(*Head)->prev = tmp;
	tmp->next = *Head;
	*Head = tmp;
}
/**
 *swap_node_behind - swap behind
 *@list: list
 *@tail: tail of the list
 *@Head: shaler
 */
void swap_node_behind(listint_t **list, listint_t **tail, listint_t **Head)
{
	listint_t *tmp = (*Head)->prev;

	if ((*Head)->next != NULL)
		(*Head)->next->prev = tmp;
	else
		*tail = tmp;
	tmp->next = (*Head)->next;
	(*Head)->prev = tmp->prev;
	if (tmp->prev != NULL)
		tmp->prev->next = *Head;
	else
		*list = *Head;
	(*Head)->next = tmp;
	tmp->prev = *Head;
	*Head = tmp;
}
