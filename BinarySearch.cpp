#include <iostream>
using namespace std;
int main()
{
    int arr[10] = {20, 18, 16, 14, 12, 10, 8, 6, 4, 2};
    int n = 10, start = 0, end = n - 1, searchNumber;

    cout << "Enter number:  ";
    cin >> searchNumber;

    while (start <= end)
    {

        int mid = (start + end) / 2;

        if (arr[mid] == searchNumber)
        {
            cout << "Found it at position " << mid + 1; // If the number is in Middle position
            break;
        }

        else if (searchNumber > arr[mid]) // If the number is present in Left side
        {
            end = mid - 1;
        }

        else
        {
            start = mid + 1; // If the number is present in Right side
        }
    }
}