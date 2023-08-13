#include "sort.h"

/**
 * selection_sort - Sorts an array of integers in ascending order using the
 * Selection sort algorithm.
 * @array: Pointer to the array.
 * @size: The size of the array.
 *
 * This function sorts the array of integers in ascending order using the
 * Selection sort algorithm. It finds the minimum element in the unsorted part
 * of the array and swaps it with the first element of the unsorted part. The
 * array is printed after each swap of two elements.
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min_idx;

	for (i = 0; i < size - 1; i++)
	{
		min_idx = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_idx])
				min_idx = j;
		}
		if (min_idx != i)
		{
			int temp = array[i];

			array[i] = array[min_idx];
			array[min_idx] = temp;
			print_array(array, size);
		}
	}
}
