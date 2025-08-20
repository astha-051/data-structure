#include<stdio.h>
#include<stdlib.h>

void main()
{
int size = 5;
int arr[size];

int *ptr = (int *)malloc(sizeof(int));

for(int i=0;i<size;i++)
{
    printf("enter a number  of an array:");
    scanf("%d",ptr + i);  //ptr first  point to the 1st element so adding i it will be pointing to the next and than...
}

printf("\n");

for(int i=0;i<size;i++)
{
    printf("%d ",*(ptr + i)); //ptr+i stores tha address and using *+ we can acess its value
}

printf("\n");
free(ptr);

}