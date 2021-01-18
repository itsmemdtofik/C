
// write a c program to illustrate to implement linked list //
#include<stdio.h>
#include<stdlib.h>


int list[100];
int top=-1;
void insert(int);
int delete();
void display();
void insert(int element)
{
	if(top==99)
	{
		printf("list is full");
		exit(1);
	}
	top++;
	list[top]=element;
}
int delete()
{
if(top==-1)
{
	printf("list empty");
	exit(0);
}
return(list[top--]);

}
void display()
{
	int i;
	if (top==-1)
	{
		printf("\n list is empty\n");
	}
	else
	{
       printf("\n Element of the Queue are :");
	for(i=top; i>=0; i--)
		printf("\n %d\n",list[i]);
}
}
void main()
{
int choice,num1=0,num2=0;
while(1)
       {
   	printf("------------------");
	printf("\n 1- Insert" );
	printf("\n 2- Delete");
	printf("\n 3- Display");
	printf("\n 4- Exit\n");
      printf("------------------\n");
	printf("\n Enter your choice :");
	scanf("\n %d",&choice);


	switch(choice)
	{

	case 1: printf("\n Enter the element :");
	scanf("%d",&num1);
	insert(num1);
	break;

	case 2: num2=delete();
	printf(" \nElement Deleted is :%d\n",num2);
	break;

	case 3: display();
	break;
	case 4: exit(0);

		default:printf("\n Invalid choice");
		break;

    }

        }
    }


