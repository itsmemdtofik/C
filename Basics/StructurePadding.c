#include <stdio.h>
#include <stdlib.h>

/**
 * Structure Padding:
 * When you define a structure, the compiler may insert empty bytes (padding) between members to align them properly in memory.
 * Reason: Many CPUs are faster if variables are stored at addresses divisible by their size.
 * (Example: int should start at an address multiple of 4 on a 32-bit system).
 * Note: Padding ensures proper alignment for CPU efficiency, but increases memory usage.
*/

typedef struct A {
    char c;
    int i;
    char d;
} A;

int main(int argc, char *argv[]) {
    printf("Size of the struct A: %zu\n", sizeof(A));
    return EXIT_SUCCESS;
}
