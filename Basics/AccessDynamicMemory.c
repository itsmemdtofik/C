#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {
    /**
     * As with arrays, to access an element in dynamic memory, refer to its index number.
     * ptr[0] = 12 is same as *ptr = 12, to access the first element of an array.
     * Dynamic memory does not have its own data type, it is just a sequence of bytes.
     * The data in the memory can be interpreted as a type based on the data type of the pointer.
     */

    int *ptr = calloc(4, sizeof(*ptr));

    /* Write to the memory */
    ptr[0] = 2; /* OR we can write it as *ptr = 2 both are same */
    ptr[1] = 4; /* OR we can write it as *(ptr + 1) = 4 both are same */
    ptr[2] = 6; /* OR we can write it as *(ptr + 2) = 6 both are same */

    /* Read from Memory */
    printf("%d\n", *ptr);
    printf("%d %d %d\n", ptr[1], ptr[2], ptr[3]);
    printf("%d %d %d\n", *(ptr + 1), *(ptr + 2), *(ptr + 3));

    free(ptr);

    return EXIT_FAILURE;
}
