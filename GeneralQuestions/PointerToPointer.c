/**
 * Pointer To Pointer:
 * A pointer to pointer (Also called Double Pointer) is a variable that store the address of another pointer variable.
 * @param argc
 * @param argv
 * @return
 */
#include <stdio.h>
#include <_stdlib.h>

void update(int **pointerToPointer);

int main(int argc, char *argv[]) {
    /**
     * A Pointer is a variable that stores the address of another variable.
     */
    int age = 20;
    int *pointer = &age; /* variable pointer stores the address of age */

    /**
     * Let's see the Double Pointer.
     * A pointer to pointer (also called double pointer) is a variable that stores the address of another pointer.
     */

    int rollNo = 50;
    int *ptr = &rollNo; /* Here, variable ptr stores the address of age */
    int **pointerToPointer = &ptr; /* pointerToPointer stores of ptr */

    printf("%d\n", rollNo); /* 50 */
    printf("%d\n", *ptr); /* 50 (value at address stored in ptr) */

    /* 50 (value at address stored in *pointerToPointer → which is ptr → which points to rollNo) */
    printf("%d\n", **pointerToPointer);

    /**
     * Why use pointer to pointer?
     * 1. Dynamic Memory Allocation (e.g, malloc with 2D arrays)
     * 2. Passing pointer to function (when function needs to modify the original pointer).
     */
    int **nums = (int **) malloc(3 * sizeof(int *));
    for (int i = 0; i < 3; i++) {
        nums[i] = (int *) malloc(4 * sizeof(int)); /* like a 3x4 matrix */
    }


    int x = 10;
    int *p = &x;
    update(&p); /* pass address of pointer */
    printf("%d", x); /* 20 */


    free(nums);
    return EXIT_SUCCESS;
}

void update(int **pointerToPointer) {
    **pointerToPointer = 20; /* Change original value */
}
