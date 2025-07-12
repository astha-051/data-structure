#include<stdio.h>
#include<stdlib.h>

struct node{
    int info;
    struct node *link;
};

struct node *first = NULL;
struct node *second = NULL;

void insert(int x)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));

    newNode -> info = x;
    newNode -> link = NULL;
    
    if(first == NULL)
    {
        first = newNode;
    }
    else 
    {
        struct  node *save = first;

        while(save -> link != NULL)
        {
            save = save -> link;
        }
        save -> link = newNode;
    }
}

void insert2(int x)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));

    newNode -> info = x;
    newNode -> link = NULL;
    
    if(second == NULL)
    {
        second = newNode;
    }
    else 
    {
        struct  node *save = second;

        while(save -> link != NULL)
        {
            save = save -> link;
        }
        save -> link = newNode;
    }
}

void print(struct node *start)
{
    struct node *save = start;

    while(save != NULL)
    {
        printf("%d -> ",save -> info);
        save = save -> link;
    }
    printf("NULL");
}

int compare()
{
    struct node *f1  = first;
    struct node *f2 = second;

    while(f1 != NULL && f2 != NULL)
    {
        if(f1 -> info != f2 -> info)
        {
            return 0;
        }

        f1 = f1 -> link;
        f2 = f2 -> link;
    }
    return (f1 ==  NULL && f2 == NULL);  //if both are of same length
}

void main()
{
    insert(10);
    insert(20);
    insert(30);

    printf("\n first list: \n");
    print(first);

    insert2(10);
    insert2(20);
    insert2(30);
    insert2(50);

    printf("\n second list: \n");
    print(second);

    if(compare())
    {
        printf("\n both lists are equal \n");
    }
    else 
    {
        printf("\n both are not equal \n");
    }
}
