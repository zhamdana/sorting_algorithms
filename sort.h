#ifndef SORT_H
#define SORT_H

/** INCLUDES **/
#include <stdlib.h>
#include <stdio.h>

/** STRUCT **/

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

/** PROTOTYPES **/
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void bubble_sort(int *array, size_t size);
void selection_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);

void counting_sort(int *array, size_t size);
	int max_int(int *array, size_t size);

void quick_sort(int *array, size_t size);
	void quick_sort_recursion(int *array, size_t size, int left, int right);
	int quick_sort_split(int *array, size_t size, int left, int right);
	void swap_elements(int *array, size_t size, int *a, int *b);

#endif
