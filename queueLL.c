#include <stdio.h>
#include <stdlib.h>

// Node structure
struct node {
    int data;
    struct node *next;
} *front = NULL, *rear = NULL;

// Function to enqueue (insert) an element
void enqueue(int data) {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    newnode->data = data;
    newnode->next = NULL;

    if (rear == NULL) {
        front = rear = newnode;  // First element case
    } else {
        rear->next = newnode;
        rear = newnode;
    }
    printf("Enqueued: %d\n", data);
}

// Function to dequeue (delete) an element
void dequeue() {
    if (front == NULL) {
        printf("Queue is empty!\n");
        return;
    }

    struct node *temp = front;
    printf("Dequeued: %d\n", front->data);
    front = front->next;

    if (front == NULL) {
        rear = NULL; // Reset queue if empty
    }

    free(temp);
}

// Function to display the queue
void display() {
    struct node *temp = front;
    if (temp == NULL) {
        printf("Queue is empty!\n");
        return;
    }
    
    printf("Queue: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function
int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);

    display();

    dequeue();
    dequeue();

    display();

    return 0;
}
