#include <stdio.h>

/**
 * Null Pointer:
 * A null pointer is a pointer that doesn’t point to any valid memory location.
 * Good practice to initialize unused pointers as NULL.
 * Note: Dereferencing a null pointer (*p) → segmentation fault.
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, char *argv[]) {
    int *p = NULL; /* null pointer */
    if (p == NULL) {
        printf("Pointer is NULL, not pointing anywhere.\n");
    }
    return 0;
}
