#include<stdio.h>
void main()
{
    int number;

    printf("enter a number:");
    scanf("%d",&number);

    int arr[number];

    for(int i=0;i<number;i++)
    {
        printf("enter an array element:");
        scanf("%d",&arr[i]);
    }

    for(int i=0;i<number;i++)
    {
        for(int j=i+1;j<number;j++)
        {
            if(arr[i] == arr[j])
            {
                for(int k=j;k<number;k++)
                {
                    arr[k] = arr[k+1]; 
                }
                number--; // reduce the size of the array
                j--; // adjust index 
            }
        }
    }

    printf("array after delete duplicate \n");

    for(int i=0;i<number;i++)
    {
        printf("%d ",arr[i]);
    }
}