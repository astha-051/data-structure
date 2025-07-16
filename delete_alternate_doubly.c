#include<stdio.h>
#include<stdlib.h>

struct node 
{
    int info;
    struct node *lpter;
    struct node *rpter;
};

struct node *left = NULL;
struct node *right = NULL;

void insert(int x)  //last
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));

    newNode -> info = x;
    newNode -> lpter = NULL;
    newNode -> rpter = NULL;

    if(right == NULL)
    {
        newNode -> lpter = NULL;
        newNode -> rpter = NULL;
        left = right = newNode;
    }
    else 
    {
        right -> rpter  = newNode;
        newNode -> lpter = right;
        right = newNode;
    }
}
void delete_alternate(struct node *start)
{
    struct node *save = start;
    struct node *pred;

    while(save != NULL && save -> rpter != NULL)  //forlast node checking
    {
        // pred is the node to be deleted — the one after save.
        // Example: If save is pointing to node 10, then pred = 20.
        pred = save -> rpter;

        // save->rpter now skips over pred and points to the next node after it.
        // Example: 10 -> 30, effectively removing 20 from the list.
        save -> rpter = pred -> rpter;

        // If pred wasn't the last node:
        // Set the left pointer of pred->rpter to save, to maintain doubly linked structure.
        // Example: 30->lpter = 10
        if(pred -> rpter != NULL)  
        {
            pred -> rpter -> lpter = save;
        }
        free(pred);
        save  = save -> rpter;
    }
}

void print()
{
    struct node *save = left;

    while(save != NULL)
    {
        printf("%d <-> ",save -> info);
        save = save -> rpter;
    }
    printf("NULL");
}

void main()
{
    printf("\n inserted element: ");
    insert(10);
    insert(20);
    insert(30);
    insert(40);
    insert(50);
    insert(60);

    print();

    printf("\n after delete alternate: \n");
    delete_alternate(left);

    print();
}

// Iteration 1:
// save = 10

// pred = 20

// Delete 20

// List: 10 <-> 30 <-> 40 <-> 50 <-> 60

// save = 30

// Iteration 2:
// save = 30

// pred = 40

// Delete 40

// List: 10 <-> 30 <-> 50 <-> 60

// save = 50

// Iteration 3:
// save = 50

// pred = 60

// Delete 60

// List: 10 <-> 30 <-> 50

// save->rpter = NULL → loop exits.

// ✅ Final Output:
// 10 <-> 30 <-> 50

// Every second node (20, 40, 60) was successfully deleted.