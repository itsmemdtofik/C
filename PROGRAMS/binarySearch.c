#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i, n, mid, low, heigh, search, arr[100];
    int found = 0;
    int count = 0;
    printf("Enter the size of element : ");
    scanf("%d", &n);
    printf("Enter the element : ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter the element to be searched : ");
    scanf("%d", &search);
    low = 0;
    heigh = n - 1;

    while (low <= heigh)
    {
        mid = (low + heigh) / 2;
        if (search < arr[mid])
        {
            heigh = mid - 1;
        }
        else if (search > arr[mid])
        {
            low = mid + 1;
        }
        else if (search == arr[mid])
        {
            printf("%d found at location %d ", search, mid + 1);
            found = 1;
            printf("\n\n");
            break;
        }
        else
        {
            printf("Invalid search !");
        }
    }

    if (low > heigh)
    {
        printf("%d is not present in the array", search);
    }
}
