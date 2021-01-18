#include <stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
};

struct node *front=-1;
struct node *rear=-1;

void cenqueue();
void cdequeue();


void cenqueue()
{

    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    printf("\n\t\t\t\tEnter data : ");
    scanf("\n\t\t\t\t%d",&temp->data);
    temp->link=0;
    if(rear==-1)  // checking whether the Queue is empty or not.
    {
        front=rear=temp;
        rear->link=front;
    }
    else
    {
        rear->link=temp;
        rear=temp;
        rear->link=front;
    }
}

// function to delete the element from the queue
void cdequeue()
{
    struct node *temp;   // declaration of pointer of node type
    temp=front;
    if((front==-1)&&(rear==-1))  // checking whether the queue is empty or not
    {
        printf("\n\t\t\t\tQUEUE IS EMPTY\n\n");
    }
    else if(front==rear)  // checking whether the single element is left in the queue
    {
        front=rear=-1;
        free(temp);
    }
    else
    {
        front=front->link;
        rear->link=front;
        free(temp);
    }
}

// function to get the front of the queue
int peek()
{
    if((front==-1) &&(rear==-1))
    {
        printf("\n\t\t\t\tQUEUE IS EMPTY\n\n");
    }
    else
    {
        printf("\n\t\t\t\tThe front element is = %d", front->data);
        printf("\n\n");
    }
}

// function to display all the elements of the queue
void display()
{
    struct node *temp;
    temp=front;
    printf("\n\t\t\t\tQUEUE IS PRINTING DATA....\n\n");
    if((front==-1) && (rear==-1))
    {
        printf("\n\t\t\t\tQUEUE IS EMPTY\n\n");
    }

    else
    {
        while(temp->link!=front)
        {
            printf("\n\t\t\t\t%d", temp->data);
            printf("\n\n");
            temp=temp->link;
        }
        printf("\n\t\t\t\t%d", temp->data);
        printf("\n\n");
    }
}

int main(void)
{

    int choice;
    printf("\n\t\t--------------------------------------------\n\n");
    printf("\n\t\t\t Queue Operation Using Linked List\n\n");
    while (1)
    {

        printf("\n\t\t--------------------------------------------\n\n");
        printf("\n\t\t\t\t1-Insert");
        printf("\n\t\t\t\t2-Delete");
        printf("\n\t\t\t\t3-Display");
        printf("\n\t\t\t\t4-Peek");
        printf("\n\t\t\t\t5-Exit");
        printf("\n\n");
        printf("\n\t\t\t\tEnter the choice : ");
        scanf("\n\t\t\t\t%d", &choice);
        printf("\n\n");

        switch (choice)
        {

        case 1:
            cenqueue();
            break;
        case 2:
            cdequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            peek();
            break;
        case 5:
            exit(0);
            printf("\n\t\t\tExitting queue....\n\n");
            break;
        default:
            printf("\n\t\t\tInvalid choice\n\n");

        }

    }

}


