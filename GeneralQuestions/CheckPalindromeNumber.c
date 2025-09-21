#include <stdio.h>
#include <_stdlib.h>

int reverse(int num);

int isPalindrome(int num);

int main(void) {
    int num;
    printf("Enter a number: ");
    if (scanf("%d", &num) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    if (isPalindrome(num)) {
        printf("The given number %d is a palindrome.\n", num);
    } else {
        printf("The given number %d is not a palindrome.\n", num);
    }

    return EXIT_SUCCESS;
}

int isPalindrome(const int num) {
    /* Decide how to treat negative numbers. Here we treat negatives as NOT palindrome. */
    if (num < 0) return 0;
    return num == reverse(num);
}

int reverse(const int num) {
    int rev = 0;
    int n = num;
    while (n != 0) {
        rev = rev * 10 + (n % 10);
        n /= 10;
    }
    return rev;
}
