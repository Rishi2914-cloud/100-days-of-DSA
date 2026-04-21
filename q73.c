#include <stdio.h>

#define MAX 100

int pq[MAX];
int size = 0;

// Function to insert element
void insert(int x) {
    if (size == MAX) {
        printf("Queue Overflow\n");
        return;
    }
    pq[size++] = x;
}

// Function to find index of smallest element
int findMinIndex() {
    if (size == 0)
        return -1;

    int minIndex = 0;
    for (int i = 1; i < size; i++) {
        if (pq[i] < pq[minIndex]) {
            minIndex = i;
        }
    }
    return minIndex;
}

// Function to delete highest priority element (smallest)
void delete() {
    if (size == 0) {
        printf("-1\n");
        return;
    }

    int minIndex = findMinIndex();
    printf("%d\n", pq[minIndex]);

    // Shift elements left
    for (int i = minIndex; i < size - 1; i++) {
        pq[i] = pq[i + 1];
    }
    size--;
}

// Function to peek highest priority element
void peek() {
    if (size == 0) {
        printf("-1\n");
        return;
    }

    int minIndex = findMinIndex();
    printf("%d\n", pq[minIndex]);
}

int main() {
    int n;
    scanf("%d", &n);

    char op[10];
    int x;

    for (int i = 0; i < n; i++) {
        scanf("%s", op);

        if (op[0] == 'i') {  // insert
            scanf("%d", &x);
            insert(x);
        }
        else if (op[0] == 'd') {  // delete
            delete();
        }
        else if (op[0] == 'p') {  // peek
            peek();
        }
    }

    return 0;
}