#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int coef;
    int expon;
    struct node *next;
} NODE;
NODE *insert_order(NODE *first, int coe, int expo)
{
    NODE *n = (NODE *)malloc(sizeof(NODE));
    n->coef = coe;
    n->expon = expo;
    n->next = NULL;
    if (first == NULL)
        return n;
    if (expo > first->expon)
    {
        n->next = first;
        return n;
    }
    NODE *prev = NULL, *cur = first;
    while (cur != NULL && expo < cur->expon)
    {
        prev = cur;
        cur = cur->next;
    }
    prev->next = n;
    n->next = cur;
    return first;
}
NODE *add_poly(NODE *L1, NODE *L2)
{
    NODE *L3 = NULL;
    int c, sum;
    while (L1 && L2)
    {
        if (L1->expon == L2->expon)
            c = 0;
        else if (L1->expon > L2->expon)
            c = 1;
        else
            c = 2;
        switch (c)
        {
        case 0:
            sum = L1->coef + L2->coef;
            if (sum)
                L3 = insert_order(L3, sum, L1->expon);
            L1 = L1->next;
            L2 = L2->next;
            break;
        case 1:
            L3 = insert_order(L3, L1->coef, L1->expon);
            L1 = L1->next;
            break;
        case 2:
            L3 = insert_order(L3, L2->coef, L2->expon);
            L2 = L2->next;
            break;
        }
    }
    while (L1)
    {
        L3 = insert_order(L3, L1->coef, L1->expon);
        L1 = L1->next;
    }
    while (L2)
    {
        L3 = insert_order(L3, L2->coef, L2->expon);
        L2 = L2->next;
    }
    return L3;
}
void display(NODE *first)
{
    if (first == NULL)
    {
        printf("List is empty\n");
        return;
    }
    while (first != NULL)
    {
        printf("%dX%d", first->coef, first->expon);
        if (first->next != NULL)
            printf("+");
        first = first->next;
    }
}
int main()
{
    NODE *first = NULL;
    NODE *L1 = NULL, *L2 = NULL, *L3;
    int choice, c, e;
    do
    {
        printf("\n1.create\n2.add_poly\n3.exit\n");
        printf("Enter the option\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            while (1)
            {
                printf("Enter the coefficient \n");
                scanf("%d", &c);
                if (c == -999)
                    break;
                printf("Enter the exponent\n");
                scanf("%d", &e);
                L1 = insert_order(L1, c, e);
            }
            display(L1);
            while (1)
            {
                printf("\nEnter the coefficient \n");
                scanf("%d", &c);
                if (c == -999)
                    break;
                printf("Enter the exponent\n");
                scanf("%d", &e);
                L2 = insert_order(L2, c, e);
            }
            display(L2);
            break;
        case 2:
            L3 = add_poly(L1, L2);
            display(L3);
            break;
        }
    } while (choice < 3);
}