/**
 * swap - Swaps two elements in an array.
 * @a: Pointer to the first element.
 * @b: Pointer to the second element.
 *
 * This function swaps the values of the elements pointed to by @a and @b.
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * partition - Partitions an array around the pivot using the Lomuto partition
 * scheme.
 * @array: Pointer to the array.
 * @low: The starting index of the partition.
 * @high: The ending index of the partition.
 *
 * This function chooses the last element of the partition as the pivot and
 * partitions the array such that all elements smaller than or equal to the
 * pivot are placed before it, and all elements greater than the pivot are
 * placed after it. It returns the index of the pivot after partitioning.
 *
 * Return: The index of the pivot after partitioning.
 */
int partition(int *array, int low, int high)
{
	int pivot = array[high]; /* Choose the last element as the pivot */
	int i = low - 1;

	for (int j = low; j <= high - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			swap(&array[i], &array[j]);
			print_array(array, high + 1); /* Print the array after each swap */
		}
	}
	swap(&array[i + 1], &array[high]);
	print_array(array, high + 1); /* Print the array after each swap */
	return (i + 1);
}


/**
 * quick_sort_helper - Recursively sorts an array using the Quick sort
 * algorithm.
 * @array: Pointer to the array.
 * @low: The starting index of the partition.
 * @high: The ending index of the partition.
 *
 * This function is a helper function for the quick_sort function. It
 * recursively sorts the array using the Quick sort algorithm by calling the
 * partition function and performing recursive calls for the left and right
 * partitions.
 */
void quick_sort_helper(int *array, int low, int high)
{
	if (low < high)
	{
		int pivot_index = partition(array, low, high);

		quick_sort_helper(array, low, pivot_index - 1);
		quick_sort_helper(array, pivot_index + 1, high);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order using the Quick
 * sort algorithm.
 * @array: Pointer to the array.
 * @size: The size of the array.
 *
 * This function sorts the array of integers in ascending order using the Quick
 * sort algorithm. It implements the Lomuto partition scheme, with the pivot
 * always being the last element of the partition being sorted. The array is
 * printed after each swap of two elements.
 */
void quick_sort(int *array, size_t size)
{
	quick_sort_helper(array, 0, size - 1);
}

