#include <iostream>
using namespace std;
int main()
{

    int arr[5] = {2, 7, 11, 15, 27};
    int size = 5;
    int sum = 18;

    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; i < size; j++)
        {
            if (arr[i] + arr[j] == sum)
            {
                cout << "Found" << arr[i] << " " << arr[j];
                break;
            }
        }
    }
}