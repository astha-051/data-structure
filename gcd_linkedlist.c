#include<stdio.h>
#include<stdlib.h>

struct node{
    int info;
    struct node *link;
};

struct node *first = NULL;

int  find_gcd(int num1 , int num2)
{
    int min;

    if(num1 < num2)
    {
        min = num1;
    }
    else 
    {
        min = num2;
    }

    for(int i = min ;i >= 1; i--)
    {
        if(num1 % i == 0 && num2 % i == 0)
        {
            min = i;
            break;
        }
    }
    return min;
}

void insert_gcd()
{
    struct node *save = first;
    struct node *next = first -> link;

    while(next != NULL)
    {
        struct node *newNode = (struct node *)malloc(sizeof(struct node));

        newNode -> info = find_gcd(save -> info , next -> info);
        save -> link = newNode;
        newNode -> link = next;
        save = newNode -> link;
        next = save -> link;
    }
}

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
        struct node *save = first;

        while(save -> link != NULL)
        {
            save = save -> link;
        }
        save -> link = newNode;
    }
}

void print()
{
    struct node *temp = first;

    while (temp != NULL)
    {
        printf("%d -> ", temp->info);
        temp = temp->link;
    }
    printf("NULL");
}

void main()
{
    insert(12);
    insert(22);
    insert(32);
    insert(48);
    insert(52);

    print();
    insert_gcd();
    printf("\nmodified list:\n");
    print();
}