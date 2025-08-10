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

    printf("enter a position you want to insert:");
    scanf("%d", &pos);

    int num;

    printf("enter a number to insert:");
    scanf("%d", &num);

    for(int i=number;i>pos;i--)  //shifts elements to the right
    {
        arr [i] = arr[i-1];
    }
    arr[pos] = num;
    
    int temp;
    for(int i=0;i<number+1;i++)
    {
        if(arr[i] > arr[i+1])
        {
            temp=arr[i];
            arr[i]=arr[i+1];
            arr[i+1]=temp;
        }
    }

    for(int i=0;i<number+1;i++)
    {
        printf("%d ", arr[i]); // print the updated array
    }
}