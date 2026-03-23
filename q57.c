#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Create node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Append node
void append(struct Node** head, int data) {
    struct Node* newNode = createNode(data);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

// Rotate right by k
struct Node* rotateRight(struct Node* head, int k) {
    if (head == NULL || head->next == NULL || k == 0)
        return head;

    // Step 1: Find length
    struct Node* temp = head;
    int len = 1;

    while (temp->next != NULL) {
        temp = temp->next;
        len++;
    }

    // Step 2: Make circular
    temp->next = head;

    // Step 3: Find new tail
    k = k % len;
    int steps = len - k;

    struct Node* newTail = head;
    for (int i = 1; i < steps; i++)
        newTail = newTail->next;

    // Step 4: Set new head
    struct Node* newHead = newTail->next;

    // Step 5: Break circle
    newTail->next = NULL;

    return newHead;
}

// Print list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() {
    struct Node* head = NULL;
    int n, k, x;

    // Input
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        append(&head, x);
    }
    scanf("%d", &k);

    // Rotate
    head = rotateRight(head, k);

    // Output
    printList(head);

    return 0;
}