#include <stdio.h>
#include <stdlib.h>

// Structure of Doubly Linked List Node
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

int main() {
    int n, i, value;

    struct Node *head = NULL, *temp = NULL, *newNode = NULL;

    // Read number of nodes
    scanf("%d", &n);

    // Create doubly linked list
    for(i = 0; i < n; i++) {

        scanf("%d", &value);

        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->prev = NULL;
        newNode->next = NULL;

        if(head == NULL) {
            head = newNode;
            temp = head;
        }
        else {
            temp->next = newNode;
            newNode->prev = temp;
            temp = newNode;
        }
    }

    // Traversal (Forward)
    temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}