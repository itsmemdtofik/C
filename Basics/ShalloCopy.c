/**
 * Shallow Copy ( OR Call By Reference ):
 * A shallow copy copies only the top-level values (bit by bit).
 * If the structure contains pointers, only the pointer addresses are copied, not the actual data they point to.
 * This means both copies share the same memory for pointer members → changing one affects the other.
 * Note: In C:
 * Assignment (=) between structs → shallow copy.
 * To make a deep copy, you must manually allocate memory and copy contents.
 *
 * @param argc
 * @param argv
 * @return
 */

#include <stdio.h>
#include <_stdlib.h>

typedef struct Student {
    char *name;
    int age;
} Student;

int main(int argc, char *argv[]) {
    Student s1;
    s1.name = "Alice"; /* points to string literal */
    s1.age = 20;

    Student s2 = s1; /* shallow copy */

    printf("s1: %s, %d\n", s1.name, s1.age);
    printf("s2: %s, %d\n", s2.name, s2.age);

    /**
     * Both s1.name and s2.name point to the SAME string
     * If you change s2.name, it still points to the same string (no separate copy).
     */
    return EXIT_SUCCESS;
}
