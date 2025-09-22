/**
Given a linked list, we have to reverse the linked list by changing the links between nodes.

Examples:
Input: 1 -> 2 -> 3 -> 4 -> 5
Output: 5 -> 4 -> 3 -> 2 -> 1

Time Complexity: O(n)
Space Complexity: O(1)

*/

#include <stdio.h>
#include "Node.h"

Node *reverseSingleLinkedListUsingIterativeMethod(Node *head) {
    Node *currentNode = head;
    Node *previousNode = NULL;

    /* Swap the nextNode pointer and previousNode pointer */
    while (currentNode != NULL) {
        Node *nextNode = currentNode->next; /* Store the next */
        currentNode->next = previousNode; /* Reverse the current node's next pointer */
        previousNode = currentNode; /* Move the pointer one position ahead */
        currentNode = nextNode;
    }
    head = previousNode;
    return head; /* return the head of reversed linked list */
}

int main() {
    Node *head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    head = reverseSingleLinkedListUsingIterativeMethod(head);

    printList(head);
    deAllocateMemory(head);

    return 0;
}
