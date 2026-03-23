#include <stdio.h>
int main()
{
    int transpose[3][3];
    int matrix[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};

    // Original matrix
    printf("Original Matrix:\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", matrix[i][j]); // Swapping rows with columns
        }
        printf("\n");
    }

    // Transposing the matrix
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            transpose[j][i] = matrix[i][j]; // Swapping rows with columns
        }
    }

    // Printing the transposed matrix
    printf("\nTransposed Matrix:\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", transpose[i][j]);
        }
        printf("\n");
    }

    int n1 = 1, n2 = 3, temp;
    // Exchange columns
    for (int i = 0; i < 3; ++i)
    {
        temp = transpose[i][n1 - 1];
        transpose[i][n1 - 1] = transpose[i][n2 - 1]; // Swapping columns
        transpose[i][n2 - 1] = temp;
    }

    // Printing the swapping matrix
    printf("\nAfter Swapping 1st and 2nd Column of the Matrix:\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", transpose[i][j]);
        }
        printf("\n");
    }
    return 0;
}