#include "sort.h"
#define MAX_STACK_SIZE 100
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int lomuto_partition(int *array, int low, int high)
{
	int pivot = array[high];
	int j, i = low - 1;

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

void quick_sort(int *array, size_t size)
{
	int stack[MAX_STACK_SIZE];
	int top = -1;
	int sorted = 1;
	size_t i;

	if (array == NULL || size <= 1)
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

	for (i = 1; i < size; i++)
	{
		if (array[i] < array[i - 1])
		{
			sorted = 0;
			break;
		}
	}

	if (sorted) 
		return;
}
