/* Delete the node at any given position of the linked list */
void deleteMiddleNode(int position)
{
int i;
struct node *toDelete, *prevNode;

if(head == NULL)
{
  printf("List is already empty.");
}

else
{

    toDelete = head;
    prevNode = head;
    for(i=2; i<=position; i++)
    {
        prevNode = toDelete;
        toDelete = toDelete->next;
        if(toDelete == NULL)
        break;
    }
    if(toDelete != NULL)
    {
        if(toDelete == head)
        head = head->next;
        prevNode->next = toDelete->next;
        toDelete->next = NULL;
        
        /* Deletes the n node */
        free(toDelete);
        printf("SUCCESSFULLY DELETED NODE FROM MIDDLE OF LIST\n");
    }

    else
    {
    printf("Invalid position unable to delete.");
    }

}

}