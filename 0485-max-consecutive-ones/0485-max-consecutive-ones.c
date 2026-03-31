int findMaxConsecutiveOnes(int* nums, int numsSize)
{
    int count = 0;
    int temp = 0;

    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] == 1)
        {
            temp++;
        }
        else
        {
            if (count == 0)
                count = temp;
            else
            {
                if (temp > count)
                    count = temp;
            }

            temp = 0;
        }
    }

    if (temp > count)
        count = temp;

    return count;
}