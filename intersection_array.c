#include<stdio.h>

void intersection(int arr1[],int arr2[])
{
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            if(arr1[i] == arr2[j])
            {
                printf("%d \n",arr1[i]);
            }
        }
    }
}

void main()
{
    int arr1[5],arr2[5];

    for(int i=0;i<5;i++)
    {
        printf("Enter element %d for first array: ", i + 1);
        scanf("%d", &arr1[i]);
    }

    for(int i=0;i<5;i++)
    {
        printf("Enter element %d for second array: ", i + 1);
        scanf("%d", &arr2[i]);
    }

    intersection(arr1, arr2);
}