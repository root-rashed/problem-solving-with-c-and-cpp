// C program to print the inverted alphabets
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

    return 0;
}
