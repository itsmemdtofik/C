#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int findUniqueElementUsingNestedLoop(int nums[], int length);

int findUniqueElementUsingSorting(int nums[], int numsSize);

int findUniqueElementUsingXOR(const int nums[], int length);

int findUniqueElementUsingNestedLoop(int nums[], const int length) {
    for (int i = 0; i < length; i++) {
        int uniqueElement = 0;
        for (int j = 0; j < length; j++) {
            if (nums[i] == nums[j]) {
                uniqueElement++;
            }
        }
        if (uniqueElement == 1) {
            return nums[i];
        }
    }
    return -1;
}


int compare(const void *a, const void *b) {
    return (*(int *) a - *(int *) b);
}

int findUniqueElementUsingSorting(int *nums, const int numsSize) {
    qsort(nums, numsSize, sizeof(int), compare);
    for (int i = 0; i < numsSize - 1; i += 2) {
        if (nums[i] != nums[i + 1]) {
            return nums[i];
        }
    }
    return nums[numsSize - 1];
}

int findUniqueElementUsingXOR(const int *nums, const int length) {
    int uniqueElement = 0;
    for (int i = 0; i < length; i++) {
        uniqueElement = uniqueElement ^ nums[i];
    }
    return uniqueElement;
}

int main(int argc, char *argv[]) {
    int nums[] = {1, 4, 4, 1, 2, 1, 2, 5, 5, 10, 10, 9, 1};
    const int length = sizeof(nums) / sizeof(nums[0]);

    const int uniqueElement = findUniqueElementUsingNestedLoop(nums, length);

    printf("%d\n", uniqueElement);

    const int uniqueElementUsingSorting = findUniqueElementUsingSorting(nums, length);
    printf("%d\n", uniqueElementUsingSorting);

    const int uniqueElementUsingXOR = findUniqueElementUsingXOR(nums, length);
    printf("%d\n", uniqueElementUsingXOR);

    return EXIT_SUCCESS;
}
