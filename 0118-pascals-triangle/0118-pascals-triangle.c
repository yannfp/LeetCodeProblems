/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

void destroy_rows(int **rows, int size)
{
    for (int i = 0; i < size; i++)
        free(rows[i]);

    free(rows);
}

int** generate(int numRows, int* returnSize, int** returnColumnSizes)
{
    if (numRows == 0)
    {
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }

    int **rows = malloc(sizeof(int *) * numRows);
    if (!rows)
        return NULL;

    int *column_sizes = malloc(sizeof(int) * numRows);
    if (!column_sizes)
    {
        free(rows);
        return rows;
    }

    column_sizes[0] = 1;

    rows[0] = malloc(sizeof(int) * 1);
    if (!rows[0])
    {
        free(column_sizes);
        free(rows);
        return NULL;
    }
    rows[0][0] = 1;
    
    for (int i = 1; i < numRows; i++)
    {
        column_sizes[i] = i + 1;

        int *row = malloc(sizeof(int) * (i + 1));
        if (!row)
        {
            destroy_rows(rows, i);
            free(column_sizes);
            return NULL;
        }

        rows[i] = row;

        for (int j = 0; j <= i; j++)
        {
            // First and last elements are 1
            if (j == 0 || j == i)
                row[j] = 1;
            else
                row[j] = rows[i - 1][j - 1] + rows[i - 1][j];
        }
    }

    *returnSize = numRows;
    *returnColumnSizes = column_sizes;

    return rows;
}