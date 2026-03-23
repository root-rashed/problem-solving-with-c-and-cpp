#include <iostream>
using namespace std;
int main()
{

    int arr[11] = {1, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1};
    int size = 11;
    int start = 0, end = size - 1;

    while (start < end)
    {
        if (arr[start] == 0)
        {

            start++;
        }
        else
        {
            if (arr[end] == 0)
            {
                swap(arr[start], arr[end]);
                start++;
                end--;
            }
            else
                end--;
        }
    }

    for (int i = 0; i < size; i++)
    {

        cout << arr[i] << " ";
    }

    // int count0 = 0, count1 = 0;

    // for (int i = 0; i < 8; i++)
    // {
    //     if (arr[i] == 0)
    //     {
    //         count0++; // Counting 0 and 1
    //     }
    //     else
    //         count1++;
    // }

    // for (int i = 0; i < count0; i++)
    // {

    //     arr[i] = 0; // Arrange 0
    // }

    // for (int i = count0; i < 8; i++)
    // {

    //     arr[i] = 1; // Arrange 1
    // }
}