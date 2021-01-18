//Add  integer using linked list

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct list_node *list_pointer;
struct list_node
{
    int data;
    list_pointer link;
};
void Insert_Front(list_pointer *first, int data)
{
    list_pointer n1, temp, last;
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
void Insert_Rear(list_pointer *first, int data)
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
void display(list_pointer first)
{
    if (first == NULL)
    {
        printf("List is empty\n");
        return;
    }
    while (first != NULL)
    {
        printf("%d", first->data);
        first = first->link;
    }
}
list_pointer AddLongInteger(list_pointer A, list_pointer B)
{
    int digit, sum, carry;
    list_pointer L3 = NULL;
    carry = 0;
    while (A || B)
    {
        sum = (A ? A->data : 0) + (B ? B->data : 0) + carry;
        digit = sum % 10;
        carry = sum / 10;
        Insert_Front(&L3, digit);
        if (A)
            A = A->link;
        if (B)
            B = B->link;
    }
    if (carry)
        Insert_Front(&L3, carry);
    return L3;
}
int main()
{
    list_pointer L1 = NULL, L2 = NULL, L3 = NULL;
    char s[20];
    int choice, i, len;
    printf("Enter the first number\n");
    fflush(stdin);
    scanf("%s", s);
    len = strlen(s);
    for (i = len - 1; i >= 0; i--)
        Insert_Rear(&L1, s[i] - '0');
    printf("Enter the second number\n");
    fflush(stdin);
    scanf("%s", s);
    len = strlen(s);
    for (i = len - 1; i >= 0; i--)
        Insert_Rear(&L2, s[i] - '0');
    L3 = AddLongInteger(L1, L2);
    printf("\nThe sum of the two numbers is: \t\n");
    display(L3);
}
