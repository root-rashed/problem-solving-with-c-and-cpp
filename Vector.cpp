#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> v = {1, 2, 3, 4, 5};
    v.push_back(6);
    v.push_back(7);
    v.push_back(8);
    v.push_back(9);
    v.push_back(10);

    v.pop_back();               // Remove last Element
    v.front();                  // Show first Element
    v.back();                   // Show last Element
    v.at(3);                    // To see which Element is at that Index
    v.erase(v.begin() + 2);     // To remove specific Element
    v.insert(v.begin() + 2, 3); // To Insert specific Element
    v.clear();                  // To clear all the element
    v.empty();                  // show vector empty or not

    cout << v.capacity() << endl;
    cout << v.size();
}