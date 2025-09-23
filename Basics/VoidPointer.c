#include <_stdlib.h>
/**
 * Void Pointer:
 * A generic pointer that can point to any data type, but it cannot be dereferenced directly without casting.
 * Can store the address of any type (int, float, struct, etc).
 * Must be typecast before dereferencing.
 * Useful in generic functions (like malloc() in C, which returns a void *).
 * @param argc
 * @param argv
 * @return
 */

#include <stdio.h>
#include <_stdlib.h>

int main(int argc, char *argv[]) {
    int x = 10;
    float y = 5.5;
    char c = 'A';

    void *ptr; /* void pointer */

    ptr = &x;
    printf("x = %d\n", *(int *) ptr); /* cast to int* */

    ptr = &y;
    printf("y = %.2f\n", *(float *) ptr); /* cast to float* */

    ptr = &c;
    printf("c = %c\n", *(char *) ptr); /* cast to char* */

    return EXIT_SUCCESS;
}
