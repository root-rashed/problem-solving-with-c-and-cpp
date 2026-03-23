#include <stdio.h>
int main()
{
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n); 

    double a[n];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%lf", &a[i]);
    }

    for (int i =0; i < n - 1; i++) 
    {
        int id = i; // Assume the current index 'i' has the minimum value.
                    // ধরা হচ্ছে বর্তমান ইনডেক্স 'i' তে সর্বনিম্ন মান আছে।
        for (int j = i + 1; j < n; j++) 
        {
            if (a[j] < a[id]) 
            {                // If a smaller element is found, update 'id'. // যদি ছোট উপাদান পাওয়া যায়, তাহলে 'id' আপডেট।
            id = j;          // Update 'id' to store the index of the minimum value // 'id' তে সর্বনিম্ন মানের ইনডেক্স সংরক্ষণ।
            }
        }

        if (id != i) 
        {
            double temp = a[i]; 
            a[i] = a[id];       
            a[id] = temp;                               
        }
    }
   
    printf("Sorted array in ascending order:\n");
    for (int i = 0; i < n; i++) {
        printf("%.3lf ", a[i]); 
        }

    return 0;
}