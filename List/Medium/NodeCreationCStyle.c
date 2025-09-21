#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *createNode(const int data) {
    Node *newNode = (Node *) malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void deAllocateMemory(Node *head) {
    Node *currentNode = head;
    while (currentNode != NULL) {
        Node *nextNode = currentNode->next;
        free(currentNode);
        currentNode = nextNode;
    }
}

void printList(const Node *head) {
    const Node *currentNode = head;
    while (currentNode != NULL) {
        printf("%d", currentNode->data);
        if (currentNode->next != NULL) {
            printf(" -> ");
        }
        currentNode = currentNode->next;
    }
    printf("\n");
}

int main(void) {
    Node *head = createNode(10);
    head->next = createNode(20);

    printList(head);
    deAllocateMemory(head);
    return EXIT_SUCCESS;
}
