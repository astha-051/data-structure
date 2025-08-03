#include<stdio.h>
#include<stdlib.h>

struct node
{
    int info;
    struct node *link;
};

struct node *first = NULL;

void insert_first(int x)
{
    //malloc returns a pointer to a bolck of memory,so we need a pointer variable to store that address
    struct node *newnode = (struct node *) malloc (sizeof(struct node));
    newnode->info = x;
    newnode->link = first;
    first=newnode;
}

void insert_last(int y)
{
    struct node *newnode = (struct node *) malloc(sizeof(struct node));
    newnode->info = y;
    newnode->link = NULL;


    if(first == NULL)
    {
        //if list is emty,our first  node is null and that is why newnode also points to the first
        first = newnode;
    }

    else 
    {
        //travel the list until we find last node of list
        struct node *save = first;
        while(save->link != NULL)
        {
            save = save -> link;
        }

        save->link=newnode;
    }
}

void main()
{
    int x=10;

    insert_first(x);
    insert_last(x);
}



