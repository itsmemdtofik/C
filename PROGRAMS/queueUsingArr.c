
/* write a c program to implement queue using static array */

#include <stdio.h>
#include <stdlib.h>
#define n 5
void main()
{
    int queue[n], ch = 1, front = 0, rear = 0, i, j = 1, x = n;
    printf("\t\t\t\t QUEUE USING ARRAY\n\n");
    printf("\n\t\t\t\t --------------------------");
    printf("\n\t\t\t\t 1-Insertion");
    printf("\n\t\t\t\t 2-Deletion");
    printf("\n\t\t\t\t 3-Display");
    printf("\n\t\t\t\t 4-Exit");
    printf("\n\t\t\t\t --------------------------\n\n");
    while (ch)
    {
        printf("\n\t\t\t\t Enter the Choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            if (rear == x)
                printf("\n\t\t\t\t Queue is Full");
            else
            {
                printf("\n\t\t\t\t Enter insertion %d:", j++);
                scanf("%d", &queue[rear++]);
                printf("\n\t\t\t\t --------------------------\n\n");
            }
            break;
        case 2:
            if (front == rear)
            {
                printf("\n\t\t\t\t Queue is empty");
            }
            else
            {
                printf("\n\t\t\t\t Deleted Element is %d", queue[front++]);
                x++;
            }
            break;
        case 3:
            printf("\n\t\t\t\t Queue Elements are:\n ");
            if (front == rear)
                printf("\n\t\t\t\t Queue is Empty");
            else
            {
                for (i = front; i < rear; i++)
                {
                    printf("\n\t\t\t\t %d", queue[i]);
                    printf("\n");
                }
                break;
            case 4:
                exit(0);
            default:
                printf("\t\t\t\tWrong Choice: please see the options");
            }
        }
    }
}
