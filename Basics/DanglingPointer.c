/**
 * Dangling Pointer:
 * A dangling pointer is a pointer that used to point to valid memory, but that memory has been freed or gone out of scope.
 * The pointer still holds the old address, but that memory is no longer valid.
 * Note: Best practice: After free(p); → set p = NULL; to avoid dangling pointer.
 * @param argc
 * @param argv
 * @return
 */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int *p = (int *) malloc(sizeof(int));
    *p = 42;
    free(p); /* memory released */
    printf("%d\n", *p); /* ❌ dangling pointer (memory freed) but still using p*/

    return EXIT_SUCCESS;
}
