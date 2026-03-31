int removeElement(int* nums, int numsSize, int val)
{
    // Store the numbers of non-removed elements
    int k = 0;

    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] != val)
        {
            nums[k] = nums[i];
            k++;
        }
    }

    return k;
}