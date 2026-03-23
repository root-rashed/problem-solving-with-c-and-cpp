#include <stdio.h>

int checkOddEven(int num)
{

    if (num == 0)
    {

        printf("The entered number is Zero.\n");
    }

    else if (num % 2 == 0)
    {

        printf("The entered number is even.\n");
    }
    else
    {
        printf("The entered number is odd.\n");
    }
}

int main()
{
    int n1;
    printf("Input any number : ");
    scanf("%d", &n1);
    checkOddEven(n1);
    return 0;
}