#include <stdio.h>
#include <_stdlib.h>

int main(int argc, char *argv[]) {
    FILE *fptr = fopen("filename.txt", "r");

    char string[100];

    if (fptr != NULL) {
        while (fgets(string, 100, fptr)) {
            printf("%s", string);
        }
    } else {
        printf("Not able to open the file!");
    }

    fclose(fptr);
    return EXIT_FAILURE;
}
