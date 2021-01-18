/* Circular Linked List*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct list_node *list_pointer;
struct list_node
{
    int data;
    list_pointer link;
};
void insert_Front(list_pointer *last, int data)
{
    list_pointer new_node;
    new_node = (list_pointer)malloc(sizeof(struct list_node));
    new_node->data = data;
    new_node->link = NULL;
    if (*last == NULL)
    {
        new_node->link = new_node;
        *last = new_node;
        return;
    }
    new_node->link = (*last)->link;
    (*last)->link = new_node;
}
void insert_Rear(list_pointer *last, int data)
{
    {
        list_pointer new_node;
        new_node = (list_pointer)malloc(sizeof(struct list_node));
        new_node->data = data;
        new_node->link = NULL;
        if (*last == NULL)
        {
            new_node->link = new_node;
            *last = new_node;
            return;
        }
        new_node->link = (*last)->link;
        (*last)->link = new_node;
        *last = new_node;
    }
}
void delete_front(list_pointer *last)
{
    list_pointer temp;
    if (*last == NULL)
    {
        printf("List is empty\n");
        return;
    }
    if ((*last)->link == *last)
    {
        printf("The element deleted is %d\t", (*last)->data);
        *last = NULL;
        return;
    }
    temp = (*last)->link;
    (*last)->link = temp->link;
    printf("The element deleted is %d\t", temp->data);
    free(temp);
}
void delete_rear(list_pointer *last)
{
    list_pointer temp, x;
    if (*last == NULL)
    {
        printf("List is empty\n");
        return;
    }
    if ((*last)->link == *last)
    {
        printf("The element deleted is %d\t", (*last)->data);
        *last = NULL;
        return;
    }
    temp = (*last)->link;
    while (temp->link != *last)
        temp = temp->link;
    temp->link = (*last)->link;
    printf("The element deleted is %d\t", (*last)->data);
    free(*last);
    *last = temp;
}
void display(list_pointer last)
{
    list_pointer x;
    if (last == NULL)
    {
        printf("List is empty\n");
        return;
    }
    x = last->link;
    while (x != last)
    {
        printf("%d\t", x->data);
        x = x->link;
    }
    printf("%d\t", x->data);
}
int main()
{
    list_pointer first = NULL;
    int choice, element;
    do
    {
        printf("\n1.Insert_Front\n2.Insert_Rear\n3.Display\n4.delete_Front\n5.delete_Rear\n6.exit\n ");
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
