/**
 * Call By Value:
 * A copy of the variable’s value is passed to the function.
 * The function works with the copy, not the original variable.
 * Changes made inside the function do not affect the original variable.
 *
 * @param argc
 * @param argv
 * @return
 */

#include <stdio.h>
#include <stdlib.h>

void swap(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
}

int main(int argc, char *argv[]) {
    int a = 10;
    int b = 20;

    printf("Before Swapping: a = %d and b = %d\n", a, b);

    swap(a, b);

    /**
     * Even though swap() changes values inside the function, the original a and b in main() remain unchanged.
     * That’s because C is using Call by Value here: only copies of a and b are swapped, not the originals.
     * Here, a and b are not swapped because the function got only copies of them.
    */
    printf("After Swapping: a = %d and b = %d\n", a, b);

    return EXIT_SUCCESS;
}
