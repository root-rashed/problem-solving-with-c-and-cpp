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
        for (int l = 6 - i; l > 0; l--)
        {
            printf("%c ", 64 + l);
        }

        printf("\n");
    }

    // second loop to print all rows
    for (int p = 0; p < rows; p++)
    {

        // inner loop 1 to print white spaces
        for (int m = 0; m < 2 * (rows - p)-2; m++)
        {
            printf(" ");
        }

        // inner loop 2 to print alphabets
        for (int r = 0; r <= p; r++)
        {
            printf("%c ", 'A' + r);
        }

        // third loop for printing alphabets in each row
        for (int q = 0; q < p; q++)
        {
            printf("%c ", 'A' + p - q - 1);
        }

        printf("\n");
    }
    return 0;
}
