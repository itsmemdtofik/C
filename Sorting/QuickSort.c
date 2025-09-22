#include <stdio.h>

/* Function to swap two elements */
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/* Partition function (using last element as pivot) */
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; /* pivot element */
    int i = (low - 1); /* index of smaller element */

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            /* if current element < pivot */
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]); /* place pivot in correct position */
    return (i + 1);
}

/* QuickSort function (recursive) */
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        /* Partition index */
        int pi = partition(arr, low, high);

        /* Recursively sort left and right subarrays */
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

/* Utility function to print array */
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


int main() {
    int arr[] = {1, 10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, n);

    quickSort(arr, 0, n - 1);

    printf("Sorted array:   ");
    printArray(arr, n);

    return 0;
}
