#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
} *head, *last;

void createList(int n);
void displayList();
void insert_position(int data, int position);

int main() {
    int n, data;
    head = NULL;
    last = NULL;
    printf("Enter the total number of nodes in list: ");
    scanf("%d", &n);

    createList(n);  // function to create double linked list
    displayList();  // function to display the list

    printf("Enter the position and data to insert new node: ");
    scanf("%d %d", &n, &data);
    insert_position(data, n);  // function to insert node at any position
    displayList();

    return 0;
}

void createList(int n) {
    int i, data;
    struct node *newNode;

    if (n >= 1) {
        head = (struct node *)malloc(sizeof(struct node));

        printf("Enter data of 1 node: ");
        scanf("%d", &data);

        head->data = data;
        head->prev = NULL;
        head->next = NULL;
        last = head;

        for (i = 2; i <= n; i++) {
            newNode = (struct node *)malloc(sizeof(struct node));
            printf("Enter data of %d node: ", i);
            scanf("%d", &data);
            newNode->data = data;
            newNode->prev = last;
            newNode->next = NULL;
            last->next = newNode;
            last = newNode;
        }

        printf("\nDOUBLY LINKED LIST CREATED SUCCESSFULLY\n");
    }
}

void displayList() {
    struct node *temp;
    int n = 1;
    if (head == NULL) {
        printf("List is empty.\n");
    } else {
        temp = head;
        printf("DATA IN THE LIST:\n");
        while (temp != NULL) {
            printf("DATA of %d node = %d\n", n, temp->data);
            n++;
            temp = temp->next;
        }
    }
}

void insert_position(int data, int position) {
    struct node *newNode, *temp;
    int i;

    // Case when list is empty
    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        last = newNode;
        printf("Inserted %d at position 1 as the list was empty.\n", data);
        return;
    }

    // Insertion at the beginning
    if (position == 1) {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        printf("Inserted %d at the beginning of the list.\n", data);
        return;
    }

    // Traverse to the desired position
    temp = head;
    for (i = 1; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }

    // If position is greater than the length of the list
    if (temp == NULL) {
        printf("Position is greater than the length of the list. Inserting at the end.\n");
        last->next = newNode;
        newNode->prev = last;
        last = newNode;
        return;
    }

    // Insertion at the middle or end
    newNode->next = temp->next;
    if (temp->next != NULL) 
    {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
    newNode->prev = temp;
    
    printf("Inserted %d at position %d.\n", data, position);
}
