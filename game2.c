#include <stdio.h>

char check_winner(char matrix[3][3])
{
    // Check rows and columns
    for (int i = 0; i < 3; i++)
    {
        if ((matrix[i][0] == matrix[i][1] && matrix[i][1] == matrix[i][2] && matrix[i][0] != ' ') ||
            (matrix[0][i] == matrix[1][i] && matrix[1][i] == matrix[2][i] && matrix[0][i] != ' '))
        {
            return matrix[i][i];
        }
    }

    // Check diagonals
    if ((matrix[0][0] == matrix[1][1] && matrix[1][1] == matrix[2][2] && matrix[0][0] != ' ') ||
        (matrix[0][2] == matrix[1][1] && matrix[1][1] == matrix[2][0] && matrix[0][2] != ' '))
    {
        return matrix[1][1];
    }

    // Check for Draw
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (matrix[i][j] == ' ')
            {
                return ' ';
            }
        }
    }

    return 'D'; // Draw
}

int main()
{
    char board[3][3] = {
        {'X', 'O', 'X'},
        {'O', 'X', 'O'},
        {'X', 'X', 'O'}};

    char winner = check_winner(board);
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
