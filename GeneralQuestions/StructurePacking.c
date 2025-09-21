#include <stdio.h>
#include <stdlib.h>

/**
 * Structure Packing:
 * Packing removes padding → members are stored back-to-back without gaps.
 * This is done using compiler directives like #pragma pack.
 * @param argc
 * @param argv
 * @return
 */

#pragma pack(1) /* force 1-byte alignment */

typedef struct A {
    char c;
    int i;
    char d;
} A;

int main(int argc, char *argv[]) {
    printf("Size of struct A: %zu\n", sizeof(A));
    return EXIT_FAILURE;
}
