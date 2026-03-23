#include <stdio.h>
int main()
{
    int n;
    printf("How many numbers: ");
    scanf("%d", &n);
    int arr[n];

    printf("Enter array elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]); // input array
    }

    printf("Your array is: ");
    for (int i = 0; i < n; i++)
    { // Show the array
        printf("%d ", arr[i]);
    }

    int lastindex = n - 1;
    int counter = 1;

    while (counter < n)
    {
        int index = 0;
        while (index < lastindex)
        {
            if (arr[index] > arr[index + 1])
            {
                Swap(arr[index], arr[index + 1]);
            }

            else if
            {
                index = index + 1;
            }
        }
        endwhile
    }

    return 0;
}