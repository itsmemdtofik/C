/**
Given a singly linked list and a key, the task is to delete the last occurrence of that key in the linked list.

Examples:

Input: head: 1 -> 2 -> 3 ->1 -> 4 -> NULL, key = 1
Output: 1 -> 2 -> 3 -> 4 -> NULL

Approach: The idea is to traverse the linked list from beginning to end.
While traversing, keep track of last occurrence key node and previous node of that key.
After traversing the complete list, delete the last occurrence of that key.

Time Complexity: O(n), Traversing over the linked list of size n.
Auxiliary Space: O(1)
*/

#include <stdio.h>
#include "Node.h"

Node *deleteLastOccurrence(Node *head, int key) {
    Node *last = NULL, *lastPrevious = NULL;
    Node *currentNode = head, *previousNode = NULL;

    while (currentNode != NULL) {
        if (currentNode->data == key) {
            lastPrevious = previousNode;
            last = currentNode;
        }
        previousNode = currentNode;
        currentNode = currentNode->next;
    }

    if (last != NULL) {
        if (lastPrevious != NULL) {
            lastPrevious->next = last->next;
        } else {
            head = head->next;
        }
        free(last);
    }

    return head;
}

int main() {
    Node *head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(2);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(2);

    const int key = 2;
    head = deleteLastOccurrence(head, key);
    printList(head);
    return 0;
}
