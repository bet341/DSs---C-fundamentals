#include <stdio.h>
#include <stdlib.h>
struct node {
    int  info;
    struct node * prev;
    struct node * next;
}*head, *end;
/*Declaring function*/
void createList(int n);
void displayList();
void insertAtBeginning(int info);
void insertAtEnd(int info);
void insertAtN(int info, int position);
void reverseList();
void deleteFromBeginning();
void deleteFromN(n);
void deleteFromEnd();
void  displayList();

int main()
{
    int n, info, choice=1;

    head = NULL;
    end = NULL;

    while(choice != 0)
    {
        printf("DOUBLY LINKED LIST\n");
        printf("...................\n");
        printf("\n");
        printf("\n");
        printf("\n");
        printf("\n");
        printf("\n");
        printf("\n");
        printf("1. Create List\n");
        printf("2. Insert node  at beginning\n");
        printf("3. Insert node at end\n");
        printf("4. Insert node at any position\n");
        printf("5. delete a node from the beginning\n");
        printf("6. delete a node from the end\n");
        printf("7. delete a node from any position\n");
        printf("8. reverse the created list\n");
        printf("0. Exit\n");
        printf("--------------------\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("Enter the total number of nodes in list: ");
                scanf("%d", &n);
                createList(n);
                displayList();
                break;
            case 2:
                printf("Enter data of first node : ");
                scanf("%d", &info);
                insertAtBeginning(info);
                break;
            case 3:
                printf("Enter data of last node : ");
                scanf("%d", &info);
                insertAtEnd(info);
                break;
            case 4:
                printf("Enter the position where you want to insert new node: ");
                scanf("%d", &n);
                printf("Enter data of %d node : ", n);
                scanf("%d", &info);

                insertAtN(info, n);
                break;

                 case 5:
                deleteFromBeginning();
                break;
            case 6:
                deleteFromEnd();
                break;
            case 7:
                printf("Enter the node position which you want to delete: ");
                scanf("%d", &n);
                deleteFromN(n);
                break;
            case 8:
               	printf("the revese lists are:\n");
                reverseList();
                break;
            case 0:
            	exit(0);
                break;
            default:
                printf("Error! Invalid choice. Please choose between 0-5");
        }

        printf("\n\n\n\n\n");
    }
    return 0;
}



void createList(int n)
{
    int i, info;
    struct node *newNode;

    if(n >= 1)
    {

         // Create and link the head node

        head = (struct node *)malloc(sizeof(struct node));

        printf("Enter data of 1 node: ");
        scanf("%d", &info);

        head->info = info;
        head->prev = NULL;
        head->next = NULL;

       end = head;
         //Create and link rest of the n-1 nodes

        for(i=2; i<=n; i++)
        {
            newNode = (struct node *)malloc(sizeof(struct node));
            printf("Enter data of %d node: ", i);
            scanf("%d", &info);
            newNode->info = info;
            newNode->prev = end; // Link new node with the previous node
            newNode->next = NULL;

            end->next = newNode; // Link previous node with the new node
            end = newNode;          // Make new node as last/previous node
        }

        printf("\nDOUBLY LINKED LIST CREATED SUCCESSFULLY\n");
    }
}
  //Display content of the list from beginning to end

void displayList()
{
    struct node * temp;
    int n = 1;
    if(head == NULL)
    {
        printf("List is empty.\n");
    }
    else
    {
        temp = head;
        printf("DATA IN THE LIST:\n");

        while(temp != NULL)
        {
            printf("DATA of %d node = %d\n", n, temp->info);

            n++;

            /* Move the current pointer to next node */
            temp = temp->next;
        }
    }
}
 //insert new node at the beg.
void insertAtBeginning(int info)
{
    struct node * newNode;

    if(head == NULL)
    {
        printf("Error, List is Empty!\n");
    }
    else
    {
        newNode = (struct node *)malloc(sizeof(struct node));

        newNode->info = info;
        newNode->next = head; // Point to next node which is currently head
        newNode->prev = NULL; // Previous node of first node is NULL

        /* Link previous address field of head with newnode */
        head->prev = newNode;

        /* Make the new node as head node */
        head = newNode;

        printf("NODE INSERTED SUCCESSFULLY AT THE BEGINNING OF THE LIST\n");
    }
}
 //insert a new node at the end.
void insertAtEnd(int info)
{
    struct node * newNode;
    if(end == NULL)
    {
        printf("Error, List is empty!\n");
    }
    else
    {
        newNode = (struct node *)malloc(sizeof(struct node));
        newNode->info = info;
        newNode->next = NULL;
        newNode->prev = end;
        end->next = newNode;
        end = newNode;

        printf("NODE INSERTED SUCCESSFULLY AT THE END OF LIST\n");
    }
}
 //insert new node at any possition & z data to be inserted & in which posstion.

void insertAtN(int info, int position)
{
    int i;
    struct node * newNode, *temp;
    if(head == NULL)
    {
        printf("Error, List is empty!\n");
    }
    else
    {
        temp = head;
        i=1;

        while(i<position-1 && temp!=NULL)
        {
            temp = temp->next;
            i++;
        }
        if(position == 1)
        {
            insertAtBeginning(info);
        }
        else if(temp == end)
        {
            insertAtEnd(info);
        }
        else if(temp!=NULL)
        {
            newNode = (struct node *)malloc(sizeof(struct node));

            newNode->info = info;
            newNode->next = temp->next; // Connect new node with n+1th node
            newNode->prev = temp;          // Connect new node with n-1th node

            if(temp->next != NULL)
            {
                /* Connect n+1th node with new node */
                temp->next->prev = newNode;
            }
            /* Connect n-1th node with new node */
            temp->next = newNode;

            printf("NODE INSERTED SUCCESSFULLY AT %d POSITION\n", position);
        }
        else
        {
            printf("Error, Invalid position\n");
        }
    }
}
void deleteFromBeginning()
{
    struct node * toDelete;

    if(head == NULL)
    {
        printf("Unable to delete. List is empty.\n");
    }
    else
    {
        toDelete = head;
        head = head->next; //Move head pointer to 2 node
        if (head != NULL)
            head->prev = NULL; // Remove the link to previous node

        free(toDelete); // Delete the first node from memory
        printf("node deleted.\n");
    }
}

void deleteFromEnd()//Delete or remove the last node of the doubly linked list
{
    struct node * remove;

    if(end == NULL)
    {
        printf("whoops!. List is empty.\n");
    }
    else
    {
       remove = end;
        end = end->prev; // Move last pointer to 2nd last node

        if (end != NULL)
            end->next = NULL; // Remove link to of 2nd last node with last node

        free(remove);       // Delete the last node
        printf("deleted.\n");
    }
}
void deleteFromN(int position)
{
    struct node *current;
    int i;

    current = head;
    for(i=1; i<position && current!=NULL; i++)
    {
        current = current->next;
    }
    if(position == 1)
    {
        deleteFromBeginning();
    }
    else if(current == end)
    {
        deleteFromEnd();
    }
    else if(current != NULL)
    {
        current->prev->next = current->next;
        current->next->prev = current->prev;
        free(current); /// Delete the n node
        printf("removed %d POSITION.\n", position);
    }
    else
    {
        printf("whoops!,Invalid position!\n");
    }
}
void reverseList()
{
    struct node *current, *temp;
    current = head;
    while(current != NULL)
    {
          ///Swap the previous and next address fields of current node
        temp = current->next;
        current->next = current->prev;
        current->prev = temp;

        /// Move the current pointer to next node which is stored in temp */
        current = temp;
    }
   /// Swap the head and last pointers
    temp = head;
    head = end;
   end = temp;
    printf("LIST REVERSED SUCCESSFULLY.\n");
}
