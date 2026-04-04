#include <stdlib.h>

#define MAX 10000

typedef struct {
    int stack[MAX];
    int minStack[MAX];
    int top;
    int minTop;
} MinStack;


// Constructor
MinStack* minStackCreate() {
    MinStack* obj = (MinStack*)malloc(sizeof(MinStack));
    obj->top = -1;
    obj->minTop = -1;
    return obj;
}

// Push
void minStackPush(MinStack* obj, int val) {
    obj->stack[++obj->top] = val;

    if (obj->minTop == -1 || val <= obj->minStack[obj->minTop]) {
        obj->minStack[++obj->minTop] = val;
    }
}

// Pop
void minStackPop(MinStack* obj) {
    if (obj->stack[obj->top] == obj->minStack[obj->minTop]) {
        obj->minTop--;
    }
    obj->top--;
}

// Top
int minStackTop(MinStack* obj) {
    return obj->stack[obj->top];
}

// Get Minimum
int minStackGetMin(MinStack* obj) {
    return obj->minStack[obj->minTop];
}

// Free
void minStackFree(MinStack* obj) {
    free(obj);
}