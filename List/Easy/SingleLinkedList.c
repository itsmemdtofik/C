#include <stdio.h>
#include "Node.h"


/* insertAtBegining(head, data)
   (keeps the odd Python behavior: if head is NULL, return NULL) */
Node* insertAtBegining(Node *head, int data) {
    if (head == NULL) {
        return NULL;
    }
    Node *new_node = createNode(data);
    new_node->next = head;
    head = new_node;
    return head;
}

/* insertAtMidOfEvenOdd(head, data)
   If head is NULL, return a new node (Python returned Node(data))
   For even length insert BEFORE the second middle,
   for odd length insert AFTER the exact middle. */
Node* insertAtMidOfEvenOdd(Node *head, int data) {
    if (head == NULL) {
        return createNode(data);
    }

    Node *new_node = createNode(data);

    Node *slow = head;
    Node *fast = head;
    Node *previousNode = NULL;

    while (fast != NULL && fast->next != NULL) {
        previousNode = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    if (fast == NULL) {
        /* Even length — insert BEFORE the second middle (i.e., before slow) */
        new_node->next = slow;
        if (previousNode != NULL) {
            previousNode->next = new_node;
            return head;
        } else {
            /* Only two nodes, insert at beginning */
            new_node->next = head;
            return new_node;
        }
    } else {
        /* Odd length — insert AFTER the exact middle (slow) */
        new_node->next = slow->next;
        slow->next = new_node;
        return head;
    }
}

/* insertAtEnd(head, data)
   (keeps Python behavior: if head is NULL, return NULL) */
Node* insertAtEnd(Node *head, int data) {
    if (head == NULL) {
        return NULL;
    }
    Node *new_node = createNode(data);
    Node *currentNode = head;
    while (currentNode->next != NULL) {
        currentNode = currentNode->next;
    }
    currentNode->next = new_node;
    return head;
}

/* deleteAtBeginning(head) */
Node* deleteAtBeginning(Node *head) {
    if (head == NULL) {
        return NULL;
    }
    Node *next = head->next;
    /* NOTE: not freeing the removed node to keep behavior explicit; free if you want */
    return next;
}

/* deleteAtMidOfEvenOdd(head)
   If list empty or single node, return NULL (Python returned None).
   Uses slow/fast to find middle and deletes it. */
Node* deleteAtMidOfEvenOdd(Node *head) {
    if (head == NULL || head->next == NULL) {
        return NULL;
    }

    Node *slow = head;
    Node *fast = head;
    Node *previousNode = NULL;

    while (fast != NULL && fast->next != NULL) {
        previousNode = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    /* Delete the middle node (works for both odd and even lengths) */
    if (previousNode != NULL) {
        previousNode->next = slow->next;
        /* optionally free(slow); */
    }

    return head;
}

/* deleteAtEnd(head) */
Node* deleteAtEnd(Node *head) {
    if (head == NULL) {
        return NULL;  /* List is empty */
    }
    if (head->next == NULL) {
        return NULL;  /* Only one node — delete it by returning NULL */
    }

    Node *currentNode = head;
    Node *previousNode = NULL;

    while (currentNode->next != NULL) {
        previousNode = currentNode;
        currentNode = currentNode->next;
    }

    previousNode->next = NULL; /* Unlink the last node */
    /* optionally free(currentNode); */
    return head;
}

int main(void) {
    /* Create initial list:
       head = Node(20) -> 30 -> 40 -> 50 -> 60 -> 70
    */
    Node *head = createNode(20);
    head->next = createNode(30);
    head->next->next = createNode(40);
    head->next->next->next = createNode(50);
    head->next->next->next->next = createNode(60);
    head->next->next->next->next->next = createNode(70);

    /* insert at beginning (will return NULL if head was NULL — here head != NULL) */
    head = insertAtBegining(head, 10);
    printf("After inserting node %d at beginning:\n", head ? head->data : -1);
    printList(head);

    /* insert at middle (even/odd rule) */
    head = insertAtMidOfEvenOdd(head, 80);
    printf("After inserting node 80 at even and odd:\n");
    printList(head);

    /* insert at end */
    head = insertAtEnd(head, 90);
    printf("After inserting node 90 at ending:\n");
    printList(head);

    printf("Original List:\n");
    printList(head);

    /* delete at beginning */
    head = deleteAtBeginning(head);
    printf("After deleting from beginning:\n");
    printList(head);

    printf("Original List:\n");
    printList(head);

    /* delete middle twice */
    head = deleteAtMidOfEvenOdd(head);
    printf("After deleting from Mid:\n");
    printList(head);

    head = deleteAtMidOfEvenOdd(head);
    printf("After deleting from Mid:\n");
    printList(head);

    /* delete at end */
    head = deleteAtEnd(head);
    printf("After deleting from End:\n");
    printList(head);

    /* Note: for brevity, nodes removed are not freed; add free logic if needed */
    deAllocateMemory(head);
    return EXIT_SUCCESS;
}
