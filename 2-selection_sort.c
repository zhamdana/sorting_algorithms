#include "sort.h"
/**
 * selection_sort - sort an array with selection sort algorithm
 * @array: array to sort.
 * @size: size of the array.
 */
void selection_sort(int *array, size_t size)
{
	unsigned int current, pointer;
	int min, result, aux;

	if (array == NULL || size < 2)
		return;

	for (current = 0; current < size - 1; current++)
	{
		result = 1;
		for (pointer = current; pointer < size; pointer++)
		{
			if (pointer == current)
				min = current;
			else
			{
				if (array[pointer] < array[min])
				{
					min = pointer;
					result = 0;
				}
			}
		}
		if (result == 0)
		{
			aux = array[min];
			array[min] = array[current];
			array[current] = aux;

			print_array(array, size);
		}
	}
}
