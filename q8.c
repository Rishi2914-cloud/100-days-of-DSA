int removeElement(int* nums, int numsSize, int val) 
{
    int i;
    int k = 0;  // Count of elements not equal to val

    for(i = 0; i < numsSize; i++)
    {
        if(nums[i] != val)
        {
            nums[k] = nums[i];
            k++;
        }
    }

    return k;
}
