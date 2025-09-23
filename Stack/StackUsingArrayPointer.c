#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int *arr; /* dynamic array to hold stack elements */
    int capacity; /* maximum size */
    int top; /* index of top element */
} Stack;

/* Create stack with given capacity */
Stack *createStack(const int capacity) {
    Stack *stack = malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->arr = malloc(capacity * sizeof(int));
    return stack;
}


bool isFull(const Stack *stack) {
    if (stack == NULL) return -1;
    return stack->top == stack->capacity - 1;
}


bool isEmpty(const Stack *stack) {
    if (stack == NULL) return -1;
    return stack->top == -1;
}


void push(Stack *stack, const int item) {
    if (stack == NULL) return;
    if (isFull(stack)) {
        fprintf(stderr, "Stack overflow, cannot push %d\n", item);
        return;
    }
    stack->arr[++stack->top] = item;
    printf("%d pushed to stack\n", item);
}


int pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        return -1;
    }
    return stack->arr[stack->top--];
}


int peek(const Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return -1;
    }
    return stack->arr[stack->top];
}


void freeStack(Stack *stack) {
    if (stack == NULL) return;
    free(stack->arr);
    free(stack);
}


int main() {
    Stack *s = createStack(5);

    push(s, 10);
    push(s, 20);
    push(s, 30);

    printf("%d popped from stack\n", pop(s));
    printf("Top element is %d\n", peek(s));

    push(s, 40);
    push(s, 50);
    push(s, 60); // should trigger overflow

    while (!isEmpty(s)) {
        printf("%d popped from stack\n", pop(s));
    }

    freeStack(s);
    return 0;
}
