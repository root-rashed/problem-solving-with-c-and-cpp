#include<iostream>
using namespace std;

//Print array using Recursion
void Print(int arr[],int index){

        if(index == -1){
            return;

        };

        Print(arr,index-1);
        cout<<arr[index]<<" ";
        

} 


int main()
{
    int arr[5] = {1,2,3,4,5};

    Print(arr,4);
}