#include<iostream>
using namespace std;
//Answer part
int square(int num){

    if(num ==0) {      
       return 0; }   
         
 return num*num+square(num-1);

} 


int main()
{
    int n;
    cout<<"Enter n : ";
    cin>>n;
    cout<<"Answer: "<<square(n)<<endl;
}