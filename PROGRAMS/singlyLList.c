/* Single linked list operation*/

#include<stdio.h>
#include<stdlib.h>

struct node
{

    int data;
    struct node* link;


};

struct node* root=NULL;
struct node* temp;
int data;
int position;
int len;

void addAtBegin(void);
void addAtMiddle(int data, int position);
void addAtEnd(void);
void DeleteAtFirst(void);
void DeleteAtMiddle(void);
void DeleteAtEnd(void);
void DeleteAll(void);
void ReverseList(void);
int Length();
void Display(void);


int main(void)
{
    int choice;
    printf("----------------Single linked list operations----------------\n\n");
    while(1)
    {


        printf("\n 1-addAtBegin\n");
        printf("\n 2-addAtMiddle\n");
        printf("\n 3-addAtEnd\n");
        printf("\n 4-DeleteAtFirst\n");
        printf("\n 5-DeleteAtMiddle\n");
        printf("\n 6-DeleteAtEnd\n");
        printf("\n 7-DeleteAll");
        printf("\n 8-ReverseList");
        printf("\n 9-Length\n");
        printf("\n 10-Display\n");
        printf("\n 11-Exit\n");
        printf("\n Enter your choice : ");
        scanf("%d",&choice);

        switch(choice)
        {

        case 1:
            addAtBegin();
            break;
        case 2:
            addAtMiddle(data, position);
            break;
        case 3:
            addAtEnd();
            break;
        case 4:
            DeleteAtFirst();
            break;
        case 5:
            DeleteAtMiddle();
            break;
        case 6:
            DeleteAtEnd();
            break;
        case 7:
            DeleteAll();
            break;
        case 8:
            ReverseList();
            break;

        case 9:
            len= Length();
            printf("Length is =%d\n\n",len);
            break;
        case 10:
            Display();
            break;
        case 11:
            exit(0);
            break;
        default:
            printf("Invalid choice...\n\n");
            break;



        }

    }
}

/* Inserting node from Begining */

void addAtBegin(void)
{

    struct node* temp;


    temp=(struct node*)malloc(sizeof(struct node));
    printf("Enter the data : ");
    scanf("%d",&temp->data);
    temp->link=NULL;
    if(root==NULL)
    {
        root=temp;
    }
    else
    {
        temp->link=root;
        root=temp;
    }
}

/* Inserting node from middle */

void addAtMiddle(int data, int position)
{


    int i;
    struct node *newNode, *temp;

    newNode = (struct node*)malloc(sizeof(struct node));
    printf("Enter the position to insert data the data : ");
    scanf("%d",&position);
    printf("Enter the data : ");
    scanf("%d",&data);

    if(newNode == NULL)
    {
        printf("Unable to allocate memory.");
    }
    else
    {
        newNode->data = data; // Link data part
        newNode->link = NULL;

        temp = root;

        /*
         * Traverse to the n-1 position
         */
        for(i=2; i<=position-1; i++)
        {
            temp = temp->link;

            if(temp == NULL)
                break;
        }

        if(temp != NULL)
        {
            /* Link address part of new node */
            newNode->link = temp->link;

            /* Link address part of n-1 node */
            temp->link = newNode;

            printf("DATA INSERTED SUCCESSFULLY\n");
        }
        else
        {
            printf("UNABLE TO INSERT DATA AT THE GIVEN POSITION\n");
        }
    }

}

/* Inserting node from middle */

void addAtEnd()
{

    struct node* temp;

    temp=(struct node*)malloc(sizeof(struct node));
    printf("Enter the node data : ");
    scanf("%d",&temp->data);
    printf("\n\n");
    temp->link=NULL;
    if(root==NULL)
    {
        printf("List is empty\n\n");
        root=temp;
    }
    else
    {
        struct node* p;
        p=root;
        while(p->link!=NULL)
        {
            p=p->link;
        }
        p->link=temp;

    }


}



void DeleteAtFirst()
{
    struct node* temp;
    int location;
    printf("Enter location to delete : ");
    scanf("%d",&location);
    if(location > Length())
    {
        printf("Invalid Message...\n\n");
    }
    else if(location==1)
    {
        temp=root; //starting from root
        root=temp->link;
        temp->link=NULL;
        free(temp);

    }
}

/* Delete from Middle */
void DeleteAtMiddle(void)
{

    int i;
    int position;
    struct node *toDelete, *prevNode;

    if(root == NULL)
    {
        printf("List is already empty.");
    }
    else
    {
        toDelete = root;
        prevNode = root;

        for(i=2; i<=position; i++)
        {
            prevNode = toDelete;
            toDelete = toDelete->link;

            if(toDelete == NULL)
                break;
        }

        if(toDelete != NULL)
        {
            if(toDelete == root)
                root = root->link;

            prevNode->link = toDelete->link;
            toDelete->link = NULL;

            /* Delete nth node */
            free(toDelete);

            printf("SUCCESSFULLY DELETED NODE FROM MIDDLE OF LIST\n");
        }
        else
        {
            printf("Invalid position unable to delete.");
        }
    }

}

/*Delete from End */
void DeleteAtEnd(void)
{

    struct node *toDelete, *LastNode;

    if(root == NULL)
    {
        printf("List is already empty.");
    }
    else
    {
        toDelete = root;
        LastNode = root;

        /* Traverse to the last node of the list */
        while(toDelete->link != NULL)
        {
            LastNode = toDelete;
            toDelete = toDelete->link;
        }

        if(toDelete == root)
        {
            root = NULL;
        }
        else
        {
            /* Disconnect link of second last node with last node */
            LastNode->link = NULL;
        }

        /* Delete the last node */
        free(toDelete);

        printf("SUCCESSFULLY DELETED LAST NODE OF LIST\n");
    }

}

/*Delete All Nodes */
void DeleteAll()
{

    struct node *temp;

    while(root != NULL)
    {
        temp = root;
        root = root->link;

        free(temp);
    }

    printf("SUCCESSFULLY DELETED ALL NODES OF LINKED LIST\n");
}


/*Reverse the List */
void ReverseList()
{
    struct node *prevNode, *curNode;

    if(root != NULL)
    {
        prevNode = root;
        curNode = root->link;
        root = root->link;

        prevNode->link = NULL; // Make first node as last node

        while(root != NULL)
        {
            root = root->link;
            curNode->link = prevNode;

            prevNode = curNode;
            curNode = root;
        }

        root = prevNode; // Make last node as head

        printf("SUCCESSFULLY REVERSED LIST\n");
    }


}


/* Display the Data or Node */
void Display()
{

    struct node* temp;
    temp=root; //starting from root
    if(temp==NULL)
    {
        printf("List is empty\n\n");
    }
    else
    {

        while(temp!=NULL)
        {

            printf("%d\t",temp->data);
            temp=temp->link;
        }
        printf("\n\n");

    }

}


/* Finding length of node */
int Length()
{
    struct node* temp;
    int count=0;
    temp=root; //we are counting from root node
    while(temp!=NULL)
    {

        count++;
        temp=temp->link;

    }
    return count;
}















