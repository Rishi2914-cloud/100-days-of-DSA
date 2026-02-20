void rotate(int** matrix, int matrixSize, int* matrixColSize) {
    int i, j, temp;

    for(i = 0; i < matrixSize; i++) {
        for(j = i + 1; j < matrixSize; j++) {
            temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }

    for(i = 0; i < matrixSize; i++) {
        int left = 0;
        int right = matrixSize - 1;

        while(left < right) {
            temp = matrix[i][left];
            matrix[i][left] = matrix[i][right];
            matrix[i][right] = temp;

            left++;
            right--;
        }
    }
}