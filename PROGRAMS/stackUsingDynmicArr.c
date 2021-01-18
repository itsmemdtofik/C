/* write a program to stack using pointer
#include<stdio.h>
#include<stdlib.h>

#define MAX 50
int size;

// Defining the stack structure
struct stack
{
    int arr[MAX];
    int top;
};

// Initializing the stack(i.e., top=-1)
void init_stk(struct stack *st)
{
    st->top = -1;
}

// Entering the elements into stack
void push(struct stack *st, int num)
{
    if (st->top == size - 1)
    {
        printf("\nStack overflow(i.e., stack full).");
        return;
    }
    st->top++;
    st->arr[st->top] = num;
}

//Deleting an element from the stack.
int pop(struct stack *st)
{
    int num;
    if (st->top == -1)
    {
        printf("\nStack underflow(i.e., stack empty).");
        return NULL;
    }
    num = st->arr[st->top];
    st->top--;
    return num;
}

void display(struct stack *st)
{
    int i;
    for (i = st->top; i >= 0; i--)
        printf("\n%d", st->arr[i]);
}

int main()
{
    int element, opt, val;
    struct stack ptr;
    init_stk(&ptr);
    printf("\nEnter Stack Size :");
    scanf("%d", &size);
    while (1)
    {
        printf("\n\ntSTACK PRIMITIVE OPERATIONS");
        printf("\n1.PUSH");
        printf("\n2.POP");
        printf("\n3.DISPLAY");
        printf("\n4.QUIT");
        printf("\n");
        printf("\nEnter your option : ");
        scanf("%d", &opt);
        switch (opt)
        {
        case 1:
            printf("\nEnter the element into stack:");
            scanf("%d", &val);
            push(&ptr, val);
            break;
        case 2:
            element = pop(&ptr);
            printf("\nThe element popped from stack is : %d", element);
            break;
        case 3:
            printf("\nThe current stack elements are:");
            display(&ptr);
            break;
        case 4:
            exit(0);
        default:
            printf("\nEnter correct option!Try again.");
        }
    }
    return (0);
}
*/



/* C program for array implementation of stack using dynamic array structure */
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
struct Stack
{
    int top;
    int capacity;
    int* array;
};
struct Stack* createStack(int capacity)
{
    struct Stack* myStack ;
    myStack= (struct Stack*)malloc(sizeof(struct Stack));
    myStack->capacity = capacity;
    myStack->top = -1;
    myStack->array = (int*)malloc(myStack->capacity * sizeof(int));
    return myStack;
}
int isFull(struct Stack* myStack)
{
    return myStack->top == myStack->capacity - 1;
}
int isEmpty(struct Stack* myStack)
{
    return myStack->top == -1;
}
void push(struct Stack* myStack, int item)
{
    if (isFull(myStack))
        return;
    myStack->array[++myStack->top] = item;
    printf("%d pushed to stack\n", item);
}
int pop(struct Stack* myStack)
{
    if (isEmpty(myStack))
        return INT_MIN;
    return myStack->array[myStack->top--];
}
int peek(struct Stack* myStack)
{
    if (isEmpty(myStack))
        return INT_MIN;
    return myStack->array[myStack->top];
}
int main()
{
    struct Stack* myStack = createStack(100);
    printf("\n*********STACK USING ARRAY & AYNAMIC MEMORY ALLOCATION*********\n");
    push(myStack, -10);
    push(myStack, 20);
    push(myStack, 30);

    printf("%d popped from stack\n", pop(myStack));

    return 0;



}

/* write a program to stack using pointer read from the keyboard
#include<stdio.h>
#include<stdlib.h>

#define MAX 50
int size;

// Defining the stack structure
struct stack
{
    int arr[MAX];
    int top;
};

// Initializing the stack(i.e., top=-1)
void init_stk(struct stack *st)
{
    st->top = -1;
}

// Entering the elements into stack
void push(struct stack *st, int num)
{
    if (st->top == size - 1)
    {
        printf("\nStack overflow(i.e., stack full).");
        return;
    }
    st->top++;
    st->arr[st->top] = num;
}

//Deleting an element from the stack.
int pop(struct stack *st)
{
    int num;
    if (st->top == -1)
    {
        printf("\nStack underflow(i.e., stack empty).");
        return NULL;
    }
    num = st->arr[st->top];
    st->top--;
    return num;
}

void display(struct stack *st)
{
    int i;
    for (i = st->top; i >= 0; i--)
        printf("\n%d", st->arr[i]);
}

int main()
{
    int element, opt, val;
    struct stack ptr;
    init_stk(&ptr);
    printf("\nEnter Stack Size :");
    scanf("%d", &size);
    while (1)
    {
      printf("\n*********STACK USING ARRAY & AYNAMIC MEMORY ALLOCATION*********\n");
        printf("\n1.PUSH");
        printf("\n2.POP");
        printf("\n3.DISPLAY");
        printf("\n4.QUIT");
        printf("\n");
        printf("\nEnter your option : ");
        scanf("%d", &opt);
        switch (opt)
        {
        case 1:
            printf("\nEnter the element into stack:");
            scanf("%d", &val);
            push(&ptr, val);
            break;
        case 2:
            element = pop(&ptr);
            printf("\nThe element popped from stack is : %d", element);
            break;
        case 3:
            printf("\nThe current stack elements are:");
            display(&ptr);
            break;
        case 4:
            exit(0);
        default:
            printf("\nEnter correct option!Try again.");
        }
    }
    return (0);
}


*/
/*
 * C Program to Implement Stack Operations using Dynamic Memory
 * Allocation
 */
 /*
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
}*top = NULL;


#define MAX 5

// function prototypes
void push();
void pop();
void empty();
void stack_full();
void stack_count();
void destroy();
void print_top();

void main()
{
    int choice;

    while (1)
    {
        printf("1. push an element \n");
        printf("2. pop an element \n");
        printf("3. check if stack is empty \n");
        printf("4. check if stack is full \n");
        printf("5. count/display elements present in stack \n");
        printf("6. empty and destroy stack \n");
        printf("7. Print top of the stack \n");
        printf("8. exit \n");
        printf("Enter your choice \n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            empty();
            break;
        case 4:
            stack_full();
            break;
        case 5:
            stack_count();
            break;
        case 6:
            destroy();
            break;
        case 7:
            print_top();
            break;
        case 8:
            exit(0);
        default:
            printf("wrong choice\n");
        }
    }
}

// to insert elements in stack
void push()
{
    int val,count;
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));

    count = st_count();
    if (count <= MAX - 1)
    {
        printf("\nEnter value which you want to push into the stack :\n");
        scanf("%d",&val);
        temp->data = val;
        temp->link = top;
        top = temp;
    }
    else
        printf("WARNING: STACK FULL\n");
}

// to delete elements from stack
void pop()
{
    struct node *temp;
    if (top =  = NULL)
        printf("**Stack is empty**\n");
    else
    {
        temp = top;
        printf("Value popped out is %d \n",temp->data);
        top = top->link;
        free(temp);
    }
}

// to check if stack is empty
void empty()
{
    if (top == NULL)
        printf("STACK IS EMPTY\n");
    else
        printf("elements are present, stack is not empty \n");
}

// to check if stack is full
void stack_full()
{
    int count;

    count = st_count();
    if (count =  = MAX)
    {
        printf("stack is full\n");
    }
    else
        printf("stack is not full \n");
}

// to count the number of elements
void stack_count()
{
    int count = 0;
    struct node *temp;

    temp = top;
    while (temp! = NULL)
    {
        printf(" %d\n",temp->data);
        temp = temp->link;
        count++;
    }
    printf("size of stack is %d \n",count);
}

int st_count()
{
    int count = 0;
    struct node *temp;
    temp = top;
    while (temp! = NULL)
    {
        temp = temp->link;
        count++;
    }
    return count;
}

// to empty and destroy the stack
void destroy()
{
    struct node *temp;
    temp = top;
    while (temp! = NULL)
    {
        pop();
        temp = temp->link;
    }
    printf("stack destroyed\n");
}

// to print top element of stack
void print_top()
{
    if (top == NULL)
        printf("\n**Top is not available for an EMPTY stack**\n");
    else
        printf("\nTop of the stack is %d \n",top->data);
}

*/
