#include <stdio.h>
#define MAX 100

int deque[MAX];
int front = -1, rear = -1;

// Check full
int isFull() {
    return (front == (rear + 1) % MAX);
}

// Check empty
int isEmpty() {
    return (front == -1);
}

// push_front
void push_front(int x) {
    if (isFull()) {
        printf("Deque Overflow\n");
        return;
    }

    if (isEmpty()) {
        front = rear = 0;
    } else {
        front = (front - 1 + MAX) % MAX;
    }

    deque[front] = x;
}

// push_back
void push_back(int x) {
    if (isFull()) {
        printf("Deque Overflow\n");
        return;
    }

    if (isEmpty()) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % MAX;
    }

    deque[rear] = x;
}

// pop_front
void pop_front() {
    if (isEmpty()) {
        printf("-1\n");
        return;
    }

    printf("%d\n", deque[front]);

    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
}

// pop_back
void pop_back() {
    if (isEmpty()) {
        printf("-1\n");
        return;
    }

    printf("%d\n", deque[rear]);

    if (front == rear) {
        front = rear = -1;
    } else {
        rear = (rear - 1 + MAX) % MAX;
    }
}

// front element
void getFront() {
    if (isEmpty()) {
        printf("-1\n");
    } else {
        printf("%d\n", deque[front]);
    }
}

// rear element
void getBack() {
    if (isEmpty()) {
        printf("-1\n");
    } else {
        printf("%d\n", deque[rear]);
    }
}

// size
void size() {
    if (isEmpty()) {
        printf("0\n");
    } else if (rear >= front) {
        printf("%d\n", rear - front + 1);
    } else {
        printf("%d\n", MAX - front + rear + 1);
    }
}

// clear
void clearDeque() {
    front = rear = -1;
}

// display (extra)
void display() {
    if (isEmpty()) {
        printf("Empty\n");
        return;
    }

    int i = front;
    while (1) {
        printf("%d ", deque[i]);
        if (i == rear) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

// reverse (simple)
void reverse() {
    if (isEmpty()) return;

    int i = front, j = rear;
    while (i != j && (i + MAX - 1) % MAX != j) {
        int temp = deque[i];
        deque[i] = deque[j];
        deque[j] = temp;

        i = (i + 1) % MAX;
        j = (j - 1 + MAX) % MAX;
    }
}

int main() {
    int n, x;
    char op[20];

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%s", op);

        if (op[0] == 'p' && op[5] == 'f') {   // push_front
            scanf("%d", &x);
            push_front(x);
        }
        else if (op[0] == 'p' && op[5] == 'b') { // push_back
            scanf("%d", &x);
            push_back(x);
        }
        else if (op[0] == 'p' && op[4] == 'f') { // pop_front
            pop_front();
        }
        else if (op[0] == 'p' && op[4] == 'b') { // pop_back
            pop_back();
        }
        else if (op[0] == 'f') { // front
            getFront();
        }
        else if (op[0] == 'b') { // back
            getBack();
        }
        else if (op[0] == 's') { // size
            size();
        }
        else if (op[0] == 'e') { // empty
            printf("%d\n", isEmpty());
        }
        else if (op[0] == 'c') { // clear
            clearDeque();
        }
        else if (op[0] == 'r') { // reverse
            reverse();
        }
    }

    return 0;
}