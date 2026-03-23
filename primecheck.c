#include <stdio.h>

int oddeven(n1)
{

    int count = 0;
    for (int i = 2; i <= n1; i++)
    {
        if (n1 % i == 0)
        {
            count++;
        }
    }

    if (count > 0)
        printf("Not prime number");
    else
        printf("prime number");
}

int main()
{
    int n1;
    printf("enter number: ");
    scanf("%d", &n1);
    oddeven(n1);
}
