#include<stdio.h>
#include<stdlib.h>
int mul(int a,int b);
int main()
{
    int m,n,c;
    printf("Enter the first number : ");
    scanf("%d",&m);
    printf("Enter the second number : ");
    scanf("%d",&n);
    c=mul(m,n);
    printf("The multiplication of two number is = %d",c);
    printf("\n\n");
    return 0;
}

int mul(int m,int n)
{
    int x,y;
    if(m==0 || n==0)
    {
        return 0;
    }
    else if(n==1)
    {
        return m;
    }
    else if(n!=0)
    {
        x=n-1;
        y=mul(m,n-1);
        return (m+mul(m,x));

    }
    else
    {
        return 0;
    }

}
