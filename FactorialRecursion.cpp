#include<iostream>
using namespace std;

//Factorial using recursion
int fact(int num){

    if(num ==0) {      
       return 1; }   
         
 return num*fact(num-1);

} 


int main()
{
    int n;
    cout<<"Enter n: ";
    cin>>n;
    if(n<0){
    cout<<"Factorial is not possible"<<endl;
    return 0;
    }
  cout<<"Factorial of n number: "<<fact(n)<<endl;
}