/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    
    int rows = matrixSize;
    int cols = matrixColSize[0];
    
    int* result = (int*)malloc(rows * cols * sizeof(int));
    
    int top = 0;
    int bottom = rows - 1;
    int left = 0;
    int right = cols - 1;
    
    int index = 0;
    
    while (top <= bottom && left <= right) {
        
        // 1. Left to Right
        for (int i = left; i <= right; i++) {
            result[index++] = matrix[top][i];
        }
        top++;
        
        // 2. Top to Bottom
        for (int i = top; i <= bottom; i++) {
            result[index++] = matrix[i][right];
        }
        right--;
        
        // 3. Right to Left
        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                result[index++] = matrix[bottom][i];
            }
            bottom--;
        }
        
        // 4. Bottom to Top
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                result[index++] = matrix[i][left];
            }
            left++;
        }
    }
    
    *returnSize = rows * cols;
    return result;
}