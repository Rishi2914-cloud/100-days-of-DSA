void setZeroes(int** matrix, int matrixSize, int* matrixColSize) {
    int i, j;
    int firstRowZero = 0, firstColZero = 0;

    int rows = matrixSize;
    int cols = matrixColSize[0];

    for(j = 0; j < cols; j++) {
        if(matrix[0][j] == 0) {
            firstRowZero = 1;
            break;
        }
    }

    for(i = 0; i < rows; i++) {
        if(matrix[i][0] == 0) {
            firstColZero = 1;
            break;
        }
    }

    for(i = 1; i < rows; i++) {
        for(j = 1; j < cols; j++) {
            if(matrix[i][j] == 0) {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    for(i = 1; i < rows; i++) {
        for(j = 1; j < cols; j++) {
            if(matrix[i][0] == 0 || matrix[0][j] == 0) {
                matrix[i][j] = 0;
            }
        }
    }

    if(firstRowZero) {
        for(j = 0; j < cols; j++) {
            matrix[0][j] = 0;
        }
    }

    if(firstColZero) {
        for(i = 0; i < rows; i++) {
            matrix[i][0] = 0;
        }
    }
}