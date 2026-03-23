#include<iostream>
using namespace std;

//Answer part
int power(int b,int num){

    if(num ==0) {      
       return 1; }   
         
 return b*power(b,num-1);

} 


int main()
{
    int b,n;
    cout<<"Enter base : ";
    cin>>b;
    cout<<"Enter power : ";
    cin>>n;
    cout<<"Answer: "<<power(b,n)<<endl;
}