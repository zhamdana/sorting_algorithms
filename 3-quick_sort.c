#include "sort.h"

/**
 * quick_sort - quick sort function
 * @array: array to sort
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quick_sort_recursion(array, size, 0, size - 1);
}

/**
 * quick_sort_recursion - rectursion to sort the array
 * @array: array to sort
 * @size: size of the array
 * @left: left side of the array
 * @right: right side of the array
 */
void quick_sort_recursion(int *array, size_t size, int left, int right)
{
	int pivot;

	if (left < right)
	{
		pivot = quick_sort_split(array, size, left, right);

		quick_sort_recursion(array, size, left, pivot - 1);
		quick_sort_recursion(array, size, pivot + 1, right);
	}
}

/**
 * quick_sort_split - split the array on each sides
 * @array: array to sort
 * @size: size of the array
 * @left: left side of the array
 * @right: right side of the array
 * Return: pivot indev plus one
 */
int quick_sort_split(int *array, size_t size, int left, int right)
{
	int j;
	int i = left - 1;
	int pivot = array[right];

	for (j = left; j <= right - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i += 1;
			swap_elements(array, size, &array[i], &array[j]);
		}
	}
	swap_elements(array, size, &array[i + 1], &array[right]);

	return (i + 1);
}

/**
 * swap_elements - swap two elements
 * @array: array to sort
 * @size: size of the array
 * @a: element to swap
 * @b: element to swap
 */
void swap_elements(int *array, size_t size, int *a, int *b)
{
	int aux;

	if (a != b)
	{
		aux = *a;
		*a = *b;
		*b = aux;
		print_array(array, size);
	}
}
