//Singly linked list without return type.
#include <stdio.h>
#include <stdlib.h>
typedef struct list_node *list_pointer;
struct list_node
{
    int data;
    list_pointer link;
};
void insert_Front(list_pointer *first, int data)
{
    list_pointer n1;
    n1 = (list_pointer)malloc(sizeof(struct list_node));
    n1->data = data;
    n1->link = NULL;
    if (*first == NULL)
        *first = n1;
    else
    {
        n1->link = *first;
        *first = n1;
    }
}
void insert_Rear(list_pointer *first, int data)
{
    list_pointer n1, temp, last;
    n1 = (list_pointer)malloc(sizeof(struct list_node));
    n1->data = data;
    n1->link = NULL;
    if (*first == NULL)
        *first = n1;
    else
    {
        last = *first;
        while ((last)->link != NULL)
            last = (last)->link;
        (last)->link = n1;
    }
}
void delete_front(list_pointer *first)
{
    list_pointer temp;
    if (*first == NULL)
    {
        printf("List is empty\n");
        return;
    }
    /* if((*first)->link==NULL)
{
printf("The element deleted is %d\t",(*first)->data);
*first=NULL;
return;
}*/
    //not necessarily required
    temp = (*first);
    *first = (*first)->link;
    printf("The element deleted is %d\t", temp->data);
    free(temp);
}
void delete_rear(list_pointer *first)
{
    list_pointer temp, prev;
    if (*first == NULL)
    {
        printf("List is empty\n");
        return;
    }
    //has to handle one node case.
    if ((*first)->link == NULL)
    {
        printf("The element deleted is %d\t", (*first)->data);
        *first = NULL;
        return;
    }
    temp = (*first);
    while (temp->link != NULL)
    {
        prev = temp;
        temp = temp->link;
    }
    printf("The element deleted is %d\t", temp->data);
    prev->link = NULL;
    free(temp);
}
void display(list_pointer first)
{
    if (first == NULL)
    {
        printf("List is empty\n");
        return;
    }
    while (first != NULL)
    {
        printf("%d\t", first->data);
        first = first->link;
    }
}
int main()
{
    list_pointer first = NULL;
    int choice, element;
    do
    {
        printf("-----------------------------------\n");
        printf("\n1.Insert_Front\n2.Insert_Rear\n3.Display\n4.delete_Front\n5.delete_Rear\n6.exit\n ");
        printf("-----------------------------------\n");
        printf("Enter the option\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the element to be inserted\n");
            scanf("%d", &element);
            insert_Front(&first, element);
            break;
        case 2:
            printf("Enter the element to be inserted\n");
            scanf("%d", &element);
            insert_Rear(&first, element);
            break;
        case 3:
            printf("The elements of the list are\n");
            display(first);
            break;
        case 4:
            delete_front(&first);
            break;
        case 5:
            delete_rear(&first);
            break;
        }
    } while (choice < 6);
}
