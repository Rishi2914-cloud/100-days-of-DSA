#include <stdlib.h>
#include <stdbool.h>

#define MAX 10000

typedef struct {
    int inStack[MAX];
    int outStack[MAX];
    int topIn;
    int topOut;
} MyQueue;

/** Initialize queue */
MyQueue* myQueueCreate() {
    MyQueue* obj = (MyQueue*)malloc(sizeof(MyQueue));
    obj->topIn = -1;
    obj->topOut = -1;
    return obj;
}

/** Push element x to the back of queue */
void myQueuePush(MyQueue* obj, int x) {
    obj->inStack[++obj->topIn] = x;
}

/** Helper: move elements if needed */
void transfer(MyQueue* obj) {
    if (obj->topOut == -1) {
        while (obj->topIn != -1) {
            obj->outStack[++obj->topOut] = obj->inStack[obj->topIn--];
        }
    }
}

/** Removes element from front and returns it */
int myQueuePop(MyQueue* obj) {
    transfer(obj);
    return obj->outStack[obj->topOut--];
}

/** Get front element */
int myQueuePeek(MyQueue* obj) {
    transfer(obj);
    return obj->outStack[obj->topOut];
}

/** Returns whether the queue is empty */
bool myQueueEmpty(MyQueue* obj) {
    return (obj->topIn == -1 && obj->topOut == -1);
}

void myQueueFree(MyQueue* obj) {
    free(obj);
}
