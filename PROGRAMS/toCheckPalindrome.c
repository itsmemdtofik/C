#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int isPalindrome(char *inputString, int leftIndex, int rightIndex)
{
 if (leftIndex >= rightIndex)
 {
  return 1;
 }
 if (inputString[leftIndex] == inputString[rightIndex])
 {
  return isPalindrome(inputString, leftIndex + 1, rightIndex - 1);
 }
 return 0;
}

int main()
{
 char inputString[100];
 printf("Enter a string for palindrome check \n");
 scanf("%s", inputString);
 if (isPalindrome(inputString, 0, (strlen(inputString) - 1)))
 {
  printf("%s is a palindrome \n", inputString);
 }
 else
 {
  printf("%s is not a palindrome \n", inputString);
 }
 return 0;
}
