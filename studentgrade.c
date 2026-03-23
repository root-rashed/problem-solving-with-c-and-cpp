#include <stdio.h>

// Function to calculate average grades of each student and create an array
void average_grades(int matrix[3][3], int rows, int cols, float averages[3])
{
    for (int i = 0; i < rows; i++)
    {
        float total = 0;
        for (int j = 0; j < cols; j++)
        {
            total = total + matrix[i][j];
        }
        averages[i] = total / cols;
    }
}

int main()
{
    int grades_matrix[3][3] = {
        {85, 90, 88},
        {70, 82, 75},
        {95, 88, 92}};
    int rows = 3;
    int cols = 3;

    // Array to store averages for each student
    float averages[3];
    average_grades(grades_matrix, rows, cols, averages);

    // print the averages
    for (int i = 0; i < rows; i++)
    {
        printf("Student %d: %f\n", i + 1, averages[i]);
    }

    return 0;
}
