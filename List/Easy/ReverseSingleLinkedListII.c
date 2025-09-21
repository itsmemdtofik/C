/**
Given a linked list, we have to reverse the linked list by changing the links between nodes.

Examples:
Input: 1 -> 2 -> 3 -> 4 -> 5
Output: 5 -> 4 -> 3 -> 2 -> 1

Time Complexity: O(n)
Space Complexity: O(n)

*/

#include <stdio.h>
#include "Node.h"

Node *reverseSingleLinkedListUsingRecursion(Node *head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    /* if we have reached last node or linked list is empty, return head of linked list */
    Node *result = reverseSingleLinkedListUsingRecursion(head->next);

    /* reverse the rest of linked list and put the first element at the end */
    head->next->next = head;

    /* Update next of current head to NULL */
    head->next = NULL;

    /* Return the reserved linked list */
    return result;
}

int main() {
    Node *head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    head = reverseSingleLinkedListUsingRecursion(head);

    printList(head);
    deAllocateMemory(head);

    return 0;
}
