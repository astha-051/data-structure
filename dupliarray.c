#include<stdio.h>
void main()
{
    int number,flag=0;

    printf("enter a number:");
    scanf("%d", &number);

    int arr[number];

    for(int i = 0; i < number; i++)
    {
        printf("enter an element of the array:");
        scanf("%d", &arr[i]);
    }

    for(int i=0;i<number;i++)
    {
        for(int j=i+1;j<number;j++)
        {
            if(arr[i] == arr[j])
            {
                flag = 1;
                printf("The array has a duplicate element: %d at indices %d and %d\n", arr[i], i, j);
                break; 
            }
        }
    }

    if(flag == 1)
    {
        printf("The array is a duplicate array\n");
    }
    else
    {
        printf("The array is not a duplicate array\n");
    }   
}