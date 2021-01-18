/* stack using linked list*/
#include <stdio.h>
#include <stdlib.h>
void push();
void pop();
void display();

struct node
{
    int data;
    struct node *link;
};

struct node *top = NULL;
void push();
void pop();
void display();

int main(void)
{
    int choice;
    printf("\n\t\t\------------------------------------\n\n");
    printf("\n\t\tSTACK OPRATIONS USING LINKED LIST\n\n");

    while (1)
    {
        printf("\n\t\t\------------------------------------\n\n");
        printf("\n\t\t\t 1-PUSH");
        printf("\n\t\t\t 2-POP");
        printf("\n\t\t\t 3-DISPLAY");
        printf("\n\t\t\t 4-EXIT");
        printf("\n\t\t\t Enter your choice : ");
        scanf("\n\t\t\t%d", &choice);
        printf("\n\t\t\------------------------------------\n\n");
        switch (choice)
        {
        case 1:

            push();
            break;

        case 2:

            pop();
            break;

        case 3:

            display();
            break;

        case 4:
            exit(0);
            printf("\n\t\t\t\tExiting....\n\n");
            break;
        default:

            printf("\n\t\tPlease Enter valid choice !\n\n ");
            break;
        }
    }
}

/**Inserting the element into stack */
void push()
{

    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL)
    {
        printf("\n\t\t\t\t  STACK IS EMPTY\n\n");
        temp = top;
    }
    else
    {

        printf("\n\t\t\t\tEnter the data : ");
        scanf("\n\t\t\t\t%d", &temp->data);
        printf("\n\n");
        temp->link = top;
        top = temp;

        printf("\n\t\t\t\t  ITEM PUSHED");
        printf("\n");
    }
}

/**Deleting element from stack */
void pop()
{

    struct node *temp;
    if (top == NULL)
    {
        printf("\n\t\t\t\tSTACK IS EMPTY\n\n");
    }
    else
    {
        temp = top;
        printf("\n\t\t\t\t %d DATA POPED", temp->data);
        printf("\n\n");
        top = top->link;
        temp->link = NULL;
        free(temp);
    }
}

/**Displaying the element of stack */
void display()
{

    struct node *temp;
    if (top == NULL)
    {
        printf("\n\t\t\t\tSTACK IS EMPTY\n\n");
    }
    else
    {
        temp = top;
        printf("\n\t\t\t\tPRINTING STACK ELEMENT.... \n\n");
        while (temp != NULL)
        {
            printf("\n\t\t\t\t%d\n", temp->data);
            printf("\n\n");
            temp = temp->link;
        }
    }
}
