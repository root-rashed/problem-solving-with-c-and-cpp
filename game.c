#include <stdio.h>
#include <stdbool.h>

char check_winner(char matrix[3][3])
{
    // Check rows
    for (int row = 0; row < 3; row++)
    {
        if (matrix[row][0] == matrix[row][1] && matrix[row][1] == matrix[row][2] && matrix[row][0] != ' ')
        {
            return matrix[row][0];
        }
    }

    // Check columns
    for (int col = 0; col < 3; col++)
    {
        if (matrix[0][col] == matrix[1][col] && matrix[1][col] == matrix[2][col] && matrix[0][col] != ' ')
        {
            return matrix[0][col];
        }
    }

    // Check diagonals
    if (matrix[0][0] == matrix[1][1] && matrix[1][1] == matrix[2][2] && matrix[0][0] != ' ')
    {
        return matrix[0][0];
    }

    if (matrix[0][2] == matrix[1][1] && matrix[1][1] == matrix[2][0] && matrix[0][2] != ' ')
    {
        return matrix[0][2];
    }

    int space = 0;
    // Check for only space
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            if (matrix[row][col] == ' ')
            {
                space = 1;
                break;
            }
        }
    }

    if (space == 0)
    {
        return 'D'; // Draw
    }
    if (space == 1)
    {
        return ' ';
    }
}

int main()
{
    char game[3][3] = {
        {'X', 'O', 'X'},
        {'O', ' ', 'O'},
        {'X', 'X', 'O'}};

    char winner = check_winner(game);
    if (winner == 'X' || winner == 'O')
    {
        printf("Winner: %c\n", winner);
    }
    else if (winner == 'D')
    {
        printf("Draw\n");
    }
    else
    {
        printf("No winner yet\n");
    }

    return 0;
}
