#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff;
    int exp;
    struct Node* next;
};

// Create new node
struct Node* createNode(int c, int e) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = c;
    newNode->exp = e;
    newNode->next = NULL;
    return newNode;
}

// Append node
void append(struct Node** head, int c, int e) {
    struct Node* newNode = createNode(c, e);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

// Print polynomial
void printPoly(struct Node* head) {
    struct Node* temp = head;

    while (temp != NULL) {
        // Print coefficient
        printf("%d", temp->coeff);

        // Print variable part
        if (temp->exp > 1)
            printf("x^%d", temp->exp);
        else if (temp->exp == 1)
            printf("x");

        // Print + if not last term
        if (temp->next != NULL)
            printf(" + ");

        temp = temp->next;
    }
}

int main() {
    struct Node* head = NULL;
    int n, c, e;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &c, &e);
        append(&head, c, e);
    }

    printPoly(head);

    return 0;
}