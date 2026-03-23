#include <stdio.h>
int main()
{
    int n;
    printf("How many numbers: ");
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter %dst number: ", i + 1); // for input
        scanf("%d", &arr[i]);
    }

    int max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (max < arr[i])
        { // to find maximum
            max = arr[i];
        }
    }
    printf("Maximum = %d\n", max);

    return 0;
}