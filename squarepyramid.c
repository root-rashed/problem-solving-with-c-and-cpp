#include <stdio.h>
int main()
{
    int rows = 7;

    // first loop to print all rows
    for (int p = 0; p < rows; p++)
    {

        // inner loop 1 to print white spaces
        for (int m = 0; m < 2 * (rows - p) - 2; m++)
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

    // second loop for printing all rows
    for (int m = 0; m < 6; m++)
    {

        // first inner loop for printing white spaces
        for (int n = 0; n <= 2 * m; n++)
        {
            printf(" ");
        }

        // second inner loop for printing alphabets
        for (int p = 0; p < 6 - m; p++)
        {
            printf("%c ", 65 + p);
        }
        // third inner loop for printing alphabets
        for (int q = 5 - m; q > 0; q--)
        {
            printf("%c ", 64 + q);
        }

        printf("\n");
    }
    return 0;
}
