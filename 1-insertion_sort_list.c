#include "sort.h"
/**
 * insertion_sort_list - function to sort
 *@list: list to be sorted
 *
 */
void insertion_sort_list(listint_t **list)
{
    listint_t *iterate, *insert, *temp;

    if (list == NULL || (*list) == NULL || (*list)->next == NULL)
        return;

    for (iterate = (*list)->next; iterate != NULL; iterate = temp)
    {
        temp = iterate->next;
        insert = iterate->prev;
        while (insert != NULL && iterate->n < insert->n)
        {
            swap_nodes(list, &insert, iterate);
            print_list((const listint_t *)*list);
        }
        
    }
    
}
void swap_nodes(listint_t **h, listint_t **data1, listint_t *data2)
{
    (*data1)->next = data2->next;
    if (data2->next != NULL)
        data2->next->prev = *data1;

    data2->prev = (*data1)->prev;
    data2->next = *data1;
    if ((*data1)->prev != NULL)
        (*data1)->prev->next = data2;
    else
        *h = data2;
    (*data1)->prev = data2;
    *data1 = data2->prev;
}