#include<iostream>
using namespace std;

class customer
{

    string name;
    int acc;
    int balance;

    public:
    /// Default constructor
    customer()
   {
            name = "Rashed";
            acc = 1;
            balance = 5;
   }

   /// parameterized constructor [For 3 passing]
    customer(string a, int b, int c)
    {
        name =a; 
        acc = b;
        balance = c;
    }


   /// parameterized constructor [For 2 passing] OVERLOADING
    customer(string a, int b)
    {
        name = a;
        acc = b;
       
    }

    // Output
    void  display()
    {
        cout<<name<<" "<<acc<<" "<<balance<<endl;
    }
     
     // Copy constructor
    customer(customer &B){

    name =B.name;
    acc =B.acc;
    balance=B.balance;

    }


};

    int main()
    {

    customer a1;
    customer a2("rashed",5,100);
    customer a3("sabit",6);
    customer a4(a2);
    a1.display();
    a2.display();
    a3.display();
    a4.display();
    }