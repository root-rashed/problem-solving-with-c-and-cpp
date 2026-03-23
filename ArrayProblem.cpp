#include<iostream>
using namespace std;

int main()
{
int size,elem,value,posi;
printf("Enter size: ");
scanf("%d",&size);

int arr[size];

cout<<"Enter number of element: ";
scanf("%d",&elem);


printf("Enter elements: ");
for(int i=0;i<elem;i++)
{
scanf("%d",&arr[i]);
}

printf("Enter the even index position 2/4/6/8... : ");
scanf("%d",&posi);

printf("Enter the value to add: ");
scanf("%d",&value);
elem++;

for(int i=elem;i>posi;i--)
{
 arr[i]= arr[i-1];
}

arr[posi]= value;

for(int i=0;i<elem;i++){
    printf("%d ",arr[i]);
}

return 0;

}