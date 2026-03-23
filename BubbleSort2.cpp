#include <stdbool.h>
#include <stdio.h>
void swap(int* xp, int* yp){
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// An optimized version of Bubble Sort
void bubbleSort(int arr[], int n){
    int i, j,cout=0;
    for (i = 0; i <n-1; i++) 
    {
        for (j = 0; j < n-1; j++) {
            if (arr[j] < arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                cout++;
            }

        for(int i=0;i<n;i++)
        {
            printf("%d ",arr[i]);
        }
        printf("\n");
        
        }
        printf("\n%d",cout);
    printf("\n");
    }
}

// Function to print an array
void printArray(int arr[], int size){
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
}

int main(){
    int arr[] = { 61,19,13,7,46,15,4,12 };
    int n = sizeof(arr) / sizeof(arr[0]);
    bubbleSort(arr, n);
    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}
