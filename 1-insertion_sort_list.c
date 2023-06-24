#include "sort.h"
/**
 * insertion_sort_list - sorts a list in ascending order
 * @list: double pointer to the linked list
 * Return: nothing
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *key, *pred;
	
	if (list == NULL || (*list) == NULL || (*list)->next == NULL)
		return;
	key = (*list)->next;
	while (key != NULL)
	{
		pred = key->prev;
		while (pred != NULL && pred->n > key->n)
		{
			pred->next = key->next;
			if (key->next != NULL)
				key->next->prev = pred;
			key->next = pred;
			key->prev = pred->prev;
			if (pred->prev != NULL)
				pred->prev->next = key;
			else
				*list = key;
			pred->prev = key;
			pred = key->prev;
		}
		print_list(*list);
		key = key->next;
	}
}
