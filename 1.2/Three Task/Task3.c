#include <stdio.h>

int main()
{
    // Subtask 1 : Matrix A
    int n, i, j, temp;

    printf("Enter the dimension number of squre matrix:");
    scanf("%d", &n);

    int A[n][n];
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("Enter value for A[%d][%d]:", i, j);
            scanf("%d", &A[i][j]);
        }
    }

    printf("\nMatrix A:\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }

    // Subtask 2 : Matrix B
    int B[n][n];

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            B[i][j] = A[i][j];
        }
        for (j = 0; j < n; j++)
        {
            if (i == j)
            {
                temp = B[i][j];
                B[i][j] = B[i][n - i - 1];
                B[i][n - i - 1] = temp;
            }
        }
    }

    printf("\nMatrix B: after interchange diagonals\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d ", B[i][j]);
        }
        printf("\n");
    }

    // Subtask 3 : Matrix C
    int C[n][n];

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            C[j][i] = B[i][j];
        }
    }

    printf("\nMatrix C: after transpose of the matrix B\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    // Subtask 4 : Matrix Operation

    printf("\nMatrix Operation: 3A+2B-C\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d ", (3 * A[i][j]) + (2 * B[i][j]) - C[i][j]);
        }
        printf("\n");
    }

    return 0;
}