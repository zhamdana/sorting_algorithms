#include "sort.h"
/**
 * max_int - find the max integer on an array
 * @array: array to find the max integer.
 * @size: size of the array
 *
 * Return: max integer
 */
int max_int(int *array, size_t size)
{
	int max = array[0];
	int i;

	for (i = 1; i < (int)size; i++)
	{
		if (array[i] > max)
		{
			max = array[i];
		}
	}
	return (max);
}

/**
 * counting_sort - sort an array with counting algorithm
 * @array: array to sort
 * @size: size of the array
 */
void counting_sort(int *array, size_t size)
{
	int *count, *aux, max, i;

	if (array == NULL || size < 2)
		return;

	max = max_int(array, size);

	count = malloc(sizeof(int) * (max + 1));
	if (!count)
		return;

	aux = malloc(sizeof(int) * (size));
	if (!aux)
	{
		free(count);
		return;
	}
	for (i = 0; i < (int)size; i++)
		count[i] = 0;

	for (i = 0; i < (int)size; i++)
	{
		count[array[i]] += 1;
	}
	for (i = 0; i < max + 1; i++)
		count[i] += count[i - 1];

	print_array(count, max + 1);

	for (i = 0; i < (int)size; i++)
	{
		aux[count[array[i]] - 1] = array[i];
		count[array[i]]--;
	}
	for (i = 0; i < (int)size; i++)
		array[i] = aux[i];

	free(count);
	free(aux);
}
