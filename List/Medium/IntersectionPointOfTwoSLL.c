#include <stdio.h>
#include <stdlib.h>

/**
* Solution -
Get count of the nodes in the first list, let count be c1.
Get count of the nodes in the second list, let count be c2.
Get the diﬀerence of counts d = abs(c1 – c2)
Now traverse the bigger list from the first node till d nodes so that from here
onwards both the lists have an equal no of nodes
Then we can traverse both the lists in parallel till we come across a common
node. (Note that getting a common node is done by comparing the address of
the nodes)
*/

typedef struct node {
    int data;
    struct node *next;
} Node;

Node *createNode(const int data) {
    Node *newNode = (Node *) malloc(sizeof(Node));
    if (!newNode) {
        perror("Memory Allocation Failed!");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void printSLL(Node *head) {
    Node *currentNode = head;
    while (currentNode != NULL) {
        printf("%d -> ", currentNode->data);
        currentNode = currentNode->next;
    }
    printf("NULL\n");
}

void deAllocate(Node *head) {
    Node *currentNode = head;
    while (currentNode != NULL) {
        Node *nextNode = currentNode->next;
        free(currentNode);
        currentNode = nextNode;
    }
}

int getIntersectionNode(Node *head1, Node *head2) {
    Node *currentNode1 = head1;
    Node *currentNode2 = head2;

    while (currentNode1 != currentNode2) {
        /* If the first pointer is null then set it to point to the head of the second linked list */
        if (currentNode1 == NULL) {
            currentNode1 = head2;
        } else {
            currentNode1 = currentNode1->next;
        }

        if (currentNode2 == NULL) {
            currentNode2 = head1;
        } else {
            currentNode2 = currentNode2->next;
        }
    }

    return currentNode1->data;
}

/* find intersection node of the given linked lists */
Node *getIntersectionNode1(Node *head1, Node *head2) {
    Node *curr1 = head1, *curr2 = head2;

    while (curr1 != curr2) {
        curr1 = (curr1 == NULL) ? head2 : curr1->next;
        curr2 = (curr2 == NULL) ? head1 : curr2->next;
    }
    /* either intersection Node* or NULL */
    return curr1;
}

int main(int argc, char *argv[]) {
    /* Build first list: 3 -> 6 -> 9 -> 15 -> 30 */
    Node *head1 = createNode(3);
    head1->next = createNode(6);
    head1->next->next = createNode(9);
    Node *inter = createNode(15); /* intersection starts here */
    head1->next->next->next = inter;
    inter->next = createNode(30);

    /* Build second list: 10 -> 15 -> 30
       but share the nodes starting at 'inter' so lists intersect at 15 */
    Node *head2 = createNode(10);
    head2->next = inter; /* create intersection */

    printf("List 1: \n");
    printSLL(head1);
    printf("List 2: \n");
    printSLL(head2);

    Node *result = getIntersectionNode1(head1, head2);
    if (result != NULL) {
        printf("Intersection at node with data = %d\n", result->data);
    } else {
        printf("No intersection.\n");
    }
    int ans = getIntersectionNode(head1, head2);
    if (ans != -1) {
        printf("Intersection at node with data = %d\n", ans);
    } else {
        printf("No intersection.\n");
    }

    deAllocate(result);
    /* NOTE: For brevity we skip freeing shared nodes.
       In production free carefully ensuring shared nodes freed once. */

    return EXIT_SUCCESS;
}
