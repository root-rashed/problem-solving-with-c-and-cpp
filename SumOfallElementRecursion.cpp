#include<iostream>
using namespace std;

//Print array using Recursion
int Sum(int arr[],int index){


        if(index == -1){
            return 0;

        };

        return arr[index]+ Sum(arr,index-1);       

} 


int main()
{
    int arr[5] = {1,2,3,4,5};

   cout<<"Answer: "<<Sum(arr,4)<<endl;
}