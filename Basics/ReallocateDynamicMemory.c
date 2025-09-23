#include <stdio.h>
#include <stdlib.h>

/**
 * Reallocation Dynamic Memory:
 * If the amount of memory you reserved is not enough, you can reallocate it to make it larger.
 * Reallocating reserves a different (usually larger) amount of memory while keeping the data that was stored in it.
 * You can change the size of allocated memory with the realloc() function.
 * The realloc() function takes two parameters:
 *      The first parameter is a pointer to the memory that is being resized.
 *      The second parameter specifies the new size of allocated memory, measured in bytes.
 *
 * Note: The realloc() function tries to resize the memory at ptr1 and return the same memory address.
 * If it cannot resize the memory at the current address then it will allocate memory at a different address and return the new address instead.
 *
 * Note: Note: When realloc() returns a different memory address, the memory at the original address is no longer reserved, and it is not safe to use.
 * When the reallocation is done it is good to assign the new pointer to the previous variable so that the old pointer cannot be used accidentally.
 * @param argc
 * @param argv
 * @return
 */
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *pointer1 = NULL;
    size_t size = 4 * sizeof(*pointer1);

    pointer1 = malloc(size);
    if (pointer1 == NULL) {
        perror("malloc");
        return EXIT_FAILURE;
    }

    printf("%zu bytes allocated at address %p\n", size, (void *) pointer1);

    /* Now resize the memory to hold six integers */
    size = 6 * sizeof (*pointer1);
    int *pointer2 = realloc(pointer1, size);
    if (pointer2 == NULL) {
        /* realloc failed: original pointer1 is still valid */
        perror("realloc");
        free(pointer1);
        return EXIT_FAILURE;
    }
    /* realloc succeeded: use pointer2 as the new pointer */
    pointer1 = pointer2;
    printf("%zu bytes reallocated at address %p\n", size, (void *) pointer1);

    free(pointer1);
    return EXIT_SUCCESS;
}
