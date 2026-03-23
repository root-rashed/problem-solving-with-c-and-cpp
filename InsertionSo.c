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


    for (int i = 1; i < n; i++) 
    {
        double key = a[i];      // Store the current element to insert in the  // বর্তমান উপাদানটি সংরক্ষণ করা যা সাজানো অংশে ঢোকানো হবে।
        int j = i - 1;          // Start comparing from the element just before the current one. // বর্তমান উপাদানের আগে থেকে তুলনা শুরু।

        // Shift elements of the sorted portion to the right if they are greater than 'key'.  // যদি উপাদানটি 'key'-এর চেয়ে বড় হয়, তবে তা ডানদিকে সরানো।
        while (j >= 0 && a[j] > key) 
        {
            a[j + 1] = a[j];    // Move the larger element one position to the right.    // বড় উপাদানকে এক ধাপ ডানে সরানো।
            j--;                // Move one position to the left for further comparison. // আরও তুলনার জন্য এক ধাপ বামে যাওয়া।
        }


        a[j + 1] = key;         // Place the 'key' in its correct position in the sorted portion.
                                // 'key'-কে তার সঠিক স্থানে রাখুন।
    }




    printf("Sorted array in ascending order:\n");
    for (int i = 0; i < n; i++) {
        printf("%.3lf ", a[i]); 
    }
    printf("\n"); 

    return 0; 
}