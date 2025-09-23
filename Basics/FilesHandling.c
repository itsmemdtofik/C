#include <stdio.h>
#include <_stdlib.h>

/**
 * FILE Handling: In C, you can create, open, read, and write to files by declaring a pointer of type FILE, and use the fopen() function.
 * filename:	The name of the actual file you want to open (or create), like filename.txt
 * mode:	A single character, which represents what you want to do with the file (read, write or append)
 * w - Writes to a file
 * a - Appends new data to a file
 * r - Reads from a file
 * @param argc
 * @param argv
 * @return
 */

/**
 * Creation of File:
 * To create a file, you can use the w mode inside the fopen() function.
 * The w mode is used to write to a file. However, if the file does not exist, it will create one for you.
 */
int main(int argc, char *argv[]) {
    FILE *fptr = fopen("filename.txt", "w");
    if (fptr != NULL) {
        printf("The file is created!");
    } else {
        printf("File is not created!");
    }

    fprintf(fptr, "I am writing to this file.");

    /**
     * Read From File
     */
    char string[100];
    fgets(string, 100, fptr);
    printf("%s\n", string);
    fclose(fptr);

    return EXIT_FAILURE;
}
