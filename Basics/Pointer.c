#include <stdio.h>

/*
Memory Address:

When a variable is created in C, a meomry address is assigned to the variable.
The memory address is the location of where the variable is stored on the computer.
When we assign a value to the variable, it is stored in this memory address.
To Access it, use the reference operator (&), and the result represents where the variable is stored.
*/

/*
 * You should also note that &myAge is often called a "pointer".
 * A pointer basically stores the memory address of a variable as its value.
 * To print pointer values, we use the %p format specifier.
 */

/**
 * Why is it useful to know the memory address?
 * Pointers are important in C, because they allow us to manipulate the data in the computer's memory - this can reduce the code and improve the performance.
 * @param argc
 * @param argv
 * @return
 */

int main(int argc, char *argv[]) {
    int myAge = 50;
    printf("%d\n", myAge); /* Ouputs the value of myAge (50) */
    printf("%p\n", &myAge); /* Output: 0x16db6b01c*/

    /**
    * A pointer is a variable that stores the memory address of another variable as its value.
    * A pointer variable points to a data type (like int) of the same type, and is created with the * operator.
    * The address of the variable you are working with is assigned to the pointer:
    */

    int myAge1 = 43; /* An int variable */
    int *ptr = &myAge1; /* A pointer variable, with the name ptr, that stores the address of myAge */

    /* Output the value of myAge (43) */
    printf("%d\n", myAge1);

    /* Output the memory address of myAge (0x16afe3018) */
    printf("%p\n", &myAge1);

    /* Output the memory address of myAge with the pointer (0x16afe3018) */
    printf("%p\n", ptr);

    /**
     * Create a pointer variable with the name ptr, that points to an int variable (myAge).
     * Note that the type of the pointer has to match the type of the variable you're working with (int in our example).
     * Use the & operator to store the memory address of the myAge1 variable, and assign it to the pointer.
     * Now, ptr holds the value of myAge's memory address.
     *
     */

    /**
     * Dereference: You can also get the value of the variable the pointer points to, by using the * operator (the dereference operator).
     */

    int number = 43; /* Variable Declaration */
    int *pointer = &number; /* Pointer declaration */

    printf("%p\n", pointer); /* Reference: Output the memory address of myAge with the pointer (0x16cf7300c) */
    printf("%d\n", *pointer); /* Dereference: Output the value of myAge with the pointer (43) */

    return 0;
}
