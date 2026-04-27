/**
 * Note: The returned array must be malloc'ed, assume caller calls free().
 */
int* dailyTemperatures(int* temperatures, int temperaturesSize, int* returnSize) {
    int* answer = (int*)calloc(temperaturesSize, sizeof(int));
    int* stack = (int*)malloc(temperaturesSize * sizeof(int)); // stack holds indices
    int top = -1; // stack pointer

    for (int i = 0; i < temperaturesSize; i++) {
        // While current temp is greater than the temp at stack top
        while (top >= 0 && temperatures[i] > temperatures[stack[top]]) {
            int prevDay = stack[top--]; // pop
            answer[prevDay] = i - prevDay;
        }
        stack[++top] = i; // push current index
    }

    *returnSize = temperaturesSize;
    free(stack);
    return answer;
}
