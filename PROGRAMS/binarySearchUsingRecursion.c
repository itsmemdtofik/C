#include <stdio.h>
#include <stdlib.h>
int binaryRecursion(int search, int arr[], int low, int mid, int heigh);
int main()
{
    int i, n, low, heigh, mid, search, arr[100];
    int found;
    printf("Enter the size of number : ");
    scanf("%d", &n);
    printf("Enter the element : ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter the element to be search : ");
    scanf("%d", &search);
    found = binaryRecursion(search, arr, low, mid, heigh);
    printf("%d found at location %d", search, mid + 1);
    return 0;
}
int binaryRecursion(int search, int arr[100], int low, int mid, int heigh)
{

    if (low > heigh)
        return -1;
    mid = (low + heigh) / 2;
    if (search == arr[mid])
        return mid;
    else if (search < arr[mid])
    {
        heigh = mid - 1;
        return binaryRecursion(search, arr, low, mid, heigh);
    }
    else
    {
        low = mid + 1;
        return binaryRecursion(search, arr, low, mid, heigh);
    }
}
