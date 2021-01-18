#include<stdio.h>
int fact(int);
int main(void)
{
	int n;
	printf("Enter the number for n : ");
	scanf("%d",&n);
	printf("factorial of %d is = %d ",n,fact(n));

}
	int fact(int n)
	{
		if(n==0)
			return 1;
		return n*fact(n-1);

	}
