#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createList(int n) {
    struct Node *head = NULL, *temp = NULL, *newNode;
    int value, i;

    for(i = 0; i < n; i++) {
        scanf("%d", &value);

        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;

        if(head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    return head;
}

struct Node* mergeLists(struct Node* head1, struct Node* head2) {
    struct Node *merged = NULL, *temp = NULL, *newNode;

    while(head1 != NULL && head2 != NULL) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->next = NULL;

        if(head1->data <= head2->data) {
            newNode->data = head1->data;
            head1 = head1->next;
        } else {
            newNode->data = head2->data;
            head2 = head2->next;
        }

        if(merged == NULL) {
            merged = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    while(head1 != NULL) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = head1->data;
        newNode->next = NULL;

        if(merged == NULL) {
            merged = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }

        head1 = head1->next;
    }

    while(head2 != NULL) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = head2->data;
        newNode->next = NULL;

        if(merged == NULL) {
            merged = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }

        head2 = head2->next;
    }

    return merged;
}

void printList(struct Node* head) {
    while(head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() {
    int n, m;

    scanf("%d", &n);
    struct Node* head1 = createList(n);

    scanf("%d", &m);
    struct Node* head2 = createList(m);

    struct Node* merged = mergeLists(head1, head2);

    printList(merged);

    return 0;
}