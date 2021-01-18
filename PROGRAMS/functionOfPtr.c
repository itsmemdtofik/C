/** write a c program to illustrate the use of function pointer **/
#include<stdio.h>

int main()
{
	int sum(int,int);
	int smallest(int,int);
	int (*ptr)(int,int);
	int a,b,r;
	printf("Input two integer\n");
	scanf("%d%d",&a,&b);
	ptr=sum;
	r=(*ptr)(a,b);
	printf("The sum of %d and %d is=%d\n",a,b,r);
	ptr=smallest;
	r=(*ptr)(a,b);
	printf("The smallest of %d and %d is= %d",a,b,r);

	return 0;
}
int sum(int m, int n)
{
	return(m+n);
}
int smallest(int m, int n)
{

if(m<n)
	return m;
	else
	return n;
}

