#include <stdio.h>
#include <stdlib.h>

// Structure of a node
struct node {
    int data;
    struct node *next;
} *header = NULL; 

// Function prototype
void createlinkedlist(int n);

// Main function
int main() {
    int n;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    // Creating the linked list
    createlinkedlist(n);

    return 0;
}

// Function to create the linked list
void createlinkedlist(int n) {
    struct node *newnode, *temp;
    int data, i;

    // Allocate memory and create nodes
    for (i = 1; i <= n; i++) {
        // Allocate memory for a new node
        newnode = (struct node *)malloc(sizeof(struct node));
        if (newnode == NULL) {
            printf("Unable to allocate memory. Exiting.\n");
            exit(1); // Exit the program if memory allocation fails
        }

        // Input data for the node
        printf("Enter data for node %d: ", i);
        scanf("%d", &data);

        // Initialize the new node
        newnode->data = data;
        newnode->next = NULL;

        // If it's the first node, set it as the header
        if (header == NULL) {
            header = newnode;
        } else {
            temp->next = newnode; // Link the previous node to the new node
        }

        temp = newnode; // Move the temp pointer to the current node
    }
}
