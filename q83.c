#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Queue structure
struct Queue {
    struct Node* front;
    struct Node* rear;
};

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

// Initialize an empty queue
struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

// Enqueue operation
void enqueue(struct Queue* q, int data) {
    struct Node* temp = newNode(data);

    // If queue is empty
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }

    // Add new node at the end and update rear
    q->rear->next = temp;
    q->rear = temp;
}

// Dequeue operation
int dequeue(struct Queue* q) {
    // If queue is empty
    if (q->front == NULL) {
        printf("Queue is empty\n");
        return -1;
    }

    // Store front node and move front pointer
    struct Node* temp = q->front;
    int data = temp->data;
    q->front = q->front->next;

    // If front becomes NULL, then rear should also be NULL
    if (q->front == NULL)
        q->rear = NULL;

    free(temp);
    return data;
}

// Utility function to display queue
void display(struct Queue* q) {
    struct Node* temp = q->front;
    printf("Queue: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Driver code
int main() {
    struct Queue* q = createQueue();

    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    display(q);

    printf("Dequeued: %d\n", dequeue(q));
    display(q);

    enqueue(q, 40);
    display(q);

    return 0;
}
