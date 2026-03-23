#include <stdio.h>
#include <stdlib.h>

// Node structure
struct node {
    int data;
    struct node *pre;
    struct node *next;
} *header = NULL, *tail = NULL;


int main() 
{
    struct node *newnode, *temp;
    int data;

    // Creating the linked list
    for (int i = 1; i <= 5; i++) {
        newnode = (struct node *)malloc(sizeof(struct node));
        if (newnode == NULL) {
            printf("Memory allocation failed!\n");
            return 1;
        }

        printf("Enter %d node data: ", i);
        scanf("%d", &data);

        newnode->data = data;
        newnode->pre = NULL;
        newnode->next=NULL;

        if (header == NULL) {
            header = tail = newnode;  // Initialize header and tail
        } else {
            tail->next = newnode;
            newnode->pre=tail->next;
            tail = tail->next;
           
        }
    }


    // Display linked list
    temp = header;
    printf("Before delete Data: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }


    tail=tail->pre;
    tail->next=NULL;
    free(temp);

    temp = header;
    printf("\nAfter delete Data: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }




    printf("\n");

        
}















// // Singly linked list
// int main() {
//     struct node *newnode, *temp;
//     int data;

//     // Creating the linked list
//     for (int i = 1; i <= 5; i++) {
//         newnode = (struct node *)malloc(sizeof(struct node));
//         if (newnode == NULL) {
//             printf("Memory allocation failed!\n");
//             return 1;
//         }

//         printf("Enter %d node data: ", i);
//         scanf("%d", &data);

//         newnode->data = data;
//         newnode->next = NULL;

//         if (header == NULL) {
//             header = temp = tail = newnode;  // Initialize header and tail
//         } else {
//             temp->next = newnode;
//             temp = temp->next;
//             tail = newnode;  // Update tail
//         }
//     }

//     // Display linked list
//     temp = header;
//     printf("Data: ");
//     while (temp != NULL) {
//         printf("%d ", temp->data);
//         temp = temp->next;
//     }
//     printf("\n");

//     return 0;
// }
