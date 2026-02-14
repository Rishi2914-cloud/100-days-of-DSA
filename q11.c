#include <stdio.h>

int main() {
    int n, i;

    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d sorted elements:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    if(n == 0) {
        return 0;
    }

    int j = 1;  

    for(i = 1; i < n; i++) {
        if(arr[i] != arr[i - 1]) {
            arr[j] = arr[i];
            j++;
        }
    }

    printf("Unique elements:\n");
    for(i = 0; i < j; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
