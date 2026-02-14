int missingNum(int *arr, int n) {
    long long expectedSum, actualSum = 0;
    int i;

    // n is the size of array + 1
    int total = n + 1;

    // Sum of first total natural numbers
    expectedSum = (long long)total * (total + 1) / 2;

    // Sum of array elements
    for (i = 0; i < n; i++) {
        actualSum += arr[i];
    }

    // Missing number
    return (int)(expectedSum - actualSum);
}
