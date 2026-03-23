#include<iostream>
using namespace std;

//Print 1 to using recursion
void Print(int num){

    if(num == 1) {

       cout<<1<<endl;
       return;
       
    }
    Print(num-1);
    cout<<num<<endl;
    }


int main()
{
    int N=10;
    Print(N);

}