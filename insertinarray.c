#include<stdio.h>
void main()
{
    int number;

    printf("enter a number:");
    scanf("%d",&number);

    int arr[number+1];

    for(int i=0;i<number;i++)
    {
        printf("entere an array element:");
        scanf("%d",&arr[i]);
    }

    int pos,num;

    printf("enter a position in which you want to enter the number:");
    scanf("%d",&pos);
    printf("enter a number to insert:");
    scanf("%d",&num);

    for(int i=number;i>pos;i--)  //shifts elements to the right
    {
        arr [i] = arr[i-1];
    }
    arr[pos] = num;

    for(int i=0;i<number+1;i++)
    {
        printf("%d ",arr[i]);
    }
}