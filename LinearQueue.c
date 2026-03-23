#include <stdio.h>
#include <stdlib.h>

int front = -1;
int rear = -1;
int size = 0;
int Q[100]; 

// Function to set the size of the queue.
void sizeofqueue(int n) 
{
    size = n;      // Set the maximum size of the queue.
    front = -1;    // Initialize front pointer to -1.
    rear = -1;     // Initialize rear pointer to -1.
}

// Function to add an element to the queue.
void enqueue(int element) 
{
    // Check if the queue is full.
    if (rear == size - 1) 
    {
        printf("Queue is full!!! Cannot enqueue! %d\n", element);
    }

     else 
    {
        if (front == -1) {front = 0;}
        rear++;           
        Q[rear] = element; 
        printf("Enqueued value: %d\n", element);
    }
}

// Function to remove an element from the queue.
void dequeue() {
    if (front == -1 || front > rear) 
    {       
        printf("Queue is empty!!! No elements to dequeue!\n");
    } 
    else 
    {
        printf("Dequeued element: %d\n", Q[front]);
        front++; 
    }
}

// Function to display all elements in the queue.
void displayQueue() {
    if (front == -1 || front > rear) {
        printf("--Queue is empty-- No elements to display\n");
    } 
    else 
    {
       printf("Queue elements: ");
        for (int i = front; i <= rear; i++) 
        {
            printf("%d ", Q[i]);
        }
        printf("\n");
    }
}

// Function to display the front element of the queue.
void displayFront() {
    if (front == -1 || front > rear) 
    {
        printf("Queue is empty! No front element to display\n");
    } 
    else 
    {
        printf("Front element: %d\n", Q[front]);
    }
}



int main() {
    int n, ch, element;
    printf("Enter the size of the queue: ");
    scanf("%d", &n);
    sizeofqueue(n); 

    do {

        // Print the menu.
        printf("\nOptions:\n");
        printf("1) Enqueue\n");
        printf("2) Dequeue\n");
        printf("3) Display Front\n");
        printf("4) Display All\n");
        printf("5) Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        // Perform operations based on the user's choice.
        switch (ch) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &element);
                enqueue(element);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                displayFront();
                break;
            case 4:
                displayQueue();
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (ch != 5);
    
    return 0;
}