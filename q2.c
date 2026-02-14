#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize) 
{
    
    *returnSize = 2;

    
    int* answer = (int*)malloc(2 * sizeof(int));

    
    for(int i = 0; i < numsSize; i++)
    {
        for(int j = i + 1; j < numsSize; j++)
        {
            if(nums[i] + nums[j] == target)
            {
                answer[0] = i;
                answer[1] = j;
                return answer;   
            }
        }
    }

    return NULL;  
}


