#include <stdio.h>
#include <stdlib.h>

/**
 * Memory Management: Memory management is the process of handling how much memory a program uses through allocation, reallocation and deallocation (often referred to as "freeing").
 * There are two types of Memory:
 *
 * 1. Static Memory:
 * Static memory is memory that is reserved for variables before the program runs. Allocation of static memory is also known as compile time memory allocation.
 * C automatically allocates memory for every variable when the program is compiled.
 *
 * 2. Dynamic Memory:
 * Dynamic memory is memory that is allocated after the program starts running. Allocation of dynamic memory can also be referred to as runtime memory allocation.
 * Unlike with static memory, you have full control over how much memory is being used at any time. You can write code to determine how much memory you need and allocate it.
 * Dynamic memory does not belong to a variable, it can only be accessed with pointers.
 * To allocate dynamic memory, you can use the malloc() or calloc() functions. It is necessary to include the <stdlib.h> header to use them.
 * The malloc() and calloc() functions allocate some memory and return a pointer to its address.
 * The malloc() function has one parameter, size, which specifies how much memory to allocate, measured in bytes.
 * The calloc() function has two parameters:
 *  amount - Specifies the amount of items to allocate
 *  size - Specifies the size of each item measured in bytes
 *
 * Note: The best way to allocate the right amount of memory for a data type is to use the sizeof operator.
 *
 * Be careful: sizeof(*ptr1) tells C to measure the size of the data at the address.
 * If you forget the * and write sizeof(ptr1) instead, it will measure the size of the pointer itself,
 * which is the (usually) 8 bytes that are needed to store a memory address.
 *
 * Note: The sizeof operator cannot measure how much dynamic memory is allocated. When measuring dynamic memory,
 * it only tells you the size of the data type of the memory. For example, if you reserve space for 5 float values,
 * the sizeof operator will return 4, which is the number of bytes needed for a single float value.
 *
 */

int main(int argc, char *argv[]) {
    int students[20];
    printf("%zu\n", sizeof(students));

    int *ptr1 = malloc(sizeof(*ptr1));
    int *ptr2 = calloc(1, sizeof(*ptr2));

    printf("The size of pointer ptr1 is = %zu\n", sizeof(*ptr1));

    free(ptr1);
    free(ptr2);

    /**
    * Let's use dynamic memory to improve the students example above.
    * As noted previously, we cannot use sizeof to measure how much memory was allocated,
    * we have to calculate that by multiplying the amount of items by the size of the data type
    */

    const int numberOfTeachers = 12;

    int *teachers = calloc(numberOfTeachers, sizeof(*teachers));
    printf("The size of the total teachers is = %lu\n", numberOfTeachers * sizeof(teachers));

    free(teachers);

    return EXIT_FAILURE;
}
