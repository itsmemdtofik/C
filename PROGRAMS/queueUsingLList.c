/**queue using linked list */
#include<stdio.h>
#include<stdlib.h>

struct node
{

    int data;
    struct node *link;

};
struct node *front = NULL;
struct node *rear = NULL;


void enqueue();

void dequeue();

void display();

int main(void)
{

    int choice;
    printf("\n\t\t--------------------------------------------\n\n");
    printf("\n\t\t\t Queue Operation Using Linked List\n\n");
    while (1)
    {

        printf("\n\t\t--------------------------------------------\n\n");
        printf("\n\t\t\t\t1-Insert From Rear");
        printf("\n\t\t\t\t2-Delete From Front");
        printf("\n\t\t\t\t3-Display");
        printf("\n\t\t\t\t4-Exit");
        printf("\n\n");
        printf("\n\t\t\t\tEnter the choice : ");
        scanf("\n\t\t\t\t%d", &choice);
        printf("\n\n");

        switch (choice)
        {

        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
            printf("\n\t\t\tExitting queue....\n\n");
            break;
        default:
            printf("\n\t\t\tInvalid choice\n\n");

        }

    }

}


void enqueue()
{

    struct node *temp;
    int item;

    temp = (struct node *) malloc (sizeof(struct node));
    if(temp == NULL)
    {
        printf("\n\t\t\t\tQueue is Empty\n\n");

    }
    else
    {
        printf("\n\t\t\t\tEnter data : ");
        scanf("\n\t\t\t\t%d",&item);
        printf("\n\n");
        temp -> data = item;
        if(front == NULL)
        {
            front = temp;
            rear = temp;
            front -> link = NULL;
            rear -> link = NULL;
        }
        else
        {
            rear -> link = temp;
            rear = temp;
            rear->link = NULL;
        }
    }



}


void dequeue()
{

    struct node *temp;
    if(front == NULL)
    {
        printf("\n\t\t\t\tQueue is empty\n\n");

    }
    else
    {
        temp = front;
        front = front -> link;
        free(temp);
    }

}


void display()
{

    struct node *temp;
    temp = front;
    if(front == NULL)
    {
        printf("\n\t\t\t\tEmpty queue\n\n");
    }
    else
    {
        printf("\n\t\t\t\tPrinting Queue's data .....\n\n");
        while(temp != NULL)
        {
            printf("\n\t\t\t\t%d",temp -> data);
            printf("\n\n");
            temp = temp -> link;
        }
    }


}
