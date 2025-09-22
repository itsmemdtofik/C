#include <stdio.h>
#include <stdlib.h>

/**
 * Pass By Reference:
 * When you pass a variable to a function such that the function can directly modify the original variable (not just a copy).
 * Pass by reference → describes how the argument is passed (by giving its reference/address).
 * Call by reference → describes how the function call behaves (function works on the original variable).
 *
 * Note: C does not have native references, so we simulate it using pointers:
 * @param age
 * @param argc
 * @param argv
 * @return
 */

void update(int *age);

int main(int argc, char *argv[]) {
    int a = 10;
    update(&a); /* passing address -> behaves like call by reference */
    printf("a = %d\n", a); // 100
}

void update(int *age) {
    *age = 60;
}
