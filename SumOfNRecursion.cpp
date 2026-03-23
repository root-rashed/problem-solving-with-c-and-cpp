#include<iostream>
using namespace std;

//Factorial using recursion
int sum(int num){

    if(num ==1) {      
       return 1; }   
         
 return num+sum(num-1);

} 


int main()
{
    int n;
    cout<<"Enter n: ";
    cin>>n;
    cout<<"Sum of n number: "<<sum(n)<<endl;
}