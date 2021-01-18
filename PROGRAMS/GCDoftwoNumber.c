//  write a c program to find the gcd of two number using recursion //

#include<stdio.h>
#include<math.h>
int gcd(int,int);
void main()
{
	int a,b,result;
	printf("Enter the two number : ");
	scanf("%d%d",&a,&b);
	result=gcd(a,b);
	printf("gcd of %d and %d is =%d ",a,b,result);
	printf("\n\n");
}
int gcd(int a,int b)
{
while(a!=b)
{
	if(a>b)
	a=a-b;
	else if(b>a)
	b=b-a;
}
return a;
}
