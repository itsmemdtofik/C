#include <stdio.h>
#include <string.h>

/**
 * Structure And Pointer:
 * You can use pointers with structs to make your code more efficient, especially when passing structs to functions or changing their values.
 * To use a pointer to a struct, just add the * symbol, like you would with other data types.
 * To access its members, you must use the -> operator instead of the dot . syntax.
 *
 * @param argc
 * @param argv
 * @return
 */

struct Student {
    int rollNo;
    char name[20];
    double marks;
};

/* Passing Struct Pointers to Function */
void updateStudentDetails(struct Student *s) {
    s->rollNo = 2;
    strcpy(s->name, "Mohammad");
    s->marks = 56.34;
}

int main(int argc, char *argv[]) {
    struct Student s1 = {1, "Rahul", 85.40};

    struct Student *ptr = &s1;

    printf("Roll No: %d\n", ptr->rollNo);
    printf("Name: %s\n", ptr->name);
    printf("Marks: %.2f\n", ptr->marks);

    updateStudentDetails(&s1);

    printf("Updated Student Details:\nRoll No: %d\n", ptr->rollNo);
    printf("Name: %s\n", ptr->name);
    printf("Marks: %.2f\n", ptr->marks);
}
