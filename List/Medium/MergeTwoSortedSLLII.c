#include <stdio.h>
#include "Node.h"

Node *mergeTwoSortedSingleLinkedList(Node *head1, Node *head2) {
    if (head1 == NULL) {
        return head2;
    } else if (head2 == NULL) {
        return head1;
    }

    Node *mergedHead = NULL;
    if (head1->data <= head2->data) {
        mergedHead = head1;
        head1 = head1->next;
    } else {
        mergedHead = head2;
        head2 = head2->next;
    }

    Node *mergedTail = mergedHead;
    while (head1 != NULL && head2 != NULL) {
        Node *temp = NULL;
        if (head1->data <= head2->data) {
            temp = head1;
            head1 = head1->next;
        } else {
            temp = head2;
            head2 = head2->next;
        }
        mergedTail->next = temp;
        mergedTail = temp;
    }

    if (head1 != NULL) {
        mergedTail->next = head1;
    } else if (head2 != NULL) {
        mergedTail->next = head2;
    }

    return mergedHead;
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

    const Node *merged = mergeTwoSortedSingleLinkedList(l1, l2);
    printf("Merged List: ");
    printList(merged);


    return EXIT_SUCCESS;
}
