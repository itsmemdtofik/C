/**
Given a Doubly Linked List, the task is to reverse the Doubly Linked List.

Examples:

Input: Doubly Linked List = 1 <-> 2 <-> 3 -> NULL
Output: Reversed Doubly Linked List = 3 <-> 2 <-> 1 -> NULL

Approach: Using Recursion - O(n) Time and O(n) Space

*/

#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
} Node;

Node *createNode(const int data) {
    Node *newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void printList(const Node *head) {
    const Node *currentNode = head;
    while (currentNode != NULL) {
        printf("%d -> ", currentNode->data);
        currentNode = currentNode->next;
    }
    printf("NULL\n");
}

void deAllocateMemory(Node *head) {
    Node *currentNode = head;
    while (currentNode) {
        Node *nextNode = currentNode->next;
        free(currentNode);
        currentNode = nextNode;
    }
}

Node *reverseDoublyLinkedListUsingRecursion(Node *head) {
    Node *currentNode = head;
    if (currentNode == NULL) {
        return NULL;
    }

    /* Swap the next and prev pointer */
    Node *previousNode = currentNode->prev;
    currentNode->prev = currentNode->next;
    currentNode->next = previousNode;

    if (currentNode->prev == NULL) {
        return currentNode;
    }

    return reverseDoublyLinkedListUsingRecursion(currentNode->prev);
}

int main() {
    Node *head = createNode(1);
    head->next = createNode(2);
    head->next->prev = head;
    head->next->next = createNode(3);
    head->next->next->prev = head->next;
    head->next->next->next = createNode(4);
    head->next->next->next->prev = head->next->next;

    printf("Original Linked list\n");
    printList(head);
    head = reverseDoublyLinkedListUsingRecursion(head);
    printf("Reversed Linked list\n");
    printList(head);

    deAllocateMemory(head);

    return 0;
}
