#include <iostream>
#include <cstring>
using namespace std;

void selectionSort(char arr[][10], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIdx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (strcmp(arr[j], arr[minIdx]) < 0)
                minIdx = j;
        }
        // Swap the found minimum element with the first element
        char temp[10];
        strcpy(temp, arr[i]);
        strcpy(arr[i], arr[minIdx]);
        strcpy(arr[minIdx], temp);
    }
}

int main()
{
    char names[5][10] = {"prio", "rashed", "hasan", "sakib", "zakir"};
    int n = sizeof(names) / sizeof(names[0]);

    selectionSort(names, n);

    cout << "Sorted Names: ";
    for (int i = 0; i < n; i++)
        cout << names[i] << " ";
    cout << endl;

    return 0;
}