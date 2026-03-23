#include <iostream>
using namespace std;
int main()
{

    int arr[8] = {4, 5, 6, 7, 0, 1, 2, 3};
    int start = 0, end = 8 - 1, mid, ans = arr[0];

    // Main code

    while (start <= end)
    {
        mid = end + (start - end) / 2;

        if (arr[mid] > arr[0])
        {
            start = mid + 1; // For Right side turn
        }

        else
        {
            ans = arr[mid];
            end = mid - 1; // For Left side turn
        }
    }

    cout << "Array Rotation index is: " << ans;
}