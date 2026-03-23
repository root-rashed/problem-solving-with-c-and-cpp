#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;   
    struct node *pre;
    struct node *next;
} *header, *tail;

int main() {
    int data, i;
    struct node *newnode, *temp;

    // Initialize the header
    header = NULL;
    tail = NULL;

    // Create 5 nodes
    for (i = 1; i <= 5; i++) {
        newnode = (struct node *)malloc(sizeof(struct node));

        printf("Enter data for node %d: ", i);
        scanf("%d", &data);
        newnode->data = data;
        newnode->pre = NULL;
        newnode->next = NULL;

        if (header == NULL) {
            // First node
            header = newnode;
            tail = newnode;
        } else {
            // Subsequent nodes
            tail->next = newnode;
            newnode->pre = tail;
            tail = newnode;
        }
    }

    // Print the list
    printf("\nDoubly linked list data: ");
    temp = header;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}



