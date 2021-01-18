/* write a c program to implement queue using static array
#include<stdio.h>
#define QUEUE_SIZE 5
int choice,front,rear,q[100],data;
void insert_rear()
{
	if(rear==QUEUE_SIZE -1)
	{
		printf("queue is full\n");
	}
	else
	{
		rear=rear+1;
		q[rear]=data;
	}
}
void delete_front()
{
	if(front>rear)
	{
		printf("queue is empty\n");
	}
	printf("element deleted %d",q[front++]);
}
void display()
{
	int i;
	if(front>rear)
	{
		printf("queue is empty\n");
	}
	else
	{
		printf("queue is contains\n");
		for(i=front; i<=rear; i++)
			printf("\t %d",q[i]);
	}
}
void main()
{
	front=0;rear=-1;
	while(1)
	{printf("\n*********QUEUE OPERATION USING ARRAY*********\n");
		printf("\n 1 Insert\n 2 delete\n 3 display\n 4 exit\n");
		printf("enter your choice\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:printf("inter the data for storing\n");
			scanf("%d",&data);
			insert_rear();
			break;
			case 2:delete_front();
			break;
			case 3:display();
			break;
			case 4:exit(0);
			break;
			default:printf("invalid\n");
		}
	}
}
*/
/* C program for array implementation of queue using dynamic array
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

// A structure to represent a queue
struct Queue
{
    int front, rear, size;
    unsigned capacity;
    int* array;
};

// function to create a queue
// of given capacity.
// It initializes size of queue as 0
struct Queue* createQueue(unsigned capacity)
{
    struct Queue* queue = (struct Queue*)malloc(
                              sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;

    // This is important, see the enqueue
    queue->rear = capacity - 1;
    queue->array = (int*)malloc(
                       queue->capacity * sizeof(int));
    return queue;
}

// Queue is full when size becomes
// equal to the capacity
int isFull(struct Queue* queue)
{
    return (queue->size == queue->capacity);
}

// Queue is empty when size is 0
int isEmpty(struct Queue* queue)
{
    return (queue->size == 0);
}

// Function to add an item to the queue.
// It changes rear and size
void enqueue(struct Queue* queue, int item)
{
    if (isFull(queue))
        return;
    queue->rear = (queue->rear + 1)
                  % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size = queue->size + 1;
    printf("%d enqueued to queue\n", item);
}

// Function to remove an item from queue.
// It changes front and size
int dequeue(struct Queue* queue)
{
    if (isEmpty(queue))
        return INT_MIN;
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1)
                   % queue->capacity;
    queue->size = queue->size - 1;
    return item;
}

// Function to get front of queue
int front(struct Queue* queue)
{
    if (isEmpty(queue))
        return INT_MIN;
    return queue->array[queue->front];
}

// Function to get rear of queue
int rear(struct Queue* queue)
{
    if (isEmpty(queue))
        return INT_MIN;
    return queue->array[queue->rear];
}

// Driver program to test above functions./
int main()
{
    struct Queue* queue = createQueue(1000);

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);

    printf("%d dequeued from queue\n\n",
           dequeue(queue));

    printf("Front item is %d\n", front(queue));
    printf("Rear item is %d\n", rear(queue));

    return 0;

}


*/
/** queue using static array another type */
#include <stdio.h>
#define CAPACITY 5;
int queue['CAPACITY'];
int front = 0;
int rear = 0;
int item;

void inserRear()
{
    if (rear == 'CAPACITY')
    {
        printf("Queue is full");
    }
    else
    {

        queue[rear] = item;
        rear++;
    }
}

void deleteFront()
{
    if (front == rear)
    {
        printf("Queue is empty");
    }
    else
    {
        printf("Deleted item is=%d", queue[front]);
        for (int i = 0; i < rear; i++)
        {
            queue[i] = queue[i + 1];
        }
        rear--;
    }
}
void display()
{

    if (front == rear)
    {
        printf("Queue is empty");
    }
    else
    {
        printf("Queue contains item");
        for (int i = 0; i < rear; i++)
        {

            printf("%d", queue[i]);
        }
    }
}
