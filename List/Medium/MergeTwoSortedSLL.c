/**
Merge two sorted linked lists
Given two sorted linked lists consisting of n and m nodes respectively.
The task is to merge both of the lists and return the head of the merged list.

!Approach: Using Iterative Merge - O(n+m) Time and O(1) Space
*/
#include <stdio.h>
#include "Node.h"

/* Merge two sorted lists and return head of merged list */
Node *mergeTwoSortedLists(Node *head1, Node *head2) {
    Node dummy;
    Node *current = &dummy;
    dummy.next = NULL;

    while (head1 != NULL && head2 != NULL) {
        if (head1->data <= head2->data) {
            current->next = head1;
            head1 = head1->next;
        } else {
            current->next = head2;
            head2 = head2->next;
        }
        current = current->next;
    }

    /* append the remaining nodes */
    current->next = (head1 != NULL) ? head1 : head2;
    return dummy.next;
}


int main(void) {
    /* List 1: 1 -> 3 -> 5 */
    Node *l1 = createNode(1);
    l1->next = createNode(3);
    l1->next->next = createNode(5);

    /* List 2: 2 -> 4 -> 6 */
    Node *l2 = createNode(2);
    l2->next = createNode(4);
    l2->next->next = createNode(6);

    printf("List 1: ");
    printList(l1);
    printf("List 2: ");
    printList(l2);

    const Node *merged = mergeTwoSortedLists(l1, l2);
    printf("Merged List: ");
    printList(merged);


    return EXIT_SUCCESS;
}
