/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize)
{
    int *res = malloc(sizeof(int) * digitsSize);
    if (!res)
        return NULL;

    int remainder = 0;

    for (int i = digitsSize - 1; i >= 0; i--)
    {
        int new_value;
        if (i == digitsSize - 1) 
            new_value = digits[i] + 1 + remainder;
        else
            new_value = digits[i] + remainder;
            
        if (new_value >= 10)
        {
            remainder = new_value / 10; 
            new_value = new_value % 10;
        }
        else
            remainder = 0;

        res[i] = new_value;
    }

    *returnSize = digitsSize;

    if (remainder != 0)
    {
        res = realloc(res, sizeof(int) * (digitsSize + 1));
        if (!res)
            return NULL;
        
        *returnSize = digitsSize + 1;

        res[0] = remainder;
        res[digitsSize] = 0;
    }

    return res;
}