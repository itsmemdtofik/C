//  write a c program to find the gcd of two  number prototype //

#include<stdio.h>
int gcd(int,int);
void main()
{
    int m,n,result;
    printf("Enter two number : ");
    scanf("%d%d",&m,&n);
    result=gcd(m,n);
    printf("gcd of %d abd %d is: %d ",m,n,result);
    printf("\n\n");
}
int gcd(int m,int n)
{
    if(n==0)
        return m;
    if(m<n)
        return gcd(n,m);

    return gcd(n,m%n);
}
