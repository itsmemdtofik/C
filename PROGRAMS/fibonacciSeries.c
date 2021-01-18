#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i,a=0,b=1,c,n;
    printf("Enter the size of number : ");
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        printf("\n\n");
        printf("a values is = %d",a);
        c=a+b;
        a=b;
        b=c;
    }
    printf("\n\n");
}

