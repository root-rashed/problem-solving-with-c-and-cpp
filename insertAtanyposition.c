#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
}n1, n2, n3,n4,n5;

int main() 
{

    struct node *temp;
    int n;
    printf("Enter position to delete: ");
    scanf("%d", &n);

    // Initialize the linked list with data
    n1.data = 1;
    n2.data = 2;
    n3.data = 3;
    n4.data=4;
    n5.data=5;

    // Linked adress;
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next= &n5;
    n5.next=NULL;


    //Header declaration
    temp = &n1;

    printf("Before delete:");
    while (temp!=NULL)
    {
        printf("%d ",temp->next);
        temp = temp->next;
    }
    

    
    
    }
   