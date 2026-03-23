#include <iostream>
using namespace std;
int main()
{

    int arr[5] = {2, 7, 11, 15, 27};
    int size = 5;

    int sum = 9;

    for (int i = 0; i < size - 1; i++)
    {

        int x = sum - arr[i];
        int start = i + 1;
        int end = size - 1;

        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (arr[mid] == x)
            {
                cout << "found: " << arr[i] << " " << arr[mid];
                break;
            }
            else if (arr[mid] > x)
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
    }
}