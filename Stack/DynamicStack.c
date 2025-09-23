#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int *arr;
    int capacity;
    int top;
} Stack;

Stack *createStack(const int initialCapacity) {
    Stack *stack = malloc(sizeof(Stack));
    stack->capacity = initialCapacity;
    stack->top = -1;
    stack->arr = malloc(initialCapacity * sizeof(int));
    return stack;
}

/* Dynamic resize function */
bool resizeStack(Stack *stack, const int newCapacity) {
    /* First attempt the reallocation to a temporary pointer */
    int *newStack = realloc(stack->arr, newCapacity * sizeof(int));

    if (newStack == NULL) {
        /* realloc failed - original buffer is still intact at stack->arr */
        fprintf(stderr, "Error: Failed to resize stack to %d\n", newCapacity);
        return false; /* Keep original array and capacity */
    }

    /* realloc succeeded - update the pointer and capacity */
    stack->arr = newStack;
    stack->capacity = newCapacity;
    printf("Stack resized to capacity %d\n", newCapacity);
    return true;
}

bool isEmpty(const Stack *stack) {
    if (stack == NULL) return false;
    return stack->top == -1;
}

bool push(Stack *stack, const int item) {
    if (stack == NULL) return false;

    /* Pre-check and resize if needed */
    if (stack->top + 1 >= stack->capacity) {
        /* Grow by doubling (common strategy) */
        int newCapacity = stack->capacity ? stack->capacity * 2 : 1;
        if (!resizeStack(stack, newCapacity)) {
            return false;
        }
    }
    stack->arr[++stack->top] = item;
    printf("%d pushed to stack (capacity: %d)\n", item, stack->capacity);
    return true;
}

int pop(Stack *stack) {
    if (stack == NULL) return -1;
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        return -1;
    }

    const int item = stack->arr[stack->top--];

    /* Optional: Shrink when only 25% full */
    if (stack->top > 0 && stack->top < stack->capacity / 4) {
        resizeStack(stack, stack->capacity / 2);
    }

    return item;
}

bool isFull(const Stack *stack) {
    if (stack == NULL) return false;
    return stack->top == stack->capacity - 1;
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
    Stack *s = createStack(2); // Start small

    push(s, 10);
    push(s, 20); /* This should trigger resize */
    push(s, 30);
    push(s, 40); /* This should trigger another resize */
    push(s, 50);

    printf("%d popped\n", pop(s));
    printf("%d popped\n", pop(s));

    push(s, 50);
    push(s, 50);
    push(s, 50);
    push(s, 50);

    freeStack(s);
    return 0;
}
