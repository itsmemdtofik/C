#include <stdio.h>
#include <string.h>
#include <_stdlib.h>

/**
 * Structure:
 * A structure is a user-defined data type that lets you group variables of different types under one name.
 * Each variable in the structure is known as a member of the structure.
 * Unlike an array, a structure can contain many different data types (int, float, char, etc.).
 * You can also assign values to members of a structure variable at declaration time, in a single line.
 *
 * Key Points about Structures:
 * Each member has its own memory.
 * If int = 4 bytes, float = 4 bytes, char[20] = 20 bytes → total = ~28 bytes (may include padding).
 * You can access members using . (dot operator).
 * Multiple variables of a structure type can be created.
 * @param argc
 * @param argv
 * @return
 */
struct Student {
    int rollNo;
    char name[20];
    float marks;
};

int main(int argc, char *argv[]) {
    struct Student s1 = {1, "Rahul", 85.5};
    printf("Roll No: %d\n", s1.rollNo);
    printf("Name: %s\n", s1.name);
    printf("Marks: %.2f\n", s1.marks);

    /**
     * What about String in Structure:
     * Remember that strings in C are actually an array of characters, and unfortunately, you can't assign a value to an array like this.
    * Trying to assign a value to the string s1.myString = "Some text"; and this will produce an error.
    * We solve this using the method strcpy() to assign the string.
    */

    s1.rollNo = 2;
    strcpy(s1.name, "Kumar");
    s1.marks = 100.01;

    printf("Modified Structure:\nRoll No: %d\n", s1.rollNo);
    printf("Name: %s\n", s1.name);
    printf("Marks: %.2f\n", s1.marks);

    /**
     * Copy Structures
     * We can also copy the structure into another structure
     */

    const struct Student s2 = {3, "Monu", 67.5};
    struct Student s3 = s2;

    printf("Copied Structure:\nRoll No: %d\n", s3.rollNo);
    printf("Name: %s\n", s3.name);
    printf("Marks: %.2f\n", s3.marks);

    printf("The size of structure is = %zu", sizeof(s1));


    return EXIT_FAILURE;
}
