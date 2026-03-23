#include <iostream>
using namespace std;
int main()
{
    int arr[5] = {8, 5, 7, 2, 0};
    int flag = 0;

    // Bubble sort Code
    for (int i = 3; i >= 0; i--)
    {

        for (int j = 0; j <= i; j++)
        {
            if (arr[j] > arr[j + 1]) // Ascending or descending order
            {
                flag = 1;
                swap(arr[j], arr[j + 1]);
            }
        }

        if (flag == 0) // If the array is already sorted.
            break;
    }

    // Print the sorted Array
    for (int i = 0; i <= 4; i++)
        cout << arr[i] << " ";

    return 0;
}