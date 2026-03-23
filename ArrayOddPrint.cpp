#include<stdio.h> 
int main() {
    
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    printf("Enter the number of elements to input (<= %d): ", n);
    scanf("%d", &m);

    
    if (m > n) {
        printf("Error: Number of elements cannot exceed the array size.\n");
        return 1;
    }

    int a[n]; 

    
    printf("Enter %d elements:\n", m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &a[i]);
    }

   
    printf("Even elements from the array are: ");
    for (int i = 0; i < m; i++) {
        if (a[i] % 2 == 0) { 
            printf("%d ", a[i]);
        }
    }

   

    return 0; 
}