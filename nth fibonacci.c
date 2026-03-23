#include <stdio.h>
int main()
{
    int a = 0, b = 1, c, n;
    printf("Enter number: ");
    scanf("%d", &n);

    if (n<=0)
        printf("Invalid input");
    else if (n == 1)
        printf("%d", a);

    else
    {
        for (int i = 3; i <= n; i++)
        {
            c = a + b;
            a = b;
            b = c;
        }
        printf("%d", c);
    }

    return 0;
}