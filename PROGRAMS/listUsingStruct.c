/* write a c program to implement using linked list */

#include<stdio.h>
#include<stdlib.h>
struct node
{
	int *info;
	struct node *next;
};
struct node *first=NULL;
void insert(int data)
{
	struct node *t;
	int *info;
	struct node *newnode=(struct node*)malloc(sizeof(struct node));
	newnode->info=data;
	newnode->next=NULL;
	if(first==NULL)
	{
		first=newnode;
	}
	else
	{
		t=first;
		while(t->next!=NULL)
		{
			t=t->next;
		}
		t->next=newnode;

	}
}
void delete()
{
	struct node *temp,*prev;
	if(first==NULL)
	{
		printf("No node in the list ");
		return ;
	}
	else
	{
		temp=prev=first;
		while(temp->next!=NULL)
		{
			prev=temp;
			temp=temp->next;
		}
		prev->next=NULL;
		printf("Element deleted is : %d\n",temp->info);
		free(temp);
	}
}
void display()
{
struct node *t;
t=first;
if(first==NULL)
{
	printf(" List is Empty\n");
}
	else
	{
		while(t!=NULL)
		{
			printf("%d\n",t->info);
			t=t->next;
		}
	}
}

void main()
{
	int n,choice;
	while(1)
	{
		printf("-----------------------");
		printf("\n 1-Insert");
		printf("\n 2-Delete");
		printf("\n 3-Display");
		printf("\n 4-Exit\n");
		printf("-----------------------\n\n");
		printf("Enter your choice : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:printf("Enter the element to be insert : ");
			scanf("%d",&n);
			insert(n);
			break;
			case 2:delete();
			break;
			case 3:display();
			break;
			case 4:exit(0);
			break;
		}
	}

}
