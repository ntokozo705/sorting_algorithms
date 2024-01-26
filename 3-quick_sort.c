#include "sort.h"

void swap_ints(int *a, int *b);
int lomuto_partition(int *array, size_t size, int left, int right);
void lomuto_sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

/**
 * swap_ints - Swap two integers in an array.
 * @a: First integer to swap.
 * @b: Second integer to swap.
 */

void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * lomuto_partition - Order a subset of an array of integers according to
 *                    the lomuto partition scheme (last element as pivot).
 * @array: Array of integers.
 * @size: Size of the array.
 * @left: Starting index of the subset to order.
 * @right: Ending index of the subset.
 *
 * Return: Final partition index.
 */

int lomuto_partition(int *array, size_t size, int left, int right)
{
	int *pivot, above, below;

	pivot = array + right;
	for (above = below = left; below < right; below++)
	{
		if (array[below] < *pivot)
		{
			if (above < below)
			{
				swap_ints(array + below, array + above);
				print_array(array, size);
			}
			above++;
		}
	}

	if (array[above] > *pivot)
	{
		swap_ints(array + above, pivot);
		print_array(array, size);
	}

	return (above);
}

/**
 * lomuto_sort - Implement the quicksort algorithm through recursion.
 * @array: Array of integers to sort.
 * @size: Size of the array.
 * @left: Starting index of the array partition to order.
 * @right: The ending index of the array partition to order.
 *
 * Description: Uses Lomuto partition scheme.
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
	int _part;

	if (right - left > 0)
	{
		_part = lomuto_partition(array, size, left, right);
		lomuto_sort(array, size, left, _part - 1);
		lomuto_sort(array, size, _part + 1, right);
	}
}

/**
 * quick_sort - Sort array of integers in ascending
 *     order using the quicksort algorithm.
 * @array: Array of integers.
 * @size: Size of the array.
 *
 * Description: Uses Lomuto partition scheme. Prints
 *      the array after each swap of two elements.
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
