#include "sort.h"

/**
 * bubble_sort - Sorts an array of integers in ascending order using the Bubble
 * sort algorithm.
 * @array: Pointer to the array.
 * @size: The size of the array.
 *
 * This function sorts the array of integers in ascending order using the
 * Bubble sort algorithm. It repeatedly swaps adjacent elements if they are in
 * the wrong order until the array is sorted. The array is printed after each
 * swap of two elements.
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int temp;

	if (array == NULL)
	{
		perror("Error: array is NULL\n");
		return;
	}

	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				print_array(array, size);
			}
		}
	}
}

