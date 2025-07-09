#include<stdio.h>
#include<stdlib.h>

struct node {
    int info;
    struct node *link;
};

struct node *head;
struct node *last = NULL;

void insert_first(int x)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->info = x;

    if(head -> link == head)
    {
        newNode -> link = newNode; // New node points to itself
        head -> link = newNode;
        last = newNode;
    }
    else 
    {
        newNode->link = head -> link ; // New node points to the current head
        head -> link = newNode; // Head now points to the new node
        last -> link =  head->link; // Last node points to the new node
    }
}
void insert_last(int x)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode -> info = x;

    newNode -> link = head->link;
    last->link = newNode; // Last node points to the new node
    last = newNode; // Last now points to the new node
}

void delete(int x)
{
    struct node *save = head -> link; //point to the first
    struct node *pred = head;

    while(save -> link != head -> link && save -> info != x)
    {
        pred = save;
        save = save -> link;
    }

    if(save -> info == x)
    {
        if(save == last && save == head -> link) //only one node
        {
            free(save);
            head -> link = head;
            last = NULL;
        }

        else 
        {
            pred -> link = save -> link;  //middle delte
            
            if(save == head -> link)  //first node delete
            {
                head  -> link = save -> link;
            }
            if(save == last) //last node delte
            {
                last  = pred;
                last -> link = head -> link;
            }
            free(save);
        }
    }
}

void print()
{
    struct node *save = head->link; // Start from the first node
    struct node *temp = save;   //starts where
    
    while (save -> link != temp ) {
        printf("%d -> ", save->info);
        save = save->link; // Move to the next node
    }
    printf("%d -> NULL", save ->info); 
    printf("\n");
}

void main()
{
    head = (struct node *)malloc(sizeof(struct node));
    head -> link = head;

    printf("insert at first: \n");
    insert_first(10);
    insert_first(20);
    insert_first(30);
    insert_first(40);

    print();

    printf("\n insert at last: \n");
    insert_last(50);
    insert_last(60);    

    print();

    printf("\n after delete: \n");
    delete(30);

    print();
}