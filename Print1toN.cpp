#include<iostream>
using namespace std;

//Print 1 to using recursion
void Print(int num,int N){

    if(num == N) {

      cout<<num<<endl;
       return;
       
    }
    cout<<num<<endl;
    Print(num+1,N);
    }


int main()
{
    int N=10;
    Print(1,N);

}