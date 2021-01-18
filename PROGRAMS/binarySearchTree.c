#include <stdio.h>
#include <stdlib.h>

struct tnode
{
    int data;
    struct tnode *right;
    struct tnode *left;
};

struct tnode *CreateBST(struct tnode *, int);
void Inorder(struct tnode *);
void Preorder(struct tnode *);
void Postorder(struct tnode *);

int main()
{
    struct tnode *root = NULL;
    int choice, item, n, i;
    printf("\n\t\t\t----------------------------------------------\n\n");
    printf("\n\t\t\t\tBINARY SEARCH TREE OPERATIONS\n\n");
    printf("\n\t\t\t----------------------------------------------\n\n");
    do
    {

        printf("\n\t\t\t\t 1. CREATION OF BINARY TREE\n");
        printf("\n\t\t\t\t 2. TRAVERSE IN INORDER\n");
        printf("\n\t\t\t\t 3. TRAVERSE IN PREORDER\n");
        printf("\n\t\t\t\t 4. TRAVERSE IN POSTORDER\n");
        printf("\n\t\t\t\t 5. Exit\n");
        printf("\n\t\t\t----------------------------------------------\n\n");
        printf("\n\t\t\t\t Enter Your Choice : ");
        scanf("\n\t\t\t\t%d", &choice);
        printf("\n\n");

        switch (choice)
        {
        case 1:
            root = NULL;
            printf("\n\t\t\t\tEnter the size of node : ");
            scanf("\n\t\t\t\t%d", &n);
            printf("\n\n");
            for (i = 1; i <= n; i++)
            {
                printf("\n\t\t\t\tEnter data for node %d : ", i);
                scanf("\n\t\t\t\t%d", &item);
                printf("\n\n");
                root = CreateBST(root, item);
            }
            printf("\n\t\t\t----------------------------------------------\n\n");
            printf("\n\t\t\t\tBST with %d nodes is ready to Use : ", n);
            printf("\n\n");
            break;
        case 2:
            printf("\n\t\t\t\tBST Traversal in INORDER ");
            printf("\n\n");
            Inorder(root);
            break;
        case 3:
            printf("\n\t\t\t\tBST Traversal in PREORDER \n\n");
            Preorder(root);
            break;
        case 4:
            printf("\n\t\t\t\tBST Traversal in POSTORDER \n\n");
            Postorder(root);
            break;
        case 5:
            printf("\n\t\t\t\t Terminating \n\n");
            break;
        default:
            printf("\n\t\t\t\tnInvalid Option !!! Try Again !! \n\n");
            break;
        }
    } while (choice != 5);
    return 0;
}

struct tnode *CreateBST(struct tnode *root, int item)
{
    if (root == NULL)
    {
        root = (struct tnode *)malloc(sizeof(struct tnode));
        root->left = root->right = NULL;
        root->data = item;
        return root;
    }
    else
    {
        if (item < root->data)
            root->left = CreateBST(root->left, item);
        else if (item > root->data)
            root->right = CreateBST(root->right, item);
        else
            printf("\n\t\t\t\t Duplicate Element !! Not Allowed !!!\n\n");

        return (root);
    }
}

void Inorder(struct tnode *root)
{
    if (root != NULL)
    {
        Inorder(root->left);
        printf("\n\t\t\t\t %d ", root->data);
        printf("\n\n");
        Inorder(root->right);
    }
}

void Preorder(struct tnode *root)
{
    if (root != NULL)
    {
        printf("\n\t\t\t\t %d ", root->data);
        printf("\n\n");
        Preorder(root->left);
        Preorder(root->right);
    }
}

void Postorder(struct tnode *root)
{
    if (root != NULL)
    {
        Postorder(root->left);
        Postorder(root->right);
        printf("\n\t\t\t\t %d ", root->data);
        printf("\n\n");
    }
}

/**

Binary Search Tree Operations Output :

1. Creation of BST
2. Traverse in Inorder
3. Traverse in Preorder
4. Traverse in Postorder
5. Exit

Enter Choice : 1


BST for How Many Nodes ? 5

Enter data for node 1 : 10

Enter data for node 2 : 2

Enter data for node 3 : 8

Enter data for node 4 : 15

Enter data for node 5 : 6

BST with 5 nodes is ready to Use!!


Binary Search Tree Operations

1. Creation of BST
2. Traverse in Inorder
3. Traverse in Preorder
4. Traverse in Postorder
5. Exit

Enter Choice : 2

BST Traversal in INORDER
2 6 8 10 15

Binary Search Tree Operations

1. Creation of BST
2. Traverse in Inorder
3. Traverse in Preorder
4. Traverse in Postorder
5. Exit

Enter Choice : 3

BST Traversal in PREORDER
10 2 8 6 15

Binary Search Tree Operations

1. Creation of BST
2. Traverse in Inorder
3. Traverse in Preorder
4. Traverse in Postorder
5. Exit

Enter Choice : 4

BST Traversal in POSTORDER
6 8 2 15 10

*/

/* #include <stdio.h>
#include <stdlib.h>

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct node
{
    int data;
    struct node *left;
    struct node *right;
};

/* Function to get the count of leaf nodes in a binary tree*/
unsigned int getLeafCount(struct node *node)
{
    if (node == NULL)
        return 0;
    if (node->left == NULL && node->right == NULL)
        return 1;
    else
        return getLeafCount(node->left) +
               getLeafCount(node->right);
}

/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */
struct node *newNode(int data)
{
    struct node *node = (struct node *)
        malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return (node);
}

/*Driver program to test above functions*/
int main()
{
    /*create a tree*/
    struct node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    /*get leaf count of the above created tree*/
    printf("Leaf count of the tree is %d", getLeafCount(root));

    getchar();
    return 0;
}
* /
