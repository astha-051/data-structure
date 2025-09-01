#include<stdio.h>
#include<stdlib.h>

void main()
{
    int arr[5];

    int *ptr = (int *)malloc(sizeof(int));

    for(int i=0;i<5;i++)
    {
        printf("enter an element %d ",i);
        scanf("%d", ptr + i);
    }

    for(int i=0;i<5;i++)
    {
        for(int j=i+1;j<5;j++)
        {
            if(*(ptr + i) > *(ptr +j))
            {
                int temp = *(ptr + i);
                *(ptr + i) = *(ptr + j);
                *(ptr + j) = temp;
            }
        }
    }

    for(int i=0;i<5;i++)
    {
        printf("%d \n",*(ptr + i));
    }
}