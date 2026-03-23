#include <stdio.h>

int main()
{
    int size, n, position,i,input, value;

    printf("Enter the size in the array: ");
    scanf("%d", &size);    

    int arr[size];

    printf("Enter number of elements in the array: ");
    scanf("%d", &n);
    
    printf("Enter %d elements:\n", n);
    
    for (i = 0; i < n; i++){    
        scanf("%d", &arr[i]);}

    printf("\n1.Insertion\n2.Deletion\nEnter 1 or 2 :");
    scanf("%d",&input);


    // INSERTION PART
   if(input==1){

    printf("\nEnter Insertion location for the element:\n");
    scanf("%d", &position);
    
    printf("Please enter the value: ");
    scanf("%d", &value);
    
    for (i = n - 1; i >= position - 1; i--)    
        arr[i+1] = arr[i];
    
    arr[position-1] = value;
    }


   // DELETION PART
   else if (input==2)
    {
    printf("\nEnter Deletion location for the element:\n");
    scanf("%d", &position);
    
    if(position==n){
    printf("Resultant array is\n");  
    for (i = 0; i < n-1; i++)  {
        printf("%d\n", arr[i]);    }
    
    return 0;
    }

    else if (position==1)
    {
    
    for(int i=0;i<n-1;i++){
        arr[i]=arr[i+1];
    }
printf("Resultant array is\n");  
    for (i = 0; i < n-1; i++)  {
        printf("%d\n", arr[i]);    }
       
    }
    
    else if (position>1&&position<n)
    {


        
    }
    
    else{
        printf("Invalid Input");
    }
        
    }
    
 
 else
 {
    printf("INVALID INPUT");
    return 1;
 }
 


   
}