#include "sort.h"
#define MAX_STACK_SIZE 100
/**
 * swap - Swaps the values of two integers.
 *
 * @a: pointer to the first integer
 * @b: pointer to the second integer
 *
 * Return: void
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
/**
 * lomuto_partition - Partitions an array using the Lomuto partition scheme.
 *
 * @array: pointer to the array
 * @low: starting index of the partition
 * @high: ending index of the partition
 *
 * Return: index of the pivot element after partitioning
 */
int lomuto_partition(int *array, int low, int high)
{
	int pivot = array[high];
	int j, k = low, i = low - 1;
	int sorted = 1;

	for (k = low; k < high; k++)
	{
		if (array[k] > array[k + 1])
		{
			sorted = 0;
			break;
		}
	}
	if (sorted)
		return (high);

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			swap(&array[i], &array[j]);
			print_array(array, high + 1);
		}
	}
	swap(&array[i + 1], &array[high]);
	print_array(array, high + 1);

	return (i + 1);
}
/**
 * quick_sort - Sorts an array using the quicksort algorithm.
 *
 * @array: pointer to the array
 * @size: size of the array
 *
 * returns: void
 */
void quick_sort(int *array, size_t size)
{
	int stack[MAX_STACK_SIZE];
	int top = -1;

	if (array == NULL || size <= 1 || size == 0)
		return;

	stack[++top] = 0;
	stack[++top] = size - 1;

	while (top >= 0)
	{
		int high = stack[top--];
		int low = stack[top--];

		int pivot_index = lomuto_partition(array, low, high);

		if (pivot_index - 1 > low)
		{
			stack[++top] = low;
			stack[++top] = pivot_index - 1;
		}

		if (pivot_index + 1 < high)
		{
			stack[++top] = pivot_index + 1;
			stack[++top] = high;
		}
	}
}
