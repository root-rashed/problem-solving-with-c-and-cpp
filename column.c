// C program to interchange the columns in matrix

#include <stdio.h>

int main()
{
    int Matrix[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};

    int i, j, n1, n2, temp;

    printf("Matrix before column exchange:\n");
    for (i = 0; i < 3; ++i)
    {
        for (j = 0; j < 3; ++j)
            printf(" %d", Matrix[i][j]);
        printf("\n");
    }

    printf("Enter two column numbers to be exchanged:");
    scanf("%d %d", &n1, &n2);

    // Exchange columns
    for (i = 0; i < 3; ++i)
    {
        temp = Matrix[i][n1 - 1];
        Matrix[i][n1 - 1] = Matrix[i][n2 - 1];
        Matrix[i][n2 - 1] = temp;
    }

    printf("Matrix after column exchange:\n");
    for (i = 0; i < 3; ++i)
    {
        for (j = 0; j < 3; ++j)
            printf(" %d", Matrix[i][j]);
        printf("\n");
    }

    return 0;
}
