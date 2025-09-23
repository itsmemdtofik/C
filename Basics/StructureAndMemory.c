#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int rollNo;
    char name[20];
    double marks;
};

typedef struct cars {
    char brand[32];
    int year;
} Cars;

int main() {
    /* Allocate memory for the one Student structure */
    struct Student *student = (struct Student *) malloc(sizeof(struct Student));

    /* Check if the allocation was successfully */
    if (student == NULL) {
        printf("Memory Allocation Failed.\n");
        return EXIT_FAILURE;
    }

    /* Assign the values */
    student->rollNo = 1;
    strcpy(student->name, "Mohammad");
    student->marks = 67.34;

    /* Display the values */
    printf("Roll Number: %d\n", student->rollNo);
    printf("Name of the student: %s\n", student->name);
    printf("Marks: %.2lf\n", student->marks);

    free(student);

    /**
     * Using Arrays of Structure:
     * We can also allocate memory for multiple structs at once, line an arrays
     */

    struct Student *student2 = (struct Student *) malloc(3 * sizeof(struct Student));

    if (student2 == NULL) {
        printf("Memory Allocation Failed");
        return EXIT_SUCCESS;
    }

    /* Fill the data for 3 Student structure */
    student2[0].rollNo = 10;
    strcpy(student2[0].name, "Rahul");
    student2[0].marks = 34.34;

    student2[1].rollNo = 20;
    strcpy(student2[1].name, "Monu");
    student2[1].marks = 70.34;

    student2[2].rollNo = 30;
    strcpy(student2[2].name, "Sanjay");
    student2[2].marks = 80.34;


    /* Print the data */
    for (int i = 0; i < 3; i++) {
        printf("Roll Number: %d\nStudent Name: %s\nMarks:%.2lf\n", student2[i].rollNo, student2[i].name,
               student2[i].marks);
    }

    free(student2);

    /**
     * Growing Arrays Later with realloc():
     * If you need more elements later, you can resize your dynamic array with realloc().
     * This may move the block to a new location and returns a new pointer.
     * Always store the result in a temporary pointer first to avoid losing the original memory if reallocation fails.
     */
    const int count = 2;
    Cars *cars = (Cars *) malloc(count * sizeof(Cars));
    if (cars == NULL) {
        fprintf(stderr, "Initial allocation failed\n");
        return EXIT_FAILURE;
    }

    /* Initialize first two cars */
    strcpy(cars[0].brand, "Toyota");
    cars[0].year = 2010;
    strcpy(cars[1].brand, "Audi");
    cars[1].year = 2019;

    /* Now we need one more cars and that grow -> to 3 */
    const int newCount = 3;
    Cars *temp = (Cars *) realloc(cars, newCount * sizeof(Cars));
    if (temp == NULL) {
        /* cars are still valid here; free it to avoid a leak */
        free(cars);
        fprintf(stderr, "Reallocation failed.\n");
        return EXIT_FAILURE;
    }

    /* Now use the reallocated block */
    cars = temp;

    /* Initialize the new element at index 2 */
    strcpy(cars[2].brand, "Kia");
    cars[2].year = 2022;

    /* Print All cars */
    for (int i = 0; i < newCount; i++) {
        printf("Brand:%s - Year:%d\n", cars[i].brand, cars[i].year);
    }

    free(cars);
    cars = NULL;
    return EXIT_SUCCESS;
}
