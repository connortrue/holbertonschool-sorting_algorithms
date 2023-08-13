#include "sort.h"
#include <stdio.h>

void swap(int *a, int *b)
{
	int temp = *a;

	*a = *b;
	*b = temp;
}

int partition(int array[], int low, int high)
{
	int pivot = array[high];
	int i = low - 1;
	int j;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			swap(&array[i], &array[j]);
		}
	}
	swap(&array[i + 1], &array[high]);
	return (i + 1);
}

void quick_sort(int array[], int low, int high)
{
	if (low < high)
	{
		int pivot = partition(array, low, high);

		quick_sort(array, low, pivot - 1);
		quick_sort(array, pivot + 1, high);
	}
}

void print_array(int array[], unsigned int size)
{
	unsigned int i;

	for (i = 0; i < size; i++)
	{
		printf("%d", array[i]);
		if (i != size - 1)
		{
			printf(", ");
		}
	}
	printf("\n");
}
