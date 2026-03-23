#include<iostream>
using namespace std;

//Count vowel
bool checkpal(string str,int start, int end){

    // base condition
      if(start>=end)   { return 1;}

     
     //not matched
     if(str[start]!=str[end]) 
     return 0;

     //matched
     else
     {
        return checkpal(str,start+1,end-1);
     }
     


int main()
{ string str="MOM";
   cout<<checkpal(str,0,2)<<endl;
}