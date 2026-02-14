void moveZeroes(int* nums, int numsSize) 
{
    int i, j = 0;
    
    for(i = 0; i < numsSize; i++)
    {
        if(nums[i] != 0)
        {
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
            
            j++;
        }
    }
}
