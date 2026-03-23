#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

int main() 
{
    struct node *front = NULL, *rear = NULL, *newnode = NULL;
    int data, i;

    // Creating the linked list with 5 nodes
    for (i = 1; i <= 5; i++) 
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        if (newnode == NULL) {
            printf("Memory allocation failed\n");
            return 1;
        }

        printf("Enter data for node %d: ", i);
        scanf("%d", &data);
        newnode->data = data;
        newnode->next = NULL;

        if (front == NULL) { 
            // First node
            front = rear = newnode;
        } else { 
            // Subsequent nodes
            rear->next = newnode;
            rear = newnode;
        }
    }

    // Displaying the linked list
    printf("The linked list is: ");
    struct node *temp = front;
    while (temp != NULL) 
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    // Freeing allocated memory
    temp = front;
    while (temp != NULL) 
    {
        struct node *next = temp->next;
        free(temp);
        temp = next;
    }

    return 0;
}
