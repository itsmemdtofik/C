#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Deep Copy (OR Call By Value ):
 * A deep copy duplicates not just the top-level values but also allocates new memory for pointers and copies the actual data.
 * Both objects are fully independent.
 *
 * Note: In C:
 * Assignment (=) between structs → shallow copy.
 * To make a deep copy, you must manually allocate memory and copy contents.
 * @param argc
 * @param argv
 * @return
 */

typedef struct Student {
    char *name;
    int age;
} Student;

int main(int argc, char *argv[]) {
    Student s1;
    s1.name = malloc(20);
    strcpy(s1.name, "Alice");
    s1.age = 20;

    Student s2;
    s2.name = malloc(strlen(s1.name) + 1); /* allocate new memory */
    strcpy(s2.name, s1.name); /* copy contents */
    s2.age = s1.age;

    printf("s1: %s, %d\n", s1.name, s1.age);
    printf("s2: %s, %d\n", s2.name, s2.age);

    /* Modify s2 */
    strcpy(s2.name, "Bob");
    s2.age = 25;

    printf("\nAfter modifying s2:\n");
    /* Here, s1 and s2 are independent because we performed a deep copy. */
    printf("s1: %s, %d\n", s1.name, s1.age);
    printf("s2: %s, %d\n", s2.name, s2.age);

    free(s1.name);
    free(s2.name);

    return EXIT_SUCCESS;
}
