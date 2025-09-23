#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct QueueUsingArrayPointer {
    int *nums; /* For Storage */
    int capacity; /* Maximum Size */
    int front; /* Index of front element */
    int rear; /* Index of the last element */
    int size; /* Current size */
} Queue;

/* Create a Queue with given capacity */
Queue *createQueue(const int capacity) {
    Queue *queue = malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->front = 0;
    queue->rear = capacity - 1; /* Important tricks*/
    queue->size = 0;
    queue->nums = (int *) malloc(capacity * sizeof(int));
    return queue;
}

bool isFull(const Queue *queue) {
    if (queue == NULL) {
        printf("Memory is not allocated");
        return -1;
    }
    return (queue->size == queue->capacity);
}

bool isEmpty(const Queue *queue) {
    if (queue == NULL) {
        printf("Memory is not allocated");
        return -1;
    }
    return (queue->size == 0);
}

void enqueue(Queue *queue, const int items) {
    if (isFull(queue)) {
        printf("Queue overflow, can not enqueue %d\n", items);
        return;
    }
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->nums[queue->rear] = items;
    queue->size++;
    printf("%d enqueued to queue\n", items);
}

int dequeue(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue underflow\n");
        return -1;
    }
    const int items = queue->nums[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;
    return items;
}

int peekFront(const Queue *queue) {
    if (isEmpty(queue)) return -1;
    return queue->nums[queue->front];
}

int peekRear(const Queue *queue) {
    if (isEmpty(queue)) return -1;
    return queue->nums[queue->rear];
}

void freeQueue(Queue *queue) {
    if (queue == NULL) {
        printf("Memory is not allocated");
        return;
    }
    free(queue->nums);
    free(queue);
}

int main(int argc, char *argv[]) {
    Queue *q = createQueue(5);

    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);


    printf("Front element: %d\n", peekFront(q));
    printf("Rear element:  %d\n", peekRear(q));

    printf("%d dequeued from queue\n", dequeue(q));
    printf("%d dequeued from queue\n", dequeue(q));

    enqueue(q, 50);
    enqueue(q, 60);

    printf("Front element: %d\n", peekFront(q));
    printf("Rear element:  %d\n", peekRear(q));

    freeQueue(q);
}
