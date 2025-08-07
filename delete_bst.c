#include<stdio.h>
#include<stdlib.h>

struct node{
    int info;
    struct node *left;
    struct node *right;
};

struct node *root = NULL;

struct node* createNode(int data){

    struct node* newNode = (struct node *)malloc(sizeof(struct node)); 

    newNode->info = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

struct node* insert(int data,struct node *root)
{
    if(root == NULL)
    {
        root = createNode(data);
        return root;
    }

    if(data < root->info)
    {
        root -> left = insert(data,root->left);
    }
    else if(data > root->info)
    {
        root -> right = insert(data,root->right);
    }
    
    return root;
}

struct node* inorder(struct node* root)
{
    if(root != NULL)
    {
        inorder(root->left);
        printf("%d ->",root->info);
        inorder(root -> right);
    }
}

struct node* findMin(struct node* Node)
{
    while(Node -> left != NULL)
    {
        Node = Node -> left;
    }
    return Node;
}

struct node* delete(struct node* root,int data)
{
    if(root == NULL)
    {
        return root;
    }

    if(data < root ->info)
    {
        root -> left = delete(root->left,data);
    }
    else if(data > root -> info)
    {
        root -> right =  delete(root -> right , data);
    }
    else   //found
    {
        if(root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }

        else if(root -> left == NULL)
        {
            free(root);
            return root->right;
        }

        else if(root -> right == NULL)
        {
            free(root);
            return root->left;
        }

        else 
        {
            struct node* temp = findMin(root->right);
            root->info = temp ->info;
            root->right=delete(root->right,temp->info);
        }
    }
    return root;
}

void main()
{
    root = insert(50,root);
    root = insert(30,root);
    root = insert(70,root);
    root = insert(20,root);
    root = insert(40,root);
    root = insert(60,root);
    root = insert(80,root);

    printf("before delete \n");
    inorder(root);

    printf("\n after delte \n");
    delete(root,50);
    inorder(root);
}