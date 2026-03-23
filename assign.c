#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MODEL_LENGTH 100 // Increased size for full input line

// Car structure
typedef struct
{
    int id;
    char model[MAX_MODEL_LENGTH];
    int price;
    int year;
    int index; // To maintain original order
} Car;

// Merge function to merge two sorted halves
void merge(Car cars[], int left, int mid, int right)
{
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Dynamic allocation for temporary arrays
    Car *L = (Car *)malloc(n1 * sizeof(Car));
    Car *R = (Car *)malloc(n2 * sizeof(Car));

    if (L == NULL || R == NULL)
    {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    // Copy data to temporary arrays
    for (i = 0; i < n1; i++)
        L[i] = cars[left + i];
    for (j = 0; j < n2; j++)
        R[j] = cars[mid + 1 + j];

    // Merge the temp arrays back into cars[]
    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2)
    {
        if (L[i].price < R[j].price ||
            (L[i].price == R[j].price && L[i].year > R[j].year) ||
            (L[i].price == R[j].price && L[i].year == R[j].year && L[i].index < R[j].index))
        {
            cars[k++] = L[i++];
        }
        else
        {
            cars[k++] = R[j++];
        }
    }

    // Copy remaining elements, if any
    while (i < n1)
        cars[k++] = L[i++];
    while (j < n2)
        cars[k++] = R[j++];

    // Free allocated memory
    free(L);
    free(R);
}

// Merge Sort function
void mergeSort(Car cars[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        // Sort first and second halves
        mergeSort(cars, left, mid);
        mergeSort(cars, mid + 1, right);

        // Merge the sorted halves
        merge(cars, left, mid, right);
    }
}

int main()
{
    int N;
    scanf("%d", &N);
    getchar(); // Consume leftover newline

    if (N < 1 || N > 100000)
    {
        printf("Invalid input. N must be between 1 and 100000.\n");
        return 1;
    }

    // Dynamic memory allocation to prevent stack overflow
    Car *cars = (Car *)malloc(N * sizeof(Car));
    if (cars == NULL)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }

    char line[MAX_MODEL_LENGTH]; // Buffer for full line input

    // Taking input
    for (int i = 0; i < N; i++)
    {
        fgets(line, sizeof(line), stdin); // Read entire line

        // Remove newline character from input
        strtok(line, "\n");

        // Parse input correctly
        sscanf(line, "%d %[^\t] %d %d", &cars[i].id, cars[i].model, &cars[i].price, &cars[i].year);
        cars[i].index = i; // Store original order
    }

    // Sorting the cars using Merge Sort
    mergeSort(cars, 0, N - 1);

    // Printing sorted results
    printf("\nSorted Cars:\n");
    for (int i = 0; i < N; i++)
    {
        printf("%d %s %d %d\n", cars[i].id, cars[i].model, cars[i].price, cars[i].year);
    }

    // Free allocated memory
    free(cars);

    return 0;
}
