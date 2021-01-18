 // write a c program to implemented circular linked list //

#include<stdio.h>
#include<stdlib.h>
struct node
{
	int info;
	struct node *next;
};
struct node *last=NULL;
struct node *first=NULL;

/**Deleting from front */
void insertfront(int data)
{
	struct node *newnode=(struct node*)malloc(sizeof(struct node));
	newnode->info=data;
	newnode->next=NULL;
	if(last==NULL)
	{
		last=newnode;
		newnode->next=last;
	}
	else
	{
		newnode->next=last->next;
	}
	last->next=newnode;
}

/**Inserting from end */
void insertend(int data)
{
	struct node *t;
	struct node *newnode=(struct node*)malloc(sizeof(struct node));
	newnode->info=data;
	newnode->next=NULL;
	if(last==NULL)
	{
		last=newnode;
		newnode->next=last;
	}
	else
	{
		newnode->next=last->next;
	}
	last->next=newnode;
	last=newnode;

}

void display()
{
	struct node *t;
	t=last;
	if(last==NULL)
	{
		printf("\n Empty list" );
		return;
	}
	t=last->next;
	while(t!=last)
	{
		printf("\t %d",t->info);
		t=t->next;
	}
	printf("\t %d\n\n",t->info);
}
void deletefront()
{
	struct node *t;
	if(last==NULL)
	{
		printf("\n No nodes in the list");
		return;
	}
	else
	{
		t=last->next;
		last->next=t->next;
		printf("\n Elemented deleted is %d\n :",t->info);
		free(t);
	}
}
void deleteend()
{
	struct node *temp,*prev;
	if(last==NULL)
	{
		printf("\n No nodes in the list");
		return;
	}
	else
	{
		temp=prev=last;
		while(prev->next!=last)
		{
			prev=prev->next;
		}
		printf("\n Element deleted is %d\n : ",last->info);
		free(last);
		last=prev;
	}
}
void main()
{
	int n,choice;
	while(1)
	{
		printf("----------------------------------");
		printf("\n 1 insert from front");
		printf("\n 2 insert from end");
		printf("\n 3 delete from front");
		printf("\n 4 delete from end");
		printf("\n 5 display");
		printf("\n 6 exit\n");
		printf("----------------------------------\n");
		printf("\n\n Enter your choice : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: printf("\n Enter the value to be inserted : ");
			scanf("%d",&n);
			insertfront(n);
			break;

			case 2: printf("\n Enter the value to be inserted : ");
			scanf("%d",&n);
			insertend(n);
			break;

			case 3:deletefront();
			break;

			case 4:deleteend();
			break;

			case 5:display();
			break;

			case 6:exit(0);

		}

	}
	getch();
}
