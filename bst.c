#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int val;
    struct node* left;
    struct node* right;
}Node;

Node* Root = NULL;

// function creates new node
Node* createNode(int data)
{
    Node* newnode = (Node*)malloc(sizeof(Node));
    newnode -> val = data;
    newnode -> left = NULL;
    newnode -> right = NULL;
    return newnode;
}

// function inserts node in tree
Node* insert(Node* root, int data)
{
    if(!root)
        return createNode(data);
    else if(root -> val < data)
        root -> right = insert(root -> right, data);
    else
        root -> left = insert(root -> left, data);
    return root;
}

// function does inorder traversal of tree
void inorder(Node* root)
{
    if(root)
    {
        inorder(root -> left);
        printf("%d\t", root -> val);
        inorder(root -> right);
    }
}

// function returns pointer of node having key
Node* search(Node* root, int key)
{
    if(!root || root -> val == key)
        return root;
    else if(root -> val > key)
        return search(root -> left, key);
    else
        return search(root -> right, key);
}

// function returns pointer of node having least value in tree
Node* minVal(Node* root)
{
    if(!root -> left)
        return root;
    return minVal(root -> left);
}

// function deletes key in tree
Node* delete(Node* root, int key)
{
    if(!root)
        return root;
    else if(root -> val > key)
        root -> left = delete(root -> left, key);
    else if(root -> val < key)
        root -> right = delete(root -> right, key);
    else
    {
        // if node has less than two children
        if(!root -> left)
        {
            Node* temp = root -> right;
            free(root);
            return temp;
        }
        else if(!root -> right)
        {
            Node* temp = root -> left;
            free(root);
            return temp;
        }
        // if node has two children
        Node* temp = minVal(root -> right);
        root -> val = temp -> val;
        root -> right = delete(root -> right, temp -> val);
    }
    return root;
}
int main()
{
    char c;
    do
    {
        printf("1.insert \n2.delete \n3.search \n4.display \n");
        int choice;
        int d;
        printf("Enter your choice : ");
        scanf("%d", &choice);
    
        switch (choice)
        {
            case 1:
                printf("\nEnter value : ");
                scanf("%d", &d);
                Root = insert(Root, d);
                break;
            case 2:
                printf("\nEnter value : ");
                scanf("%d", &d);
                Root = delete(Root, d);
                break;
            case 3:
                printf("\nEnter the key : ");
                scanf("%d", &d);
                Node* temp = search(Root, d);
                if(temp)
                    printf("\nValue found");
                else
                    printf("\nValue not found");
                break;
            case 4:
                inorder(Root);
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
