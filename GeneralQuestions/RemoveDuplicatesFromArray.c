#include <stdio.h>

int removeDuplicateUsingNestedLoop(int nums[], int length) {
    for (int i = 0; i < length; i++) {
        for (int j = i + 1; j < length;) {
            if (nums[i] == nums[j]) {
                for (int k = j; k < length - 1; k++) {
                    nums[k] = nums[k + 1];
                }
                length--;
            } else {
                j++;
            }
        }
    }
    return length;
}

#define MAX 101 /* Assuming arrays elements are in range [0, 100] */

int removeDuplicatesUsingHashing(const int nums[], const int length, int result[]) {
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
    int nums[] = {10, 20, 30, 20, 10, 40, 50, 30};
    int length = sizeof(nums) / sizeof(nums[0]);

    printf("Original Array: ");
    for (int i = 0; i < length; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");

    length = removeDuplicateUsingNestedLoop(nums, length);

    printf("After removing duplicates: ");
    for (int i = 0; i < length; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");

    return 0;
}
