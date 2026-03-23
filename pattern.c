// C program to print the inverted alphabets
#include <stdio.h>

int main()
{

	// Input rows from the user
	int rows;
	printf("Enter number of rows: ");
	scanf("%d", &rows);

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
		printf("\n");
	}

	return 0;
}
