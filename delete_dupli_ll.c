#include<stdio.h>
#include<stdlib.h>

struct node{
    int info;
    struct node *link;
};

struct node *first = NULL;

void insert(int number)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));

    newNode -> info = number;
    newNode -> link = NULL;
    
    if(first == NULL)
    {
        first = newNode;
    }
    else 
    {
        struct node *save = first;

        while(save -> link != NULL)
        {
            save = save -> link;  
        }

        save -> link = newNode;  
    }
}

void delete_duplicate()
{
    struct  node *pred,*next,*temp;

    for(pred = first ; pred != NULL ; pred = pred -> link)
    {
        temp = pred;  //to keep track of the previous node
        next = pred -> link;

        while(next != NULL)
        {
            if(pred -> info == next -> info)
            {
                temp -> link = next -> link;  //delete the duplicate node
                free(next);
                next = temp -> link;  //move to the next node
            }
            else 
            {
                temp = next;
                next = next -> link;  //move to the next node
            }
        }
        
    }
}
void print()
{
    struct node *save = first;

    while(save != NULL)
    {
        printf("%d -> ",save -> info);
        save = save -> link;
    }
    printf("NULL");
}
void main()
{
    insert(10);
    insert(20);
    insert(30);
    insert(10);
    insert(40);

    printf("before delete\n");
    print();

    delete_duplicate();

    printf("\nafter delete duplicate \n");
    print();
}