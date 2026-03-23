#include<iostream>
using namespace std;

class Customer
{
  string name;
  int accnum,balance;  
  static int total_customer;
public:

Customer(string name,int accnum,int balance)
{
this->name =name;
this->accnum =accnum;
this->balance =balance;
total_customer++;
}

void display(){

    cout<<name<<" "<<accnum<<" "<<balance<<" "<<total_customer<<endl;
}

};

int Customer::total_customer=0;

int main(){

Customer a1("Rashed",123,123);
Customer a2("sabit",123,123);
Customer a3("Prio",123,123);
a1.display();
a2.display();
a3.display();

}



