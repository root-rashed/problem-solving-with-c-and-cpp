#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;
    Node* prev;
};

class Linked_List
{
    Node* head;
    Node* tail;

public:
    Linked_List()
    {
        head = NULL;
        tail = NULL;
    }


    void add_node(int n)
    {
        Node* tmp = new Node();
        tmp->data = n;
        tmp->next = NULL;
        tmp->prev = NULL;

        if (head == NULL)
        {
            head = tmp;
            tail = tmp;
        }
        else
        {
            tail->next = tmp;
            tmp->prev = tail;
            tail = tmp;
        }
    }


    void delete_node(int value)
    {
        Node* current = head;

        while (current != NULL && current->data != value)
        {
            current = current->next;
        }

        if (current == NULL)
        {
            cout << "Value not found in the list." << endl;
            return;
        }

        if (current->prev != NULL)
            current->prev->next = current->next;
        else
            head = current->next;

        if (current->next != NULL)
            current->next->prev = current->prev;
        else
            tail = current->prev;

        delete current;
        cout << "\nNode with value " << value << " deleted." << endl;
    }


    void print()
    {
        Node* i = head;
        while (i != NULL)
        {
            cout << i->data << " ";
            i = i->next;
        }
        //cout << "NULL" << endl;
    }
};


int main()
{
    Linked_List A;
    for (int i = 1; i <= 10; ++i){
        A.add_node(i * 10);}

    cout << "Original List:" << endl;
    A.print();

    A.delete_node(30); // Delete node with value 30
    cout << "After Deletion:" << endl;
    A.print();

    return 0;
}