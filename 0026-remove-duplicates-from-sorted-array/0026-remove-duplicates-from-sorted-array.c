int removeDuplicates(int* nums, int numsSize)
{
    int k = 1;

    int idx = 1;
    int buffer = nums[0];

    while (idx < numsSize)
    {
        int i = idx; 

        while (i < numsSize && nums[i] == buffer) // Skip all duplicates
        {
            i++;
        }

        // Swap the values
        if (i < numsSize) // we skipped elements
        {
            buffer = nums[i];
            nums[k] = nums[i];
            k++;
            idx = i + 1;
        }
        else
            break;
    }

    return k;
}