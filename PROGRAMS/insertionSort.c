/**  Write a c program to implement insertion sort using decrease and conquer method **/

#include<stdio.h>
#include<stdlib.h>
int main()
{
    int i,j,n,a[20],item;
    printf("Enter the size of an array  :");
    scanf("%d",&n);
    printf("Enter the element  :");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
        printf("Before sorting  :");
    for(i=0;i<n;i++)
        printf("\t %d",a[i]);
    for(i=1;i<=n-1; i++)
    {
        item=a[i];
        j=i-1;
        while(item<a[j] && j>=0)
        {
            a[j+1]=a[j];
            j=j-1;
        }
        a[j+1]=item;
    }
    printf("\nAfter sorting  :");
    for(i=0;i<n;i++)
        printf("\t %d",a[i]);
}
