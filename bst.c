#include<stdio.h>
#include<stdlib.h>

struct Node{
    int info;
    struct Node* left;
    struct Node* right;
};
struct Node* root = NULL;

struct Node* createNode(int data)
{
    struct Node* newNode = (struct Node *)malloc(sizeof(struct Node));
    
    newNode -> info = data;
    newNode -> left = NULL;
    newNode -> right = NULL;

    return newNode;
}

struct Node* insert(int data,struct Node* root)
{
    if(root == NULL)
    {
        root = createNode(data);
    }
    else
    {
        if(data < root->info)
        {
            root->left = insert(data, root->left);
        }
        else if(data > root->info)
        {
            root->right = insert(data, root->right);
        }
    }
    return root;
} 

void preorder(struct Node* root)
{
    if(root!= NULL)
    { 
        printf("%d ->",root->info);
    preorder(root->left);
    preorder(root->right);
    }
}

void inorder(struct Node* root)
{
    if(root != NULL)
    {
        inorder(root->left);
        printf("%d -> ",root->info);
        inorder(root->right);
    }
}

void postorder(struct Node* root)
{
    if(root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d -> ",root -> info);
    }
}

void main()
{
    root = insert(20,root);
    root = insert(10,root);
    root  = insert(30,root);
    root = insert(5,root);

    printf("Preorder Traversal:\n");
    preorder(root); 
    printf("\nInorder Traversal:\n");
    inorder(root);
    printf("\nPostorder Traversal:\n");
    postorder(root);    
}