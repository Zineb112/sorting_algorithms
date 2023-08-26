#include "sort.h"

void swap_nbrs(int *a, int *b);
void max_heap(int *aray, size_t size, size_t base, size_t root);
void heap_sort(int *array, size_t size);

/**
 * swap_nbrs - Swap two integers in an array.
 * @x: first integer to swap.
 * @y: second integer to swap.
 */
void swap_nbrs(int *x, int *y)
{
	int temp;

	temp = *x;
	*x = *y;
	*y = temp;
}

/**
 * max_heap - Turn binary tree into a complete binary heap.
 * @aray: array of integers representing a binary tree.
 * @size:  size of the array/tree.
 * @base: index of the base row of the tree.
 * @root: The root node of the binary tree.
 */
void max_heap(int *aray, size_t size, size_t base, size_t root)
{
	size_t left, right, large;

	left = 2 * root + 1;
	right = 2 * root + 2;
	large = root;

	if (left < base && aray[left] > aray[large])
		large = left;
	if (right < base && aray[right] > aray[large])
		large = right;

	if (large != root)
	{
		swap_nbrs(aray + root, aray + large);
		print_array(aray, size);
		max_heap(aray, size, base, large);
	}
}

/**
 * heap_sort - Sort an array of integers in ascending
 *             order using the heap sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Implements the sift-down heap sort
*/
void heap_sort(int *array, size_t size)
{
	int x;

	if (array == NULL || size < 2)
		return;

	for (x = (size / 2) - 1; x >= 0; x--)
		max_heap(array, size, size, x);

	for (x = size - 1; x > 0; x--)
	{
		swap_nbrs(array, array + x);
		print_array(array, size);
		max_heap(array, size, x, 0);
	}
}

