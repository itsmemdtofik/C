/**
| Function                | Description                                       | Example                                            |
| ----------------------- | ------------------------------------------------- | -------------------------------------------------- |
| `strlen(str)`           | Returns the length of the string (excluding `\0`) | `strlen("Hello") → 5`                              |
| `strcpy(dest, src)`     | Copies one string into another                    | `strcpy(b, a);`                                    |
| `strncpy(dest, src, n)` | Copies first `n` chars                             | `strncpy(b, a, 3);`                                |
| `strcat(dest, src)`     | Concatenates (joins) two strings                  | `"Hello" + " World"` → `"Hello World"`             |
| `strncat(dest, src, n)` | Concatenates first `n` chars                       |                                                    |
| `strcmp(s1, s2)`        | Compares two strings (returns 0 if equal)         | `strcmp("abc","abc") → 0`                          |
| `strncmp(s1, s2, n)`    | Compares first `n` chars                           |                                                    |
| `strchr(str, ch)`       | Finds first occurrence of a character              | `strchr("Hello",'e') → "ello"`                     |
| `strrchr(str, ch)`      | Finds last occurrence of a character              |                                                    |
| `strstr(str, substr)`   | Finds first occurrence of a substring              | `strstr("HelloWorld","World") → "World"`           |
| `strtok(str, delim)`    | Splits string into tokens                         | Splitting `"a,b,c"` with `","` gives `a`, `b`, `c` |
| `memcpy(dest, src, n)`  | Copies `n` bytes                                  |                                                    |
| `memset(str, ch, n)`    | Fills first `n` bytes with a value                 |                                                    |
| `memcmp(s1, s2, n)`     | Compares first `n` bytes                           |                                                    |
*/

#include <stdio.h>
#include <string.h>
#include <_stdlib.h>

int main(int argc, char *argv[]) {
    char str1[50] = "Hello";
    char str2[50] = "World";
    char str3[50];

    printf("Length of the str1: %lu\n", strlen(str1));

    strcpy(str3, str1);
    printf("After strcpy, str3 = %s\n", str3);

    strcat(str1, str2);
    printf("After strcat, str1 = %s\n", str1);

    /* Compare two string */
    if (strcmp(str1, str2) == 0) {
        printf("str1 and str2 are equals:\n");
    } else {
        printf("str1 and str2 are not equals:\n");
    }

    /* Find substring */
    char *pointer = strstr(str1, "World");
    if (pointer != NULL) {
        printf("Substring found: %s\n", pointer);
    }


    return EXIT_SUCCESS;
}
