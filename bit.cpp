#include <iostream>
#include<string>
using namespace std;

int main() {
    int n;
    cin >> n;

    int result =0;


    while (n--) {
        string a;
        cin>>a;
        if (a == "X++" || a == "++X") {result++;}
        else if (a =="X"){result = result+0;}
        else {result--;}
    }

    cout<<result;

    return 0;
}