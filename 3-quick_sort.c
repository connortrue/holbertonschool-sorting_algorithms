int partition(int *array, int low, int high) {
    int pivot = array[high]; // Pivot element is the last element
    int i = low - 1; // Index of smaller element

    for (int j = low; j <= high - 1; j++) {
        if (array[j] <= pivot) {
            i++;
            // Swap the elements
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            // Print the array after each swap
            print_array(array, high - low + 1);
        }
    }
    // Swap the pivot element with the element at i+1
    int temp = array[i + 1];
    array[i + 1] = array[high];
    array[high] = temp;
    // Print the array after each swap
    print_array(array, high - low + 1);

    return i + 1; // Return the index of the pivot element
}

void quick_sort(int *array, size_t size) {
    if (size <= 1) {
        return; // Base case: array with 0 or 1 element is already sorted
    }

    int pivot_index = partition(array, 0, size - 1);

    // Recursively sort the sub-arrays before and after the pivot
    quick_sort(array, pivot_index);
    quick_sort(array + pivot_index + 1, size - pivot_index - 1);
}
