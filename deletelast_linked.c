#include<stdio.h>
#include<stdlib.h>

struct node{
    int info;
    struct node *link;
};

struct node *first =  NULL;

void insert(int x)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));

    newNode -> info =x;
    newNode -> link=first;
    first=newNode;

    printf("node %d  \n",x);
}
void delete_last()
{
    struct node *save = first;
    struct node *pred = first;

    while(save -> link  != NULL)
    {
        pred = save;
        save = save -> link;
    }
    printf("%d \n",first->info);
    free(save);
    pred -> link = NULL;
    
}

// void print_list()
// {
//     struct node * save= first;
//     while(save != NULL)
//     {
//         printf("%d \n",save->info);
//         save = save->link ; //jump at next node
//     }
// }
void print_list(){
		struct node* save = first;
		while(save != NULL)
		{
		printf("%d -> ",save->info);
		save = save->link;
		}
	printf("NULL\n");
}
void main()
{
   

    printf("delete \n");

        delete_last();

    printf("print list after deletion:\n");
    print_list();
}