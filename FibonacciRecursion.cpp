#include<iostream>
using namespace std;

//Print 1 to using recursion
int Fibo(int num){

    if(num <= 1) {      
       return num;      
    }
return Fibo(num-1)+Fibo(num-2);

}

int main()
{
    int Nth=10;
  cout<<Fibo(Nth)<<endl;

}