int rec_search(int *nums, int left, int right, int target)
{
    if (left > right)
        return -1;

    int middle = left + (right - left) / 2;

    if (target == nums[middle])
        return middle;

    if (target > nums[middle])
        return rec_search(nums, middle + 1, right, target);

    if (target < nums[middle])
        return rec_search(nums, left, middle - 1, target);

    return -1;
}

int search(int* nums, int numsSize, int target)
{
    if (!nums)
        return -1;

    int left = 0;
    int right = numsSize - 1;

    return rec_search(nums, left, right, target);
}

/*int rec_search(int *nums, int left, int right, int target)
{
    if (left > right) {
        return -1;
    }

    int middle = left + (right - left) / 2;

    if (target == nums[middle]) {
        return middle;
    }

    if (target > nums[middle]) {
        return rec_search(nums, middle + 1, right, target);
    }
    
    return rec_search(nums, left, middle - 1, target);
}

int search(int* nums, int numsSize, int target)
{
    if (!nums || numsSize == 0) {
        return -1;
    }

    int left = 0;
    int right = numsSize - 1;

    return rec_search(nums, left, right, target);
}*/