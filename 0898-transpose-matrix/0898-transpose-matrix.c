/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
void destroy(int **matrix, int size)
{
    for (int i = 0; i < size; i++)
        free(matrix[i]);
    
    free(matrix);
}

int** transpose(int** matrix, int matrixSize, int* matrixColSize, int* returnSize, int** returnColumnSizes)
{
    if (!matrix)
        return NULL;

    int col_size = matrixColSize[0];

    int **result = malloc(sizeof(int *) * col_size);
    if (!result)
        return NULL;

    for (int j = 0; j < col_size; j++)
    {
        int *row = malloc(sizeof(int) * matrixSize);
        if (!row)
        {
            destroy(result, col_size);
            return NULL;
        }

        result[j] = row;

        for (int i = 0; i < matrixSize; i++)
        {
            result[j][i] = matrix[i][j];
        }
    }    

    *returnSize = col_size;
    int *colSizes = malloc(sizeof(int) * col_size);

    if (!colSizes) {
        destroy(result, col_size);
        return NULL;
    }

    for (int i = 0; i < col_size; i++) {
        colSizes[i] = matrixSize;
    }

    *returnColumnSizes = colSizes;
    
    return result;
}