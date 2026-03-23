#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next; //Address part
}n1,n2,n3;


int main()
{
n1.data=2;
n2.data=3;
n3.data=4;

n1.next=&n2;
n2.next=&n3;
n3.next=NULL;

struct node *newNode;

// newNode = (struct node*)malloc(sizeof(struct node));
// if(newNode == NULL)
// {printf("Unable to allocate memory.");
// }

// else
// {
newNode->data = 1;
newNode->next = &n1;
printf("DATA INSERTED SUCCESSFULLY\n");
// }

while (newNode!=NULL)
{
    printf("%d ",newNode->data);
    newNode=newNode->data;

}


}
