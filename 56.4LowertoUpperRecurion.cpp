#include<iostream>
using namespace std;

//lower to upper
void lowertoupper(string &str,int index){


        if(index == -1)   { return;}

        str[index] = 'A'+ str[index]-'a';
        lowertoupper(str,index-1);
} 


int main()
{
    string str="rashed";
    lowertoupper(str,5);

   cout<<str<<endl;
}