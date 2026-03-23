#include <stdio.h>

int main() {
    int n, e;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int a[n];
    printf("Enter the number of elements you want to insert: ");
    scanf("%d", &e);

    if (e > n) {
        printf("Number of elements exceeds array size.\n");
        return 1;
    }

   
    printf("Enter the elements:\n");
    for (int i = 0; i < e; i++) {
        scanf("%d", &a[i]);
    }

    int pos; 
    printf("Enter the even index position to delete (0, 2, 4,...): ");
    scanf("%d", &pos);

    if (pos < 0 || pos >= e || pos % 2 != 0) {
        printf("Invalid position. Please enter a valid even index.\n");
        return 1;
    }


    for (int i = pos; i < e - 1; i++) 
    {      
        a[i] = a[i + 1];
    }
    e--;



    printf("Array after deletion: ");
    for (int i = 0; i < e; i++) 
    {
        printf("%d ", a[i]);
    }
    printf("\n");   
    return 0; 
}