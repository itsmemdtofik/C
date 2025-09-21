/**
Given a singly linked list and an integer k, the task is to rotate the linked list to the left by k places.

Examples:

Input: linked list = 10 -> 20 -> 30 -> 40 -> 50, k = 4
Output: 50 -> 10 -> 20 -> 30 -> 40

Explanation: After rotating the linked list to the left by 4 places, the 5th node,
i.e., node 50 becomes the head of the linked list and next pointer of node 50 points to node 10.

Approach: By changing pointer of kth node - O(n) Time and O(1) Space
*/

#include <stdio.h>
#include "Node.h"

Node *rotateSingleLinkedList(Node *head, int K) {
    if (K == 0 || head == NULL) {
        return head;
    }

    Node *currentNode = head;
    int length = 1;

    /* Find the length of the list */
    while (currentNode->next != NULL) {
        currentNode = currentNode->next;
        length += 1;
    }

    /* Modulo K with length of Linked List to hdndle large values of K */
    K = K % length;
    if (K == 0) {
        return head;
    }

    /* Make the Linked List Circular */
    currentNode->next = head;

    /* Traverse the Linked List to find the Kth node */
    currentNode = head;
    for (int i = 1; i < K; i++) {
        currentNode = currentNode->next;
    }

    /* Update the ( K + 1 )th node as the new head */
    head = currentNode->next;

    /* Break the loop by updating next pointer of kth node */
    currentNode->next = NULL;
    return head;
}

int main() {
    Node *head = createNode(10);
    head->next = createNode(20);
    head->next->next = createNode(30);
    head->next->next->next = createNode(40);

    printf("Original Linked list\n");
    printList(head);

    head = rotateSingleLinkedList(head, 6);

    printf("After Rotation Linked list\n");
    printList(head);

    deAllocateMemory(head);

    return EXIT_SUCCESS;
}
