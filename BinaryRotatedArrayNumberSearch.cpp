#include <iostream>
using namespace std;
int main()
{

    int arr[8] = {4, 5, 6, 7, 0, 1, 2, 3};
    int num, start = 0, end = 8 - 1, mid, ans = -1;

    cout << "Enter number: ";
    cin >> num;

    // Main code
    while (start <= end)
    {
        mid = end + (start - end) / 2;

        // For mid position
        if (arr[mid] == num)
        {
            ans = mid;
            break;
        }

        // For Left side
        else if (arr[mid] >= arr[0])
        {
            if (arr[start] <= num && num <= arr[mid])

            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }

        // For Right side
        else
        {

            if (arr[mid] < num && arr[mid] <= num)
            {
                start = mid + 1;
            }

            else
            {
                end = mid - 1;
            }
        }
    }

    cout << "Position of search number in Rotated Array: " << ans;
}
