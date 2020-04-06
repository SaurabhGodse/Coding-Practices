#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node* next;
}Node;

Node* head = NULL;
int length = 0;

// function deletes a node in linked list
void delete(Node* h, int pos)
{
    if(pos > 0 && pos <= length)
    {
        if(pos == 1)
        {
            head = head -> next;
            free(h);
        }
        else
        {
            int i;
            for(i = 1; i < pos - 1; i++)
            {
                h = h -> next;
            }
            Node* d = h -> next;
            h -> next = d -> next;
            free(d);
        }
        length--;
    }
    else
    {
        if(length == 0)
            printf("Linked list is empty\n");
        else
            printf("Wrong position entered...\n Please enter position between 1 and %d\n", length);
    }
}

// function inserts an element in linked list
void insert(Node* h, int d, int pos)
{
    Node* newnode = (Node*)malloc(sizeof(Node));
    newnode -> data = d;
    newnode -> next = NULL;
    if(pos > 0 && pos <= length + 1)
    {
        if(pos == 1)
        {
            newnode -> next = head;
            head = newnode;
        }
        else
        {
            int i;
            for(i = 1; i < pos - 1; i++)
            {
                h = h -> next;
            }
            newnode -> next = h -> next;
            h -> next = newnode;
        }
        length++;
    }
    else
    {
        printf("Wrong position passed...\nPlease enter position between 1 and %d\n", length + 1);
    }
}

// function displays all elements in linked list
void display(Node* h)
{
    if(h == NULL)
    {
        printf("No element in linked list...\n");
    }
    else
    {
        while(h)
        {
            printf("%d\t", h -> data);
            h = h -> next;
        }
    }
    printf("\n");
}

int main()
{
    char c;
    do
    {
        printf("1.insert at start \t 2.insert in middle \t 3.insert at end \n 4.delete at start \t 5.delete in middle \t 6.delete at last \n 7.display\n");
        int choice;
        int d, pos;
        printf("Enter your choice : ");
        scanf("%d", &choice);
        
        switch (choice)
        {
            case 1:
                printf("\nEnter data : ");
                scanf("%d", &d);
                insert(head, d, 1);
                break;
            case 2:
                printf("\nEnter data : ");
                scanf("%d", &d);
                printf("\nEnter position : ");
                scanf("%d", &pos);
                insert(head, d, pos);
                break;
            case 3:
                printf("\nEnter data : ");
                scanf("%d", &d);
                insert(head, d, length + 1);
                break;
            case 4:
                delete(head, 1);
                break;
            case 5:
                printf("\nEnter position : ");
                scanf("%d", &pos);
                delete(head, pos);
                break;
            case 6:
                delete(head, length);
                break;
            case 7:
                display(head);
                break;
            default:
                break;
        }
        printf("\nEnter Y/y to continue else enter N/n");
        printf("\nDo you want to continue : ");
        scanf(" %c", &c);
    } while (c != 'n' && c != 'N');
    
    return 0;
}
