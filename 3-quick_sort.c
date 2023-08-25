#include "sort.h"

void swap_nbrs(int *x, int *y);
int lmt_partition(int *array, size_t size, int left_s, int right_s);
void lmt_sort(int *array, size_t size, int left_s, int right_s);
void quick_sort(int *array, size_t size);

/**
 * swap_nbrs - swap 2 numbers in  an array.
 * @a:   first number to swap.
 * @b:   second number to swap.
 */
void swap_nbrs(int *x, int *y)
{
	int temp;

	tmp = *x;
	*x = *y;
	*y = temp;
}

/**
 * lmt_partition - Order a subset of an array of numbers according to
 * @array:   array of numbers.
 * @size:   size of   array.
 * @left_s:   starting index of   subset to order.
 * @right_s:   ending index of   subset to order.
 *
 * Return:   final partition index.
 */
int lmt_partition(int *array, size_t size, int left_s, int right_s)
{
	int *pivot_s, above_s, below_s;

	pivot_s = array + right_s;
	for (above_s = below_s = left_s; below_s < right_s; below_s++)
	{
		if (array[below_s] < * pivot_s)
		{
			if (above_s < below_s)
			{
				swap_nbrs(array + below_s, array + above_s);
				print_array(array, size);
			}
			above_s++;
		}
	}

	if (array[above_s] > * pivot _s)
	{
		swap_nbrs(array + above_s,  pivot _s);
		print_array(array, size);
	}

	return (above_s);
}

/**
 * lmt_sort - Implement   quicksort algorithm through recursion.
 * @array: An array of numbers to sort.
 * @size:   size of   array.
 * @left_s:   starting index of   array partition to order.
 * @right_s:   ending index of   array partition to order.
 *
 * Description: Uses   Lmt partition scheme.
 */
void lmt_sort(int *array, size_t size, int left_s, int right_s)
{
	int part;

	if (right_s - left_s > 0)
	{
		part = lmt_partition(array, size, left_s, right_s);
		lmt_sort(array, size, left_s, part - 1);
		lmt_sort(array, size, part + 1, right_s);
	}
}

/**
 * quick_sort - Sort an array of numbers in ascending
 * @array: An array of numbers.
 * @size:   size of   array.
 *
 * Description: Uses   Lmt partition scheme. Prints
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lmt_sort(array, size, 0, size - 1);
}

