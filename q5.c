#include <stdio.h>

int main() {
    int n, i, key;
    int comparisons = 0;

    printf("Enter the size of array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

     printf("Enter the key to search: ");
    scanf("%d", &key);

    int found = -1;  d

    for(i = 0; i < n; i++) {
        comparisons++;  

        if(arr[i] == key) {
            found = i;   
            break;      
        }
    }

    if(found != -1) {
        printf("Key found at index %d\n", found);
    } else {
        printf("Key not found in the array\n");
    }

    printf("Total comparisons performed: %d\n", comparisons);

    return 0;
}
