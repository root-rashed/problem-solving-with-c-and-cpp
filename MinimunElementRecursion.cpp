#include<iostream>
using namespace std;

//Find Minumun element
int minimum(int arr[],int index){


        if(index == 4){
            return arr[index];

        };

        return min(arr[index],minimum(arr,index+1));       

} 


int main()
{
    int arr[5] = {1,2,3,4,5};

   cout<<"Answer: "<<minimum(arr,0)<<endl;
}