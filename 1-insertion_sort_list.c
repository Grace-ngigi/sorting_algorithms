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
	key = *list;
	while (key != NULL)
	{
		while (key->next != NULL && key->n > key->next->n)
		{
			pred = key->next;
			key->next = pred->next;
			pred->prev = key->prev;
			if (key->prev != NULL)
				key->prev->next = pred;
			if (pred->next != NULL)
				pred->next->prev = key;
			key->prev = pred;
			pred->next = key;

			if (pred->prev != NULL)
				key = pred->prev;
			else
				*list = pred;
			print_list(*list);
		}
		key = key->next;
	}
}
