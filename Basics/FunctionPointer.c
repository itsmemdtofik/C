/**
 * Function Pointer:
 * A pointer that stores the address of a function.
 * You can call the function using this pointer.
 * @param argc
 * @param argv
 * @return
 */

#include <stdio.h>
#include <_stdlib.h>

int add(int a, int b) { return a + b; }
int sub(int a, int b) { return a - b; }

int main(int argc, char *argv[]) {
    /* declare a function pointer */
    int (*fp)(int, int);

    fp = add; /* assign address of add */
    printf("Add: %d\n", fp(10, 5)); /* call via pointer */

    fp = sub; /* assign address of sub */
    printf("Sub: %d\n", fp(10, 5)); /* call via pointer */

    return EXIT_SUCCESS;
}
