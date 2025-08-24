#include<stdio.h>
#include<stdlib.h>

void main()
{
    int size = 5;

    int arr[size];
    int *ptr = (int *)malloc(sizeof(int));

    for(int i = 0; i < size; i++)
    {
        printf("Enter a number for the array: ");
        scanf("%d", ptr + i);  
    }

    int *largest = (int *)malloc(sizeof(int));
    *largest = *ptr; // Initialize largest with the first element

    for(int i=0;i<size;i++)
    {
        if(*largest < *(ptr + i))
        {
            *largest = *(ptr + i); // Update largest if a smaller element is found
        }
    }

    printf("largest = %d \n",*largest);

    int *smallest = (int *)malloc(sizeof(int));
    *smallest = *ptr; // Initialize smallest with the first element

    for(int i=0;i<size;i++)
    {
        if(*smallest > *(ptr + i))
        {
            *smallest = *(ptr + i); // Update smallest if a larger element is found
        }
    }   

    printf("smallest = %d \n",*smallest);

    free(ptr);
    free(largest);
    free(smallest);
}   