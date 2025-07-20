#include<stdio.h>
void main()
{
    int number;

    printf("enter a number:");
    scanf("%d", &number);

    int arr[number];

    for(int i = 0; i < number; i++)
    {
        printf("enter an array element:");
        scanf("%d", &arr[i]);
    }

    int pos;

    printf("enter a position you want to delete from:");
    scanf("%d", &pos);

    for(int i=0;i<number;i++)
    {
        if(i >= pos)
        {
            arr[i] = arr[i + 1]; // shifts elements to the left
        }
    }

    printf("Array after deletion:\n");
    for(int i = 0; i < number-1; i++)
    {
        printf("%d ", arr[i]);
    }
}