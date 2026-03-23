#include <stdio.h>
#include <limits.h>
int main()
{
    // declaring the size of the array
    int n;
    printf("Enter size of the array: ");
    scanf("%d", &n);

    // For entering elements
    int arr[n];
    for (int i = 0; i < n; i++)
    {

        printf("Enter %d number elements: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // assigning first element as smallest temporarily
    int smallest = arr[0];

    // we find the smallest element here
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < smallest)
            smallest = arr[i];
    }

    // temporarily assinging largest max value
    int sec_smallest = INT_MAX;

    // finding second smallest here
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != smallest && arr[i] < sec_smallest)
            sec_smallest = arr[i];
    }

    printf("The 2nd smallest : %d", sec_smallest);
    return 0;
}
