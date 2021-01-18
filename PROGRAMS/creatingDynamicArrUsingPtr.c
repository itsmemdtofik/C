/** write a c program to create a dynamic array of integer using pointer **/
#include<stdio.h>
int main()
{

int *ptr,*table;
int n;
printf("Enter the size of an array\n");
scanf("%d",&n);
if((table=(int*)calloc(n,sizeof(int)))==NULL)
{
	printf("something is mistake creating your program\n");
	exit(1);
}
printf("Enter the Element of an array\n");
for(ptr=table; ptr<table+n; ptr++)
scanf("%d",ptr);
printf("Element of array are\n");
for(ptr=table; ptr<table+n; ptr++)
printf("%d",*ptr);
free(table);

}
