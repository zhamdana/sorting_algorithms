#include "sort.h"

/**
 * insertion_sort_list - sort a linked list with insertion sort algorithm.
 * @list: dubly linked list.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current = NULL;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;
	while (current != NULL)
	{
		while (current->prev && current->n < current->prev->n)
		{
			current->prev->next = current->next;
			if (current->next != NULL)
				current->next->prev = current->prev;
			current->next = current->prev;
			current->prev = current->prev->prev;
			current->next->prev = current;
			if (current->prev == NULL)
				*list = current;
			else
				current->prev->next = current;
			print_list(*list);
		}
		current = current->next;
	}
}
