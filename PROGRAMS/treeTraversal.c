/*  write a c program to find a number using tree traversal using linked representation */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node
{
 int data;
 struct node *left;
 struct node *right;
};
struct node *tree = NULL;
void inorder(struct node *);
void preorder(struct node *);
void postorder(struct node *);
void main()
{
 int choice, i, number, n;
 struct node *p, *q, *temp;
 printf("Enter the number of Element : ");
 scanf("%d", &n);
 for (i = 0; i < n; i++)
 {
		printf("Enter the  %d data item  :  ", i + 1);
		scanf("%d", &temp->data);
 }
 temp = (struct node *)malloc(sizeof(struct node));
 temp->left = NULL;
 temp->right = NULL;
 if (tree == NULL)
 {

		tree = temp;
 }
 else

 {
		p = q = tree;
 }

 while (q != NULL)
 {
		p = q;
		if (temp->data < p->data)
		{

			q = p->left;
		}
		else
		{

			q = p->right;
		}
 }
 if (temp->data < p->data)
 {

		p->left = temp;
 }
 else
 {

		p->right = temp;
 }

 while (1)
 {

		printf("----------------------------");
		printf("1-Inorder\n 2-Preorder\n 3-Postorder\n 4-Exit\n");
		printf("----------------------------");
		printf("Enter your choice\n");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			preorder(tree);
			break;
		case 2:
			inorder(tree);
			break;
		case 3:
			postorder(tree);
			break;
		case 4:
			exit(0);
			break;
		default:
			printf("invalid value\n");
		}
 }
}

void inorder(struct node *tree)
{
 if (tree != NULL)
 {
		inorder(tree->left);
		printf("%d\t", tree->data);
		inorder(tree->right);
 }
 return;
}

void preorder(struct node *tree)
{
 if (tree != NULL)
 {

		printf("%d\t", tree->data);

		inorder(tree->left);
		inorder(tree->right);
 }
 return;
}

void postorder(struct node *tree)
{
 if (tree != NULL)
 {
		inorder(tree->left);
		inorder(tree->right);
 }
 printf("%d\t", tree->data);

 return;
}
