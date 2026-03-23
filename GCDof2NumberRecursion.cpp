#include<iostream>
using namespace std;

//gcd part
int gcd(int num1, int num2){

    if(num2 == 0) {      
       return num1; }   
         
  return gcd(num2, num1%num2);

} 


int main()
{
    int n,m;
    cout<<"Enter n : ";
    cin>>n;
    cout<<"Enter m : ";
    cin>>m;

    if(m>n){swap(n,m);}
    
    
    cout<<"Answer: "<<gcd(n,m)<<endl;
}