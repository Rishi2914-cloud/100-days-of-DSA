#include <stdlib.h>

// Comparison function for qsort
int compare(const void* a, const void* b)
{
    return (*(int*)a - *(int*)b);
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) 
{
    // Sort both arrays
    qsort(nums1, nums1Size, sizeof(int), compare);
    qsort(nums2, nums2Size, sizeof(int), compare);

    int i = 0, j = 0, k = 0;

    // Allocate maximum possible size
    int* result = (int*)malloc(sizeof(int) * (nums1Size < nums2Size ? nums1Size : nums2Size));

    // Two pointer approach
    while (i < nums1Size && j < nums2Size)
    {
        if (nums1[i] < nums2[j])
        {
            i++;
        }
        else if (nums1[i] > nums2[j])
        {
            j++;
        }
        else
        {
            result[k++] = nums1[i];
            i++;
            j++;
        }
    }

    *returnSize = k;
    return result;
}
