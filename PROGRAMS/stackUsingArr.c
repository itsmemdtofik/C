/* write a c program to illustrate stack operation using static array */
#include <stdio.h>
#include <stdlib.h>

int stack[100];
int top = -1;
void push(int);
int pop();
void display();
void push(int element)
{
    if (top == 99)
    {
        printf("\n\t\t\t\tstack is full \n\n");
        exit(1);
    }
    top++;
    stack[top] = element;
}
int pop()
{
    if (top == -1)
    {
        printf("\n\t\t\t\tstack empty !\n\n");
        exit(1);
    }
    return (stack[top--]);
}
void peek()
{
    if (top == -1)
    {

        printf("\n\t\t\t\t Stack is empty !\n\n");
    }
    else
    {

        printf("\n\t\t\t\ttopmost element is = %d", stack[top]);
        printf("\n\n");
    }
}
void display()
{
    int i;
    if (top == -1)
    {
        printf("\n\t\t\t\t stack is empty !\n\n");
    }
    else
    {

        for (i = top; i >= 0; i--)
            printf("\n\t\t\t\t %d\t", stack[i]);
    }
    printf("\n\n");
}
void main()
{
    int choice, num1 = 0, num2 = 0;
    printf("\n\t\t\t\t------------------------------\n\n");
    printf("\t\t\t\t Stack USING ARRAY\n\n");

    while (1)
    {
        printf("\n\t\t\t\t------------------------------");
        printf("\n\t\t\t\t 1- Push");
        printf("\n\t\t\t\t 2- Pop");
        printf("\n\t\t\t\t 3- PEEK");
        printf("\n\t\t\t\t 4- Display");
        printf("\n\t\t\t\t 5- Exit");
        printf("\n\t\t\t\t --------------------------\n\n");
        printf("\n\t\t\t\t Enter your choice : ");
        scanf("\n %d", &choice);
        printf("\n\t\t\t\t --------------------------\n\n");
        switch (choice)
        {

        case 1:
            printf("\n\t\t\t\t Enter the element : ");
            scanf("\n\t\t\t\t%d", &num1);
            push(num1);
            break;

        case 2:
            num2 = pop();
            printf("\n\t\t\t\t Element poped is = \t%d", num2);
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        case 5:
            exit(1);

        default:
            printf("\n\t\t\t\t Invalid choice !");
            break;
        }
    }
}
