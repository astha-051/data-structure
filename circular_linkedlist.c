#include<stdio.h>
#include<stdlib.h>

struct node{
    int info;
    struct  node *link;
};

struct node *first = NULL;
struct node *last = NULL;

void insert_first(int x)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));

    newNode -> info = x;

    if(first == NULL)
    {
        newNode -> link = newNode;
        first = last = newNode;
    }
    else 
    {
        newNode -> link = first;
        last -> link = newNode;
        first = newNode;
    }
}

void insert_last(int x)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));

    newNode -> info = x;

    if(first  == NULL)
    {
        newNode -> link = newNode;
        first = last = newNode;
    }
    else 
    {
        newNode -> link =first;
        last -> link = newNode;
        last = newNode;
    }
}
void delete(int x)
{
    struct  node  *save = first;
    struct node *pred = NULL;

    if(first == last && first -> info == x) //if only one node
    {
        free(first);
        first = last =NULL;
        return;
    }

    while(save -> link != first)
    {
        pred = save;
        save = save -> link;
        
        if(save -> info == x)
        {
            if(save == first)
            {
                first = first -> link;
                last -> link = first;
                free(save);
                return;
            }
            else 
            {
                pred -> link = save -> link;

                if(save == last)
                {
                    last = pred;
                }
            }
            free(save);
            return;
        }
    }
        
}

void print()
{
    struct node *save = first;

    while(save  -> link != first)
    {
        printf("%d -> ",save -> info);
        save = save -> link;
    }
    printf("%d", save -> info); // Print the last node and back to first node
}

void main()
{
    insert_first(20);
    insert_first(40);
    insert_first(60);
    insert_first(80);

    printf("insert at first:\n");
    print();

    insert_last(100);
    insert_last(200);

    printf("\ninsert at last:\n");
    print();

    printf("\n after delete:\n");
    delete(40);
    print();
}