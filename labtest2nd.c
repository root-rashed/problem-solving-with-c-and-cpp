#include <stdio.h>
int main()
{
    int inserted_element, size;

    // Input array size
    printf("Enter size of the array: ");
    scanf("%d", &size);

    // Input array elements
    int arr[size];
    printf("Enter elements: ");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Input element to check
    printf("Enter element to check: ");
    scanf("%d", &inserted_element);

    // Check if the element is present or not
    int found = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == inserted_element)
        {
            found = 1;
            printf("Inputted element is present in the array.\n");
            break;
        }
    }

    if (found == 0)
    {
        // Shift elements to the right
        for (int i = size - 1; i >= 0; i--)
        {
            arr[i + 1] = arr[i];
        }
        // Insert the new element at the beginning
        arr[0] = inserted_element;
        size++;

        printf("After inserting the element at the beginning: ");
        for (int i = 0; i < size; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }

    return 0;
}
