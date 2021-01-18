/** write a program to implement doubly linked list */

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* leftlink;
    struct node* rightlink;



};

struct node* root=NULL;
struct node* leftlink=NULL;
struct node* rightlink=NULL;
int len;
int count;

void addAtBegin(void);
void addAtBetween(void);
void addAtEnd(void);
void deleteAtBegin(void);
void deleteAtEnd(void);
void addAtBetween();
void display(void);
int length();



/**Inserting node from begining */
void addAtBegin()
{

    struct node* temp;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("\n\t\t\t\tEnter the Data : ");
    scanf("\n\t\t\t\t%d",&temp->data);
    temp->leftlink=NULL;
    temp->rightlink=NULL;

    if(root==NULL)
    {
        root=temp;
    }
    else
    {

        temp->rightlink=root;
        root->leftlink =temp;
        root=temp;
    }


}

/**Adding in between the node */
void addAtBetween()
{
    int loc=0,i=1;
    int len=length();
    printf("\n\t\t\t\tEnter Location to add Between the Node : ");
    scanf("%d",&loc);
    if(loc>len)
    {
        printf("\n\t\t\t\tInvalid Operation\n\n");
        printf("\n\t\t\t\tList contains only %d nodes",len);
        printf("\n\n");
    }
    else
    {
        struct node* temp;
        struct node* p;
        p=root;
        temp=(struct node*)malloc(sizeof(struct node));
        printf("\n\t\t\t\tEnter data : ");
        scanf("\n\t\t\t\t%d",&temp->data);
        temp->leftlink=NULL;
        temp->rightlink=NULL;
        while(i<loc)
        {
            p=p->rightlink;
            i++;
        }
        temp->rightlink=p->rightlink;
        p->rightlink->leftlink=temp;
        temp->leftlink=p;
        p->rightlink=temp;
    }
}

/**Inserting from end */
void addAtEnd()
{
    struct node* temp;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("\n\t\t\t\tEnter the Data : ");
    scanf("\n\t\t\t\t%d",&temp->data);
    temp->leftlink=NULL;
    temp->rightlink=NULL;

    if(root==NULL)
    {

        root=temp;
    }
    else
    {

        struct node* p;
        p=root;

        while(p->rightlink!=NULL)
        {

            p=p->rightlink;
        }
        p->rightlink=temp;
        temp->leftlink=p;


    }

}




/**Deleting from Begin */
void deleteAtBegin()
{

    struct node* temp;
    
    temp=root;
    if(root==NULL)
    {
        printf("\n\t\t\t\tList is empty\n\n" );
    }
    else
    {


        root=temp;
        root=root->rightlink;
        root->leftlink=NULL;
        printf("\n\t\t\t\t->%d data is deleted",temp->data);
        printf("\n\n");
        free(temp);
    }

}


/**Delete from between */
void deleteAtBetween()
{

    struct node *p, *temp;
    int val;
    printf("\n\t\t\t\tEnter the value : ");
    scanf("\n\t\t\t\t%d",&val);
    printf("\n\n");

    temp = root;
    while(temp -> data != val)
        temp = temp -> rightlink;
    if(temp -> rightlink == NULL)
    {
        printf("\n\t\t\t\tCan't delete\n\n");
    }
    else if(temp -> rightlink -> rightlink == NULL)
    {
        temp ->rightlink = NULL;
        printf("\n\t\t\t\t %dNode Deleted",temp->data);
        printf("\n\n");
    }
    else
    {
        p = temp -> rightlink;
        temp -> rightlink = p -> rightlink;
        p -> rightlink -> leftlink = temp;
        free(p);
        printf("\n\t\t\t\t%d Node Deleted",temp->data);
        printf("\n\n");
    }


}


/**Delete from end */
void deleteAtEnd(void)
{
    struct node *temp;
    if(root == NULL)

    {
        printf("\n\t\t\t\tLIST IS EMPTY\n\n");
    }
    else if(root->rightlink == NULL)
    {
        root = NULL;
        free(root);
        printf("\n\t\t\t\t ->%d Node is Deleted!",temp->data);
        printf("\n\n");
    }

    else
    {
        temp = root;
        if(temp->rightlink != NULL)
        {
            temp = temp -> rightlink;
        }
        temp -> leftlink -> rightlink = NULL;
        printf("\n\t\t\t\t->%d Node is Deleted!",temp->data);
        printf("\n\n");
        free(temp);



    }
}


/**Display the data */
void display(void)
{

    struct node* temp;
    temp=root;//it will store from root
    if(temp==NULL)
    {
        printf("\n\t\t\t\tList is empty\n\n");
    }
    else
    {
        while(temp!=NULL)
        {
            printf("\n\t\t\t\t %d->",temp->data);
            printf("\n\n");
            temp=temp->rightlink;
        }


    }



}
int length()
{

    struct node* temp;
    temp=root;
    if(temp==NULL)
    {
        printf("\n\t\t\t\tList is empty\n\n");
    }
    else
    {
        while(temp!=NULL)
        {

            count++;
            temp=temp->rightlink;
        }

        return count;



    }
}
int main(void)
{

    int choice;
    printf("\n\t\t-------------------------------------------\n\n");
    printf("\n\t\t\tDoubly LinkedList Operations\n\n");
    printf("\n\t\t-------------------------------------------\n\n");
    while(1)
    {

        printf("\n\t\t\t\t 1-addAtBegin");
        printf("\n\t\t\t\t 2-addAtBetween");
        printf("\n\t\t\t\t 3-addAtEnd");
        printf("\n\t\t\t\t 4-deleteAtBegin");
        printf("\n\t\t\t\t 5-deleteAtBetween");
        printf("\n\t\t\t\t 6-deleteAtEnd");
        printf("\n\t\t\t\t 7-display");
        printf("\n\t\t\t\t 8-length");
        printf("\n\t\t\t\t 9-Exit\n\n");
        printf("\n\t\t-------------------------------------------\n\n");
        printf("\n\t\t\t\tEnter the choice : ");
        scanf("%d",&choice);

        switch(choice)
        {

        case 1:
            addAtBegin();
            break;
        case 2:
            addAtBetween();
            break;
        case 3:
            addAtEnd();
            break;
        case 4:
            deleteAtBegin();
            break;
        case 5:
            deleteAtBetween();
            break;

        case 6:
            deleteAtEnd();
            break;
        case 7:
            display();
            break;
        case 8:
            len=length();
            printf("\n\t\t\t\tLength is = %d",len);
            printf("\n\n");
            break;
        case 9:
            exit(0);
            break;
        default:
            printf("\n\t\t\t\tInvalid choice ");
            break;

        }


    }


}




