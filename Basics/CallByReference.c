#include <stdio.h>
#include <stdlib.h>


/**
 * Call By Reference:
 * Instead of passing a copy, we pass the address (pointer) of the variable.
 * The function works on the actual variable using its memory address.
 * Changes inside the function do affect the original variable.
 * @param argc
 * @param argv
 * @return
 */

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(int argc, char *argv[]) {
    int a = 10;
    int b = 20;

    printf("Before Swapping: a = %d and b = %d\n", a, b);

    swap(&a, &b);

    printf("After Swapping: a = %d and b = %d\n", a, b);

    return EXIT_SUCCESS;
}
