#include <stdio.h>
#include <stdlib.h>

// Node structure for Queue
struct Node {
    int data;
    struct Node* next;
};

// Queue structure
struct Queue {
    struct Node* front;
    struct Node* rear;
};

// Stack structure (linked list based)
struct Stack {
    struct Node* top;
};

// Utility function to create a new node
struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

// Queue operations
struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

void enqueue(struct Queue* q, int data) {
    struct Node* temp = newNode(data);
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}

int dequeue(struct Queue* q) {
    if (q->front == NULL) {
        printf("Queue is empty\n");
        return -1;
    }
    struct Node* temp = q->front;
    int data = temp->data;
    q->front = q->front->next;
    if (q->front == NULL)
        q->rear = NULL;
    free(temp);
    return data;
}

int isQueueEmpty(struct Queue* q) {
    return q->front == NULL;
}

// Stack operations
struct Stack* createStack() {
    struct Stack* s = (struct Stack*)malloc(sizeof(struct Stack));
    s->top = NULL;
    return s;
}

void push(struct Stack* s, int data) {
    struct Node* temp = newNode(data);
    temp->next = s->top;
    s->top = temp;
}

int pop(struct Stack* s) {
    if (s->top == NULL) {
        printf("Stack is empty\n");
        return -1;
    }
    struct Node* temp = s->top;
    int data = temp->data;
    s->top = s->top->next;
    free(temp);
    return data;
}

int isStackEmpty(struct Stack* s) {
    return s->top == NULL;
}

// Function to reverse queue using stack
void reverseQueue(struct Queue* q) {
    struct Stack* s = createStack();

    // Step 1: Move all elements from queue to stack
    while (!isQueueEmpty(q)) {
        push(s, dequeue(q));
    }

    // Step 2: Move all elements back from stack to queue
    while (!isStackEmpty(s)) {
        enqueue(q, pop(s));
    }
}

// Utility function to display queue
void displayQueue(struct Queue* q) {
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
    enqueue(q, 40);

    printf("Original ");
    displayQueue(q);

    reverseQueue(q);

    printf("Reversed ");
    displayQueue(q);

    return 0;
}
