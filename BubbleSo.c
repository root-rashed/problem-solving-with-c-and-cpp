#include <stdio.h>
int main() {
    int size,n;
    printf("Enter the size of the array: ");
    scanf("%d", &size); 
    int a[size]; 
    printf("Enter the number of elements of the array: ");
    scanf("%d",&n); 
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) { 
        scanf("%d", &a[i]); 
    }

    // Sorting the array in ascending order using nested loops.

    for (int i = 0; i < n-1; i++) { // Outer loop to pass calculate
        for (int j = 0; j < n-1-i; j++) { // Inner loop to compare with subsequent elements.
            if (a[j] > a[j+1]) {
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }

    printf("Sorted array in ascending order:\n");
    for (int i = 0; i < n; i++) { 
        printf("%d ", a[i]); 

    }
    printf("\n"); 
    return 0; 

}