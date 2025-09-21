#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main() {
    char text = 'abcdef';
    printf("%c", text);

    printf("\n");

    char myText[] = "abcdef";
    printf("%s", myText);

    const float sum = (float) 5 / 2;
    printf("%.1f", sum);

    int peopleInRoom = 0;

    // 3 people enter
    peopleInRoom += 1;
    peopleInRoom += 1;
    peopleInRoom += 1;

    printf("%d\n", peopleInRoom); // 3

    // 1 person leaves
    peopleInRoom--;

    printf("%d\n", peopleInRoom); // 2

    const int nums[] = {10, 20, 30, 40, 50, 100};
    printf("The size of an array is = %zu", sizeof(nums));

    printf("\n");
    for (int i = 0; i < sizeof(nums) / sizeof(nums[0]); i++) {
        printf("%d\n", nums[i]);
    }

    printf("\n");

    const int length = sizeof(nums) / sizeof(nums[0]);

    printf("The total item in the array is = %d", length);
    printf("\n");

    printf("-------------- Working With String ---------------");

    printf("\n");
    char greetings[] = "Hello World";
    printf("%s", &greetings[0]);
    printf("%s", greetings);
    printf("%c", greetings[0]);

    greetings[0] = 'J';

    printf("%s", &greetings[0]);
    printf("%s", greetings);
    printf("%c", greetings[0]);

    /* Loop through the string */
    printf("\n");
    printf("Loop through the string: \n");
    for (int i = 0; i < sizeof(greetings) / sizeof(greetings[0]); i++) {
        printf("%c\n", greetings[i]);
    }

    int lengthOsString = sizeof(greetings) / sizeof(greetings[0]);
    /* The sizeof() operator includes null character as well */
    int lenOfString = strlen(greetings);

    printf("%d\n", lengthOsString);
    printf("%d\n", lenOfString);

    char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    printf("%zu\n", strlen(alphabet));
    printf("%zu\n", sizeof(alphabet));

    char alphabets[50] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    printf("%zu\n", strlen(alphabets)); // 26
    printf("%zu\n", sizeof(alphabets)); // 50

    for (int i = 0; i < strlen(greetings); i++) {
        printf("%c\n", greetings[i]);
    }

    /* Concatenate two string */
    char str1[20] = "Hello ";
    char str2[] = "World";

    strcat(str1, str2);
    printf("%s\n", str1);

    char str3[20];
    strcpy(str1, str2);
    printf("%s\n", str3);

    /* String Comparison */
    char str4[] = "Hello";
    char str5[] = "Hello";
    char str6[] = "Hi";

    // Compare str1 and str2, and print the result
    printf("%d\n", strcmp(str4, str5)); // Returns 0 (the strings are equal)

    // Compare str1 and str3, and print the result
    printf("%d\n", strcmp(str5, str6)); // Returns -4 (the strings are not equal)

    return 0;
}
