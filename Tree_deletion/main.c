
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int value)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
};

struct Node* insert(struct Node* root,int value)
{
    if(root==NULL)
    {
        return createNode(value);
    }

    if(value<root->data)
    {
        root->left = insert(root->left,value);
    }

    else if(value>root->data)
    {
        root->right = insert(root->right,value);
    }

    return root;
};

void inorder(struct Node* root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d ->",root->data);
        inorder(root->right);
    }
}

void preorder(struct Node* root)
{
    if(root!=NULL)
    {
        printf("%d ->",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct Node* root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ->",root->data);
    }
}

int element;
int search(struct Node* root,int element)
{
    if(root==NULL)
    {
        return 0;
    }
    if(root->data == element)
    {
        return 1;
    }
    else if(root->data>element)
    {
        return search(root->left,element);
    }
    else
    {
        return search(root->right,element);
    }
}

int main()
{
    struct Node* root = NULL;
    int n,value;

    printf("Enter the number you want to insertion: ");
    scanf("%d",&n);
    printf("\n");

    for(int i=0; i<n; i++)
    {
        printf("Enter the element %d: ",i+1);
        scanf("%d",&element);

        root=insert(root,element);
    }

    printf("\nTree Insertion done...\n");

    printf("\nInorder Traversal: ");
    inorder(root);
    printf("\n");

    printf("preorder Traversal: ");
    preorder(root);
    printf("\n");

    printf("postorder Traversal: ");
    postorder(root);
    printf("\n");

    printf("\nEnter the element you want to search: ");
    scanf("%d",&element);
    printf("Searching...\n");
    if(search(root,element))
    {
        printf("\nElement %d is found",element);
    }
    else
    {
        printf("\nElement %d is not found",element);
    }

    printf("\nExit...");

    return 0;
}
