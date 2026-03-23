#include <iostream>
using namespace std;
int main()
{

    int arr[7] = {1, 2, 5, 7, 5, 2, 1};
    int start = 0, end = 7 - 1, mid, ans;

    // Main code

    while (start <= end)
    {
        mid = start + (end - start) / 2;

        if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
        {
            ans = mid; // For Middle point
            break;
        }

        else if (arr[mid] > arr[mid - 1])
        {

            start = mid + 1; // For Right side
        }

        else
        {
            end = mid - 1; // For Left side
        }
    }

    cout << "Array Peak Index is: " << ans;
}