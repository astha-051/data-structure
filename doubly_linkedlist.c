#include<stdio.h>
#include<stdlib.h>

struct node{
    int info;
    struct node *lpter;
    struct node *rpter;
};

struct node *left = NULL,*right = NULL;

void insert_end(int x)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));

    newNode -> info = x;
    newNode -> lpter = NULL;
    newNode -> rpter = NULL;
 
    if(right == NULL)  //only one node which we insert
    {
        newNode -> lpter = NULL;  //it don't point anywhere so that both the  side become null
        newNode -> rpter = NULL;
        left = right = newNode;
    }
    else 
    {
        right -> rpter = newNode;
        newNode -> lpter = right;
        right = newNode;
    }
}

void insert_first(int x)
{
    // Create a new node newNode. Set newNode->info = data.
    // Set newNode->prev = NULL. Set newNode->next = first.
    // If first is not NULL: Set first->prev = newNode. Set first = newNode.

    struct node *newNode = (struct node *)malloc(sizeof(struct node));

    newNode -> info = x;
    newNode -> lpter  = NULL;
    newNode -> rpter = NULL;

    newNode -> rpter = left; //new node will point to the first node
    left -> lpter = newNode; //first node will point to the new node
    left = newNode; 
}

void insert_middle(int  x,int pos)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode -> info = x;
    newNode -> lpter  = NULL;
    newNode -> rpter = NULL;

    struct node *temp = left;
    int i = 1;
    
    while(i < pos -1 && temp -> rpter != NULL)
    {
        temp = temp -> rpter;
        i++;
    }

    newNode -> rpter = temp -> rpter;
    newNode -> lpter = temp;
    temp -> rpter -> lpter = newNode;
    temp  -> rpter = newNode;
}

void delete(int pos)
{
    struct node *temp = left;
    int i=1;

    if(pos == 1)  //first node
    {
        if(left == right)
        {
            left = right = NULL;
        }
        else 
        {
            left = left -> rpter;
            left -> lpter = NULL;
        }
        free(temp);
    }
    while(i < pos && temp != NULL )
    {
        temp = temp -> rpter;
        i++;
    }
    printf("delete elemente = %d  \n",temp -> info);

    if(temp == NULL)
    {
        printf("invalid");
    }

    if(temp  == right) //last node
    {
        right = temp -> lpter;
        right -> rpter = NULL;
        free(temp);
    }

    //middle node
    temp -> lpter -> rpter = temp -> rpter;
    temp -> rpter -> lpter = temp -> lpter;
    free(temp);
}
void print()
{
    struct  node *save = left;

    struct node *first = NULL;

    while(save != NULL)
    {
        printf("%d <-> ",save -> info);
        save = save -> rpter;
    }
    printf("NULL");
}
void main()
{
    printf("insert at last:\n");
    insert_end(10);
    insert_end(20);
    insert_end(30);
    insert_end(40);

    print();

    printf("\n insert at first:\n");
    insert_first(5);
    insert_first(15);
    insert_first(25);
    insert_first(35);

    print();

    printf("\n insert at middle:\n");
    insert_middle(13,5);
    insert_middle(16,6);

    print();

    printf("\n after delete: \n");
    delete(4);

    print();
}