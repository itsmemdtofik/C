/** write a program to find the smallest element in an array of 10
elements using pointer **/

#include<stdio.h>
int main()
{
    int small,arr[20];
    int *ptr;
    printf("Enter ten element for an array\n");
    for(ptr=arr; ptr<arr+10; ptr++)
        scanf("%d",ptr);
    for(ptr=arr; ptr<+10; ptr++)
        printf("The element are=%d\n",*ptr);
    ptr=arr;
    small=*ptr;
    for(ptr=arr; ptr<arr+10; ptr++)
    {
        if(*ptr<small)
            small=*ptr;
    }
    printf("smallest element of the array is=%d",small);

}
