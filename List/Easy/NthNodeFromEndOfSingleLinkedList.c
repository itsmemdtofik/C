/**
Given a Linked List of M nodes and a number N, find the value at the Nth node from the end of the Linked List. If there is no Nth node from the end, print -1.

Examples:

Input: 1 -> 2 -> 3 -> 4, N = 3
Output: 2
Explanation: Node 2 is the third node from the end of the linked list.

Input: 35 -> 15 -> 4 -> 20, N = 4
Output: 35
Explanation: Node 35 is the fourth node from the end of the linked list.

Approach: By Finding the length of list - Two Pass - O(M) Time and O(1) Space
*/

#include <stdio.h>
#include "Node.h"

/* Function to find the Nth node from the last of a Linked List */
int nthNodeFromSingleLinkedList(const Node *head, int N) {
    int length = 0;
    const Node *currentNode = head;
    while (currentNode != NULL) {
        currentNode = currentNode->next;
        length += 1;
    }

    if (length < N) {
        return -1;
    }

    /* Get the (len - N + 1)th node from the beginning */
    currentNode = head;
    for (int i = 1; i < length - N + 1; i++) {
        currentNode = currentNode->next;
    }

    return currentNode->data;
}

int main() {
    Node *head = createNode(35);
    head->next = createNode(15);
    head->next->next = createNode(4);
    head->next->next->next = createNode(20);

    printf("Original Linked list\n");
    printList(head);

    printf("Nth Node from the Last of Linked List is = %d", nthNodeFromSingleLinkedList(head, 4));

    deAllocateMemory(head);

    return EXIT_SUCCESS;
}
