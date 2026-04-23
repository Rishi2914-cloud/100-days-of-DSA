#include <stdlib.h>

// sort integers
int cmpInt(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

// structure for number + frequency
typedef struct {
    int num;
    int freq;
} Node;

// sort by frequency (descending)
int cmpNode(const void* a, const void* b) {
    return ((Node*)b)->freq - ((Node*)a)->freq;
}

int* topKFrequent(int* nums, int numsSize, int k, int* returnSize) {

    // Step 1: sort nums
    qsort(nums, numsSize, sizeof(int), cmpInt);

    // Step 2: count frequencies
    Node* arr = (Node*)malloc(numsSize * sizeof(Node));
    int count = 0;

    for (int i = 0; i < numsSize; i++) {
        if (i == 0 || nums[i] != nums[i - 1]) {
            arr[count].num = nums[i];
            arr[count].freq = 1;
            count++;
        } else {
            arr[count - 1].freq++;
        }
    }

    // Step 3: sort by frequency
    qsort(arr, count, sizeof(Node), cmpNode);

    // Step 4: take top k
    int* result = (int*)malloc(k * sizeof(int));
    for (int i = 0; i < k; i++) {
        result[i] = arr[i].num;
    }

    *returnSize = k;
    return result;
}