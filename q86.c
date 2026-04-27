typedef struct {
    int *maxHeap;
    int maxSize;
    int *minHeap;
    int minSize;
} MedianFinder;

MedianFinder* medianFinderCreate() {
    MedianFinder *mf = malloc(sizeof(MedianFinder));
    mf->maxHeap = malloc(50001 * sizeof(int));
    mf->minHeap = malloc(50001 * sizeof(int));
    mf->maxSize = 0;
    mf->minSize = 0;
    return mf;
}

void maxHeapPush(int *heap, int *size, int val) {
    heap[(*size)++] = val;
    int i = *size - 1;
    while (i > 0) {
        int p = (i - 1) / 2;
        if (heap[p] < heap[i]) {
            int t = heap[p]; heap[p] = heap[i]; heap[i] = t;
            i = p;
        } else break;
    }
}

int maxHeapPop(int *heap, int *size) {
    int top = heap[0];
    heap[0] = heap[--(*size)];
    int i = 0;
    while (1) {
        int l = 2*i+1, r = 2*i+2, largest = i;
        if (l < *size && heap[l] > heap[largest]) largest = l;
        if (r < *size && heap[r] > heap[largest]) largest = r;
        if (largest == i) break;
        int t = heap[i]; heap[i] = heap[largest]; heap[largest] = t;
        i = largest;
    }
    return top;
}

void minHeapPush(int *heap, int *size, int val) {
    heap[(*size)++] = val;
    int i = *size - 1;
    while (i > 0) {
        int p = (i - 1) / 2;
        if (heap[p] > heap[i]) {
            int t = heap[p]; heap[p] = heap[i]; heap[i] = t;
            i = p;
        } else break;
    }
}

int minHeapPop(int *heap, int *size) {
    int top = heap[0];
    heap[0] = heap[--(*size)];
    int i = 0;
    while (1) {
        int l = 2*i+1, r = 2*i+2, smallest = i;
        if (l < *size && heap[l] < heap[smallest]) smallest = l;
        if (r < *size && heap[r] < heap[smallest]) smallest = r;
        if (smallest == i) break;
        int t = heap[i]; heap[i] = heap[smallest]; heap[smallest] = t;
        i = smallest;
    }
    return top;
}

void medianFinderAddNum(MedianFinder* obj, int num) {
    maxHeapPush(obj->maxHeap, &obj->maxSize, num);
    minHeapPush(obj->minHeap, &obj->minSize, maxHeapPop(obj->maxHeap, &obj->maxSize));
    if (obj->minSize > obj->maxSize)
        maxHeapPush(obj->maxHeap, &obj->maxSize, minHeapPop(obj->minHeap, &obj->minSize));
}

double medianFinderFindMedian(MedianFinder* obj) {
    if (obj->maxSize > obj->minSize)
        return obj->maxHeap[0];
    return (obj->maxHeap[0] + obj->minHeap[0]) / 2.0;
}

void medianFinderFree(MedianFinder* obj) {
    free(obj->maxHeap);
    free(obj->minHeap);
    free(obj);
}