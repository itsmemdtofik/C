/**
Given a Linked List of M nodes and a number N, find the value at the Nth node from the end of the Linked List. If there is no Nth node from the end, print -1.

Examples:

Input: 1 -> 2 -> 3 -> 4, N = 3
Output: 2
Explanation: Node 2 is the third node from the end of the linked list.

Input: 35 -> 15 -> 4 -> 20, N = 4
Output: 35
Explanation: Node 35 is the fourth node from the end of the linked list.

Approach: Using Two Pointers - One Pass - O(M) Time and O(1) Space
*/

#include <stdio.h>
#include "Node.h"

/* Function to find the Nth node from the last of a Linked List */
int nthNodeFromSingleLinkedListUsingTwoPointer(const Node *head, const int N) {
    const Node *currentNode = head;
    const Node *nextNode = head;

    for (int i = 1; i < N; i++) {
        nextNode = nextNode->next;

        if (nextNode == NULL) {
            return -1; /* If the nextNode reaches NULL, then it means N > length of Linked List */
        }
    }

    /* Move the currentNode and nextNode pointer by one node until nextNode reaches the last node of the list */
    while (nextNode->next != NULL) {
        nextNode = nextNode->next;
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

    printf("Nth Node from the Last of Linked List is = %d", nthNodeFromSingleLinkedListUsingTwoPointer(head, 4));

    deAllocateMemory(head);

    return EXIT_SUCCESS;
}
