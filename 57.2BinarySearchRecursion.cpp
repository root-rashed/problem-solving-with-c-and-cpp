#include<iostream>
using namespace std;

bool Binarysearch(int arr[],int start,int end, int X){

    //end case
    if(start>end)
    return 0;

    //mid case
    int mid = start+(end-start)/2;
    if(arr[mid]==X)
    return 1;
    //right side
    else if(arr[mid]<X){
    return Binarysearch(arr,mid+1,end,X);}
    //left side
    else
    return Binarysearch(arr,start,mid-1,X);

}


int main(){

    int arr[] = {2,3,6,7,1,5};
    int X =8;
    cout<<Binarysearch(arr,0,6,X)<<endl;

}