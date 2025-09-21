#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int data;
    struct Node *next;
} Node;


Node *createNode(const int data) {
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}


void printList(Node *head) {
    Node *temp = head;
    int count = 0;
    while (temp != NULL && count < 20) {
        printf("%d -> ", temp->data);
        temp = temp->next;
        count++;
    }
    if (temp != NULL)
        printf("...");
    else
        printf("NULL");
    printf("\n");
}


void detectAndRemoveLoop(Node *head) {
    if (head == NULL || head->next == NULL)
        return;

    Node *slow = head;
    Node *fast = head;
    int loopExists = 0;


    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            loopExists = 1;
            break;
        }
    }


    if (loopExists) {
        slow = head;


        if (slow == fast) {
            while (fast->next != head)
                fast = fast->next;
        } else {
            while (slow->next != fast->next) {
                slow = slow->next;
                fast = fast->next;
            }
        }


        fast->next = NULL;
    }
}

int main() {
    Node *head = createNode(1);
    head->next = createNode(3);
    head->next->next = createNode(4);


    head->next->next->next = head->next;

    printf("Original List with Loop (partial print to avoid infinite loop):\n");
    printList(head);

    detectAndRemoveLoop(head);

    printf("\nList after removing loop:\n");
    printList(head);

    return 0;
}
