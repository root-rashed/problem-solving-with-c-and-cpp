#include <stdio.h>
int main()
{
    int fact = 1;
    for (int i = 1; i <= 5; i++)
    {
        fact = fact * i;
    }
    printf("Factorial is %d", fact);
    return 0;
}