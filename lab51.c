#include<stdio.h>
#include<stdlib.h>

void main()
{
    int number;

    int *sum = (int *)malloc(sizeof(int));
    *sum = 0;

    for(int i=1;i<=5;i++)
    {
        printf("enter a number %d: ", i);
        scanf("%d", &number);
        *sum += number; // This line is incorrect, it should be sum[i-1] += number;
    }

    printf("sum = %d \n", *sum);
    free(sum);
}