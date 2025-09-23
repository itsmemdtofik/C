/**
 * Wild Pointer:
 * A wild pointer is an uninitialized pointer → it points to a garbage (random) memory location.
 * It may cause crashes if you try to use it.
 *
 * Note: Best practice: Always initialize pointers either to NULL or a valid address.
 * @param argc
 * @param argv
 * @return
 */

#include <stdio.h>
#include <_stdlib.h>

int main(int argc, char *argv[]) {
    int *p; /* wild pointer (uninitialized!) */
    *p = 10; /* ❌ undefined behavior (may crash) */
    return EXIT_SUCCESS;
}
