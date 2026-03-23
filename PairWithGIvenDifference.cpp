#include <iostream>
using namespace std;
int main()
{

    int arr[5] = {3, 7, 8, 11, 25};
    int size = 5, start = 0, end = 1, target;
    cout << "Enter target Difference: ";
    cin >> target;

    while (end < size)
    {
        if (arr[end] - arr[start] == target)
        {
            cout << "Found: " << arr[start] << " " << arr[end];
            break;
        }
        else if (arr[end] - arr[start] < target)
        {

            end++;
        }
        else
        {
            start++;
        }
    }
}