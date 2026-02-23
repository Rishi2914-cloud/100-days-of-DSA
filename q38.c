int maxSubarraySumCircular(int* nums, int numsSize) {
    int total_sum = nums[0];

    int curr_max = nums[0];
    int max_sum = nums[0];

    int curr_min = nums[0];
    int min_sum = nums[0];

    for(int i = 1; i < numsSize; i++) {
        total_sum += nums[i];

        if(curr_max + nums[i] > nums[i])
            curr_max = curr_max + nums[i];
        else
            curr_max = nums[i];

        if(curr_max > max_sum)
            max_sum = curr_max;

        if(curr_min + nums[i] < nums[i])
            curr_min = curr_min + nums[i];
        else
            curr_min = nums[i];

        if(curr_min < min_sum)
            min_sum = curr_min;
    }

    if(max_sum < 0)
        return max_sum;

    if(total_sum - min_sum > max_sum)
        return total_sum - min_sum;
    else
        return max_sum;
}