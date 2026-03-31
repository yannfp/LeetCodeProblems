


typedef struct {
    int* sum;
    int size;
} NumArray;


NumArray* numArrayCreate(int* nums, int numsSize)
{
    NumArray *array = malloc(sizeof(NumArray));
    if (!array)
        return NULL;

    array->size = numsSize;

    array->sum = malloc(sizeof(int) * (numsSize + 1));
    if (!array->sum)
        return NULL;

    array->sum[0] = 0;
    for (int i = 0; i < numsSize; i++)
        array->sum[i + 1] = array->sum[i] + nums[i];  

    return array;
}

int numArraySumRange(NumArray* obj, int left, int right)
{
    return obj->sum[right + 1] - obj->sum[left];
}

void numArrayFree(NumArray* obj)
{
    free(obj->sum);
    free(obj);    
}

/**
 * Your NumArray struct will be instantiated and called as such:
 * NumArray* obj = numArrayCreate(nums, numsSize);
 * int param_1 = numArraySumRange(obj, left, right);
 
 * numArrayFree(obj);
*/