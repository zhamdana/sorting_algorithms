#include "sort.h"

/**
 * bubble_sort - sort an array with bubble sort algorithm
 * @array: array to sort.
 * @size: size of the array.
 */
void bubble_sort(int *array, size_t size)
{
	unsigned int finish = 0, i, aux;

	if (array == NULL || size < 2)
		return;

	while (finish == 0)
	{
		finish = 1;
		for (i = 0; i < size - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				aux = array[i];
				array[i] = array[i + 1];
				array[i + 1] = aux;
				print_array(array, size);
				finish = 0;
			}
		}
	}
}
