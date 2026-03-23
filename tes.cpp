#include <stdio.h>

int main() {
    int n, e;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int a[n]; 
    printf("Enter the number of elements you want to insert: ");
    scanf("%d", &e);

    if (e > n) {
        printf("Number of elements to insert exceeds array size.\n");
        return 1;
    }

    printf("Enter the elements:\n");
    for (int i = 0; i < e; i++) {
        scanf("%d", &a[i]);
    }

    int oddcnt = 0, evencnt = 0;

    for (int i = 0; i < e; i++) {
        if (a[i] % 2 == 0) {
            evencnt++; 
        } else {
            oddcnt++;
        }
    }

    if (evencnt >= 2) 
    {
        int delcnt = 0;

        for (int i = e - 1; i >= 0 && delcnt < 2; i--) 
        {
            if (a[i] % 2 == 0) 
            {
                for (int j = i; j < e - 1; j++) 
                {
                    a[j] = a[j + 1];
                }
                e--;
                delcnt++;
            }
        }
    } 
    
    else if (evencnt == 1) 
    {
        int newelem[2];
        printf("Enter two elements to insert: ");
        for (int i = 0; i < 2; i++) {
            scanf("%d", &newelem[i]);
        }

        for (int i = e - 1; i >= e / 2; i--) {
            a[i + 2] = a[i];
        }

        a[e / 2] = newelem[0];
        a[(e / 2) + 1] = newelem[1];
        e += 2; 
    } 

    else 
    {
        int middle = e / 2; 
        for (int i = middle; i < e - 1; i++) {
            a[i] = a[i + 1];
        }
        e--;

        int newelem;
        printf("Enter an element to insert: ");
        scanf("%d", &newelem);

        for (int i = e - 1; i >= middle; i--) {
            a[i + 1] = a[i];
        }

        a[middle + 1] = newelem;
        e++; 
    }

   
    printf("Final array: ");
    for (int i = 0; i < e; i++) 
    {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}