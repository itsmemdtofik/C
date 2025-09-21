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


Node *reverseSingleLinkedListUsingStack(Node *head) {
    /* create a stack to store the nodes */
    Node *stack[100000];
    int top = -1;
    Node *currentNode = head;

    /* push all nodes into stack */
    while (currentNode != NULL) {
        stack[++top] = currentNode;
        currentNode = currentNode->next;
    }

    /* make the last node as new head of the linked list */
    if (top >= 0) {
        head = stack[top];
        currentNode = head;

        /* pop all the nodes and append to the linked list */
        while (top > 0) {
            /* append the top value of stack in list */
            currentNode->next = stack[--top];

            /* move to the next node in the list */
            currentNode = currentNode->next;
        }

        /* update the next pointer of last node of stack to null */
        currentNode->next = NULL;
    }

    return head;
}

int main() {
    Node *head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    head = reverseSingleLinkedListUsingStack(head);

    printList(head);
    deAllocateMemory(head);

    return 0;
}
