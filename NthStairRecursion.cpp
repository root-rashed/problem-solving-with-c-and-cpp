#include<iostream>
using namespace std;

//Print 1 to using recursion
int process(int num){

    if(num <=1) {      
       return 1; }   
         
 return process(num-1)+process(num-2);

} 


int main()
{
    int Nth=4;
  cout<<process(Nth)<<endl;
 
}