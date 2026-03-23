#include <stdio.h>

int main()
{
    int rows = 7;

    // first loop for printing all rows
    for (int i = 0; i < rows; i++)
    {
        // first inner loop for printing white spaces
        for (int j = 0; j < 2 * i; j++)
        {
            printf(" ");
        }

        // second inner loop for printing alphabets
        for (int k = 0; k < rows - i; k++)
        {
            printf("%c ", 65 + k);
        }

        // third inner loop for printing alphabets
        for (int l = rows - i - 2; l >= 0; l--)
        {
            printf("%c ", 65 + l);
        }

        printf("\n");
    }

    // second loop to print all rows
    for (int p = 1; p < rows; p++)
    {

        // inner loop 1 to print white spaces
        for (int m = 0; m < 2 * p; m++)
        {
            printf(" ");
        }

        // inner loop 2 to print alphabets
        for (int r = 0; r < rows - p; r++)
        {
            printf("%c ", 'A' + r);
        }

        // third loop for printing alphabets in each row
        for (int q = rows - p - 2; q >= 0; q--)
        {
            printf("%c ", 'A' + q);
        }

        printf("\n");
    }

    return 0;
}
