#include <stdio.h>
#include <stdlib.h>


// Global variables for the queue's front, rear, and size.
int front = -1, rear = -1, size = 0;
int Q[100]; // Queue array with a fixed maximum size of 100.


// Function to set the size of the queue.
void sizeofqueue(int n) {
    size = n;      // Set the maximum size of the queue.
    front = -1;    // Initialize front pointer to -1.
    rear = -1;     // Initialize rear pointer to -1.
}


// Function to add an element to the queue.
void enqueue(int element) {

    // Check if the queue is full.
    if (rear == size - 1) {
        printf("Queue is full!!! Cannot enqueue! %d\n", element);
    } else {
        if (front == -1) front = 0;
        // If it's the first element, set front to 0.
        rear++;           // Increment the rear pointer.
        Q[rear] = element; // Add the element to the queue.
        printf("Enqueued value: %d\n", element);
    }
}


// Function to remove an element from the queue.
void dequeue() {
    if (front == -1 || front > rear) {

        // If the queue is empty or all elements have been dequeued.
        printf("Queue is empty!!! No elements to dequeue!\n");
    } else {

        // Remove the element from the front.
        printf("Dequeued element: %d\n", Q[front]);
        front++; // Move the front pointer to the next element.
    }
}


// Function to display all elements in the queue.
void displayQueue() {
    if (front == -1 || front > rear) {

        // If the queue is empty.
        printf("--Queue is empty-- No elements to display\n");
    } else {

        // Print the queue elements.
        printf("Queue elements: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", Q[i]);
        }
        printf("\n");
    }
}


// Function to display the front element of the queue.
void displayFront() {
    if (front == -1 || front > rear) {

        // If the queue is empty.
        printf("Queue is empty! No front element to display\n");
    } else {

        // Print the front element.
        printf("Front element: %d\n", Q[front]);
    }
}


// Main function to handle menu-based operations.
int main() {
    int n, ch, element;


    // Taking the size of the queue from the user.
    printf("Enter the size of the queue: ");
    scanf("%d", &n);
    sizeofqueue(n); // Set the size of the queue.

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

                // Enqueue option.
                printf("Enter value to enqueue: ");
                scanf("%d", &element);
                enqueue(element); // Call the enqueue function.
                break;
            case 2:

                // Dequeue option.
                dequeue(); // Call the dequeue function.
                break;
            case 3:

                // Display front option.
                displayFront(); // Call the displayFront function.
                break;
            case 4:

                // Display all option.
                displayQueue(); // Call the displayQueue function.
                break;
            case 5:

                // Exit option.
                printf("Exiting program.\n");
                break;
            default:

                // If the user's choice is invalid.
                printf("Invalid choice. Please try again.\n");
        }
    } while (ch != 5);
    // Keep running the menu until the user chooses to exit.

    return 0;
    // End the program successfully.
}