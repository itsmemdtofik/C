
// write a c program to display array element using selection sort technique //

#include<stdio.h>
void main()
{
	int a[100],i,j,temp,n;
	printf("Enter the size of an element\n");
	scanf("%d",&n);
	printf("Enter the lement\n");
	for(i=0; i<n; i++)
		scanf("%d",&a[i]);
	printf("Before sorting\n");
	for(i=0; i<n; i++)
		printf("%d\n",a[i]);
	for(i=0; i<n-1; i++)
	{
		for(j=i+1; j<n; j++)
		{
			if(a[i]>a[j])
			{
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}
	printf("After sorting\n");
	for(i=0; i<n; i++)
		printf("%d\n",a[i]);
}
