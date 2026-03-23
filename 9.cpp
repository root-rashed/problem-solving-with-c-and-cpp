#include<iostream>
using namespace std;

struct Queue{
    int queue_size;
    int q_front;
    int q_rear;
    int occupied;
    int *items;
};

Queue * createQueue(int capacity){
    Queue * pt = new Queue();
    pt->queue_size = capacity;
    pt->q_front = 0;
    pt->q_rear = 0;
    pt->occupied = 0;
    pt->items = new int[capacity];
    return pt;
}

int isFull(Queue *pt){
    return pt->occupied == pt->queue_size;
}

int isEmpty(Queue * pt){
    return pt->occupied == 0;
}

void enqueue(Queue* pt, int data){
    if(isFull(pt)){
        cout << "Queue is full" << endl;
    }
    else{
        cout << "Enqueued value " <<data<< endl;
        pt->items[pt->q_rear] = data;
        pt->q_rear = (pt->q_rear + 1) % pt->queue_size;
        pt->occupied++;
    }
}

void dequeue(Queue* pt){
    if(!isEmpty(pt)){
         cout << "Dequeued value " << endl;
        pt->q_front = (pt->q_front + 1) % pt->queue_size;
        pt->occupied--;
    }
    else{
        cout << "Queue is empty" << endl;
    }
}

int top(Queue * pt){
    if(isEmpty(pt)){
        cout << "Queue is empty" << endl;
        return -1;
    }
    else
        return pt->items[pt->q_front];
}

void printQueue(Queue *pt){
    if(isEmpty(pt)){
        cout << "Queue is empty" << endl;
        return;
    }
    int i = pt->q_front;
    int count = pt->occupied;
     cout << "Queue: ";
    while(count--){
        cout << pt->items[i] << " ";
        i = (i + 1) % pt->queue_size;
    }
    cout << endl;
}


int main(){
    Queue * q1 = createQueue(5);
    
    enqueue(q1, 10);
    enqueue(q1, 20);
    enqueue(q1, 30);
    printQueue(q1);

    dequeue(q1);
    printQueue(q1);

    enqueue(q1, 40);
    printQueue(q1);

    return 0;
}
