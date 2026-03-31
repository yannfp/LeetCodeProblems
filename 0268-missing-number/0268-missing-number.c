int missingNumber(int* nums, int numsSize)
{
    int sum = 0;
    int total_sum = numsSize;

    for (int i = 0; i < numsSize; i++)
    {
        sum = sum + nums[i];
        total_sum = total_sum + i;
    }

    return total_sum - sum;   
}