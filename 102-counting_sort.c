#include "sort.h"

/**
 * get_maxim - Get the maximum value in an array of integers.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Return: The maximimum integer in the array.
 */
int get_maxim(int *array, int size)
{
	int maxim, x;

	for (maxim = array[0], x = 1; x < size; x++)
	{
		if (array[x] > maxim)
			maxim = array[x];
	}

	return (maxim);
}

/**
 * counting_sort - Sort an array of integers in ascending order
 *                 using the counting sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the counting array after setting it up.
 */
void counting_sort(int *array, size_t size)
{
	int *cont, *sort, maxim, x;

	if (array == NULL || size < 2)
		return;

	sort = malloc(sizeof(int) * size);
	if (sort == NULL)
		return;
	maxim = get_maxim(array, size);
	cont = malloc(sizeof(int) * (maxim + 1));
	if (cont == NULL)
	{
		free(sort);
		return;
	}

	for (x = 0; x < (maxim + 1); x++)
		cont[x] = 0;
	for (x = 0; x < (int)size; x++)
		cont[array[x]] += 1;
	for (x = 0; x < (maxim + 1); x++)
		cont[x] += cont[x - 1];
	print_array(cont, maxim + 1);

	for (x = 0; x < (int)size; x++)
	{
		sort[cont[array[x]] - 1] = array[x];
		cont[array[x]] -= 1;
	}

	for (x = 0; x < (int)size; x++)
		array[x] = sort[x];

	free(sort);
	free(cont);
}

