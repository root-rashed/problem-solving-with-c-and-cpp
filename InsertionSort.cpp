#include <iostream>
using namespace std;
int main()
{
    int arr[5] = {3, 1, 2, 4, 5};

    // Insertion sort Code
    for (int i = 1; i <= 4; i++)
    {
        for (int j = i; j > 0; j--)
        {
            if (arr[j - 1] < arr[j]) // Ascending or descending order
            {
                swap(arr[j - 1], arr[j]);
            }
            else
                break;
        }
    }

    // Print the sorted Array
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}