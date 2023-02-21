#include "sort.h"
void swap(listint_t **list, listint_t *iz, listint_t *der);
void swap_h(listint_t **list, listint_t *iz, listint_t *der);

/**
 * cocktail_sort_list - sort a list with cocktail sort algorithm.
 * @list: dubly linked to sort.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *current = *list, *aux = NULL, *inicio;

	if (list == NULL && *list == NULL && (*list)->next == NULL)
		return;

	while (current)
	{
		inicio = current;
		for (; current; current = current->next)
		{
			if (current->next && current->n > current->next->n)
			{
				swap(&(*list), current, current->next);
				print_list(*list);
				current = current->prev;
				if (current != NULL)
					aux = current;
			}
		}
		for (current = aux; current; current = current->prev)
		{
			if (current->prev && current->n < current->prev->n)
			{
				if (current->prev->prev != NULL)
					swap(&(*list), current, current->prev);
				else
					swap_h(&(*list), current, current->prev);
				print_list(*list);
				current = current->next;
			}
		}
		current = inicio->next;
	}
}

/**
 * swap - swap nodes.
 * @list: list.
 * @iz:	left node.
 * @der: right node.
 */
void swap(listint_t **list, listint_t *iz, listint_t *der)
{
	listint_t *temp;

	temp = iz->next;
	iz->next = der->next;
	der->next = temp;
	if (iz->next != NULL)
		iz->next->prev = iz;
	if (der->next != NULL)
		der->next->prev = der;
	temp = iz->prev;
	iz->prev = der->prev;
	der->prev = temp;
	if (iz->prev != NULL)
		iz->prev->next = iz;
	if (der->prev == NULL)
		(*list) = der;
	der->prev->next = der;
}

/**
 * swap_h - swap nodes.
 * @list: list.
 * @iz:	left node.
 * @der: right node.
 */
void swap_h(listint_t **list, listint_t *iz, listint_t *der)
{
	iz->prev = der->prev;
	der->prev = iz;
	der->next = iz->next;
	iz->next = der;
	if (der->next != NULL)
		der->next->prev = der;
	if (iz->prev == NULL)
		*list = iz;
	else
		iz->prev->next = iz;
}
