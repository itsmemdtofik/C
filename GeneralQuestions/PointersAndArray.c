#include <stdio.h>

int main(int argc, char *argv[]) {
    /**
     * We can also use the pointer to access array.
     * Consider the following array of integer.
     */

    const int nums[4] = {10, 20, 30, 40};
    for (int i = 0; i < 4; i++) {
        printf("Elements: %d\n", nums[i]);
    }

    /* OR */

    for (int i = 0; i < 4; i++) {
        const int number[4] = {25, 50, 75, 100};
        printf("Elements: %d\n", number[i]);
    }

    /* Note: Instead of printing the value of each array element, lets print the memory address of each array element. */
    for (int i = 0; i < 4; i++) {
        const int number[4] = {25, 50, 75, 100};
        printf("Memory Address of Array Element %d is = %p\n", number[i], &number[i]);
    }

    /* We can also find the size of an array */
    printf("The size of an array is = %zu\n", sizeof(nums));

    /**
     * How are pointer related to arrays:
     * Ok, so what's the relationship between pointers and arrays? Well, in C, the name of an array, is actually a pointer to the first element of the array.
     * Note: The memory address of the first element is the same as the name of the array.
     */

    int nums1[4] = {25, 50, 75, 100};
    printf("Get the memory address of the nums1 array : %p\n", nums1);
    printf("Get the memory address of the first array element: %p\n", &nums1[0]);

    /**
     * This besically means the we can work with arrays through pointers.
     * How? Since myNumbers is a pointer to the first element in myNumbers, you can use the * operator to access it.
     */

    int myNumbers[4] = {25, 50, 75, 100};
    printf("Get the value of the first element in myNumbers: %d\n", *myNumbers);
    printf("Get the value of the second element in myNumbers: %d\n", *(myNumbers + 1));
    printf("Get the value of the third element in myNumbers: %d\n", *(myNumbers + 2));
    printf("Get the value of the fourth element in myNumbers: %d\n", *(myNumbers + 3));

    /**
     * OR: Loop through it
     * Common Way -> int *numberPointer = myNumbers;
     * myNumbers automatically represents the address of its first element (common way )
     * Explicit Way: int *numberPointer = &myNumbers[0];
     */
    int *numberPointer = myNumbers;
    for (int i = 0; i < 4; i++) {
        printf("Element: %d\n", *(numberPointer + i));
    }

    /**
     * Note : It is also possible to change the value of array elements with pointer.
     */

    /* Change the value of the first element to 13 */
    *myNumbers = 13;

    /* Change the value of the second element to 17 */
    *(myNumbers + 1) = 17;

    /* Get the value of the first element */
    printf("%d\n", *myNumbers);

    /* Get the value of the second element */
    printf("%d\n", *(myNumbers + 1));

    return 0;
}
