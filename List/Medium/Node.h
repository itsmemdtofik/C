#pragma once
#include <stdio.h>
#include <stdlib.h>
#ifndef NODE_H
#define NODE_H


typedef struct node {
    int data;
    struct node *next;
} Node;

/* Function Declaration */
Node *createNode(int data);

void deAllocateMemory(Node *head);

void printList(const Node *head);

#endif

/* Create the Single Linked List */
inline Node *createNode(const int data) {
    Node *newNode = malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed!");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}


inline void deAllocateMemory(Node *head) {
    Node *currentNode = head;
    while (currentNode) {
        Node *nextNode = currentNode->next;
        free(currentNode);
        currentNode = nextNode;
    }
}

inline void printList(const Node *head) {
    const Node *currentNode = head;
    while (currentNode) {
        printf("%d -> ", currentNode->data);
        currentNode = currentNode->next;
    }
    printf("NULL\n");
}
