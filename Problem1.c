#include <stdio.h>

int main() {

    int size;
    // input the size of the array
    printf("Enter size of the array: ");
    scanf("%d", &size);

    // Check size valid or not
    if (size <= 0) {
        printf("Invalid array size!\n");
        return 1;
    }

    // Calculate quarter size
    int quarSize = size / 4;
    if (quarSize == 0) 
    {
        printf("Array size is small.\n");
        return 1;
    }

    //array declaration
    int arr[quarSize];

    // input array elements
    printf("Enter %d elements(quarter of size):\n", quarSize);
    for (int i = 0; i < quarSize; i++) {
        scanf("%d", &arr[i]);
    }

    // selection sort in descending order
    for (int i = 0; i < quarSize - 1; i++) {
        int maxind = i;
        for (int j = i + 1; j < quarSize; j++) {
            if (arr[j] > arr[maxind]) {
                maxind = j;
            }
        }
        // swap the maximum element with the first element
        int temp = arr[maxind];
        arr[maxind] = arr[i];
        arr[i] = temp;
    }

    // print the array
    printf("Sorted array in descending order: ");
    for (int i = 0; i < quarSize; i++) 
    {
        printf("%d ", arr[i]);
    }

    return 0;
}
