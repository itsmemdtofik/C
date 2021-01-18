
// write a c program to display linear search //

#include <stdio.h>
int main()
{
    int arr[100], search,count=0,found=0, i, n;

    printf("Enter the size of an array : ");
    scanf("%d", &n);

    printf("Enter %d integer(s) : ", n);

    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter a number to search : ");
    scanf("%d", &search);

    for (i = 0; i < n; i++)
    {
        if (arr[i] == search)    /* If required element is found */
        {
            printf("%d is found at location : %d\n", search, i+1);
            count++;
            found=1;

        }
    }
    if (!found)
        printf("Element is not in the array");
}

