#include<stdio.h>
#include<stdlib.h>

struct node{
	int info;
	struct node *link;
};

struct node *first = NULL;
struct node *begin = NULL;

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

		while(save->link != NULL)
		{
			save = save -> link;
		}
		save -> link =newNode;
	}
}

void copy()
{
	struct node *newNode = (struct node *)malloc(sizeof(struct node)); //copy a node

	newNode -> info = first -> info;  //copy first node
	newNode -> link = NULL;

	struct node *save = first;
	struct node *pred;
	begin = newNode;  //starting from first

	while(save -> link != NULL)
	{
		pred = newNode;
		save = save -> link;
		newNode = (struct node *)malloc(sizeof(struct node)); //add a value in node and joint to the linkedlist
		newNode -> info = save -> info;
		pred -> link = newNode;
	}
	newNode -> link = NULL;
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

void main()
{
	insert(10);
	insert(20);
	insert(30);
	insert(40);
	insert(50);

	printf("original list:\n ");
	print(first);

	copy();
	printf(" \n copied list: \n");
	print(begin);
}