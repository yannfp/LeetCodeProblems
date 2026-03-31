/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* shuffle(int* nums, int numsSize, int n, int* returnSize)
{

    int *res = malloc(sizeof(int) * numsSize);
    if (!res)
        return NULL;

    for (int i = 0; i < n; i++)
    {
        res[2 * i] = nums[i];
        res[(2 * i) + 1] =  nums[n + i];
    }


    *returnSize = numsSize;

    return res;
}