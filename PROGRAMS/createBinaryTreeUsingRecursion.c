#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *leftchild;
    struct node *rightchild;
};

struct node *root = NULL;
struct node *CreateBinaryTree()
{

    struct node *temp;
    int element;
    temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter the element to inserted( -1 for no data) : \n\n");
    scanf("%d", &element);
    printf("\n\n");
    temp->data = element;
    if (element == -1)
    {
        return NULL;
    }
    printf("Enter the leftchild of %d\n\n", element);
    temp->leftchild = CreateBinaryTree();
    printf("\n\n");
    printf("Enter the rightchild of %d", element);
    printf("\n\n");
    temp->rightchild = CreateBinaryTree();
    return temp;
}
int main()
{
    int n;
    root=CreateBinaryTree();
    for(int i=0; i<n; i++)
    {
        printf("%d",root);
    }
}
