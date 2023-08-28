#include <stdio.h>
#include "sort.h"

/* Function to compare two elements */
void compare_and_swap(int *array, size_t low, size_t high, int dir)
{
	if ((array[low] > array[high] && dir == 1) || (array[low] < array[high] && dir == 0))
	{
		int temp = array[low];

		array[low] = array[high];
		array[high] = temp;
	}
}

/* Function to recursively sort a bitonic sequence in given direction */
void bitonic_merge(int *array, size_t low, size_t cnt, int dir)
{
	if (cnt > 1)
	{
		size_t k = cnt / 2;

		for (size_t i = low; i < low + k; i++)
		{
			compare_and_swap(array, i, i + k, dir);
		}

		bitonic_merge(array, low, k, dir);
		bitonic_merge(array, low + k, k, dir);
	}
}

/* Function to recursively sort the entire array */
void bitonic_sort_recursive(int *array, size_t low, size_t cnt, int dir)
{
	if (cnt > 1)
	{
		size_t k = cnt / 2;

		bitonic_sort_recursive(array, low, k, 1);
		bitonic_sort_recursive(array, low + k, k, 0);
		bitonic_merge(array, low, cnt, dir);
	}
}

/* Public function to perform bitonic sort */
void bitonic_sort(int *array, size_t size)
{
	bitonic_sort_recursive(array, 0, size, 1);
}
