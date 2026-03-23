#include <stdio.h>

void above_threshold_students(int marks[3][3], int threshold)
{
    for (int i = 0; i < 3; i++)
    {
        float sum = 0;
        float average;
        for (int j = 0; j < 3; j++)
        {
            sum = sum + marks[i][j];
        }
        average = sum / 3;
        if (average > threshold)
        {
            printf("%d ", i);
        }
    }
}

int main()
{
    int marks[3][3] = {
        {80, 75, 90},
        {85, 88, 92},
        {65, 75, 80}};
    int threshold = 80;
    above_threshold_students(marks, threshold);
    return 0;
}
