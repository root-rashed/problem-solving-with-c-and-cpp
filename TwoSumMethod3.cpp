#include <iostream>
using namespace std;
int main()
{

    int arr[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int size = 9, start = 0, End = size - 1, target;
    cout << "Enter target sum: ";
    cin >> target;

    while (start < End)
    {
        if (arr[start] + arr[End] == target)
        {
            cout << "Found: " << arr[start] << " " << arr[End];
            break;
        }
        else if (arr[start] + arr[End] < target)
        {

            start++;
        }
        else
            End--;
    }
}
