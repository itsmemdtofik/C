#include <stdio.h>
#include <string.h>
#include <_stdlib.h>
/**
 * Union:
 * A Union is a user-defined data type that lets you group variables of different types under one name.
 * A union is similar to a structure, but with one big difference. All members share the same memory which means you can only use one of the values at a time.
 * Unlike an array, a Union can contain many different data types (int, float, char, etc.).
 * You can also assign values to members of a Union variable at declaration time, in a single line.
 *
 * Points about Unions:
 * One memory block is shared among all members.
 * If largest member is char str[20] (20 bytes), union size = 20 bytes.
 * At any time, only one member holds a valid value.
 * Useful when you need a variable to hold different types at different times (e.g., memory-efficient embedded systems).
 *
 * Note: Most of the time, you will use structs instead of unions, as it can store and access multiple values at the same time, which is more common in everyday programs.
 * However, unions are useful when you only need to store one of several possible types at a time, and you want to save memory.
 *
 * @param argc
 * @param argv
 * @return
 */

union Student {
    int rollNo;
    char name[20];
    float marks;
};

int main(int argc, char *argv[]) {
    union Student s1;

    s1.rollNo = 1;
    printf("Roll No: %d\n", s1.rollNo);

    strcpy(s1.name, "Rahul");
    printf("Name: %s\n", s1.name);

    s1.marks = 98.5;
    printf("Marks: %.2f\n", s1.marks);

    printf("The size of the union is: %zu", sizeof(s1));

    return EXIT_FAILURE;
}

/**
* When to Use Unions:
* Use unions when:
* You need to store different types in the same location
* You only use one type at a time
* Saving memory is very important
*/
