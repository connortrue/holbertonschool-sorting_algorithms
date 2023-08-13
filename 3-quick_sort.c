#include "sort.h"

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int arr[], int low, int high) {
	int pivot = arr[high];
	int i = low - 1;
	int j;

	for (j = low; j <= high - 1; j++) {
		if (arr[j] <= pivot) {
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

void quick_sort(int arr[], int low, int high) {
	if (low < high) {
		int pivot = partition(arr, low, high);
		quick_sort(arr, low, pivot - 1);
		quick_sort(arr, pivot + 1, high);
	}
}

void print_array(int arr[], unsigned int size) {
	unsigned int i;
	for (i = 0; i < size; i++) {
		printf("%d", arr[i]);
		if (i != size - 1) {
			printf(", ");
		}
	}
	printf("\n");
}
