#include "sort.h"

/**
 * partition - represents the partition function
 *
 * @array: represents the array to be sorted
 * @size: represents size of array to be sorted
 * @low: represents the low size
 * @high: represents the high length
 *
 * Return: the current position of type unsigned long
 */

size_t partition(int *array, ssize_t low, ssize_t high, size_t size)
{
	ssize_t i, j;
	int swap, pivot;

	pivot = array[high];
	i = low - 1;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				swap = array[i];
				array[i] = array[j];
				array[j] = swap;
				print_array(array, size);
			}
		}
	}
	if (array[high] < array[i + 1])
	{
		swap = array[i + 1];
		array[i + 1] = array[high];
		array[high] = swap;
		print_array(array, size);
	}

	return (i + 1);
}

/**
 * quicksort_recursion - represents the function to sort an array using
 *                       quick sort algorithm and the partition scheme
 * @array: represents the array to be sorted
 * @size: represents the size of array to be sorted
 * @low:  represents the low size
 * @high: represents the high size of length
 *
 * Return: nothing
 */
void quicksort_recursion(int *array, ssize_t low, ssize_t high, size_t size)
{
	ssize_t pi;

	if (low < high)
	{
		pi = partition(array, low, high, size);

		quicksort_recursion(array, low, pi - 1, size);
		quicksort_recursion(array, pi + 1, high, size);
	}
}

/**
 * quick_sort - represents the function to sort an array using quick
 *              sort algorithm and the partition scheme
 * @array: represents the array to be sorted
 * @size: represents the size of array to be sorted
 *
 * Return: nothing
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	quicksort_recursion(array, 0, size - 1, size);
}
