#include <stdio.h>

int main(int argc, char *argv[]) {
    int number;
    char character;
    printf("Enter the number and character : ");
    scanf("%d %c", &number, &character);
    printf("number is = %d, and character is = %c \n", number, character);

    /* Create a String */
    char firstName[30];
    printf("Enter your first name: \n");
    scanf("%s", firstName);
    printf("hello %s\n", firstName);

    char fullName[30];

    printf("Type your full name: \n");
    scanf("%s", fullName);

    printf("Hello %s\n", fullName);

    /* From the example above, you would expect the program to print "John Doe", but it only prints "John".*/

    /* That's why, when working with strings, we often use the fgets() function to read a line of text.
     * Note that you must include the following arguments: the name of the string variable, sizeof(string_name), and stdin:*/

    char details[30];
    printf("Enter the details: \n");
    fgets(details, sizeof(details), stdin);
    printf("Hello %s\n", details);


    return 0;
}
