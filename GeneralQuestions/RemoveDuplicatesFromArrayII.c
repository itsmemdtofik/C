#include <stdio.h>
#include <_stdlib.h>

#define MAX 101 /* Assuming arrays elements are in range [0, 100] */

int removeDuplicateUsingHashing(const int nums[], const int length, int result[]) {
    int seen[MAX] = {0}; /* Hash Table */
    int newSize = 0;

    for (int i = 0; i < length; i++) {
        /* Not seen before */
        if (seen[nums[i]] == 0) {
            result[newSize++] = nums[i];
            seen[nums[i]] = 1; /* Marked as seen */
        }
    }
    return newSize;
}

int main(int argc, char *argv[]) {
    const int arr[] = {10, 20, 30, 20, 10, 40, 50, 30, 100, 0, 50};
    const int length = sizeof(arr) / sizeof(arr[0]);
    int result[length];

    printf("Original array: ");
    for (int i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    const int newSize = removeDuplicateUsingHashing(arr, length, result);

    printf("Array after removing duplicates: ");
    for (int i = 0; i < newSize; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    return EXIT_SUCCESS;
}
