/**
 * Sort an Array Using Quick Sort In-built method.
 * @param argc
 * @param argv
 * @return
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * base → pointer to the first element of the array
 * n-items → number of elements in the array
 * size → size of each element in bytes (sizeof(type))
 * compare → function pointer used for comparison
 * @param base
 * @param nitems
 * @param size
 * @param compar
 */
void qsort(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void *));

int compare(const void *a, const void *b);

int main(int argc, char *argv[]) {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    /* Sort using qsort */
    qsort(&arr, n, sizeof(int), compare);

    printf("Sorted array:   ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

/* Comparison Function */
int compare(const void *a, const void *b) {
    return *(int *) a - *(int *) b;
}
