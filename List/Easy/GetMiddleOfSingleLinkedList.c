/**
Given a singly linked list, the task is to find the middle node of the linked list.

If the number of nodes is odd, return the middle node.
If the number of nodes is even, there are two middle nodes, so return the second middle node.
Example:

Input: linked list: 1->2->3->4->5
Output: 3
Explanation: There are 5 nodes in the linked list and there is one middle node whose value is 3.

Input: linked list = 10 -> 20 -> 30 -> 40 -> 50 -> 60
Output: 40
Explanation: There are 6 nodes in the linked list, so we have two middle nodes: 30 and 40, but we will return the second middle node which is 40.

Time Complexity: O(2*n) = O(n) where n is the number of nodes in the linked list.
Auxiliary Space: O(1)

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

/* Helper function to find the length of the linked list */
int getLength(const Node *head) {
    int length = 0;
    while (head) {
        length++;
        head = head->next;
    }
    return length;
}


/* Function to find the middle element of the Single Linked List */
int getMiddle(const Node *head) {
    if (head == NULL) {
        printf("Error: List is empty!");
        return EXIT_FAILURE;
    }
    const int length = getLength(head);
    int middleIndex = length / 2;
    const Node *currentNode = head;
    while (middleIndex--) {
        currentNode = currentNode->next;
    }
    return currentNode->data;
}

/* Create the Single Linked List */
Node *createNode(const int data) {
    Node *newNode = (Node *) malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed!");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void deAllocateMemory(Node *head) {
    Node *currentNode = head;
    while (currentNode) {
        Node *nextNode = currentNode->next;
        free(currentNode);
        currentNode = nextNode;
    }
}

void printList(const Node *head) {
    const Node *currentNode = head;
    while (currentNode) {
        printf("%d -> ", currentNode->data);
        currentNode = currentNode->next;
    }
    printf("NULL\n");
}

int main() {
    Node *head = createNode(10);
    head->next = createNode(20);
    head->next->next = createNode(30);
    head->next->next->next = createNode(40);
    head->next->next->next->next = createNode(50);
    head->next->next->next->next->next = createNode(60);

    printList(head);
    printf("%d\n", getMiddle(head));

    deAllocateMemory(head);

    return 0;
}
