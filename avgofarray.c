#include<stdio.h>
void main()
{
    int number,sum=0;

    printf("enter a number:");
    scanf("%d",&number);

    int arr[number];

    for(int i=0;i<number;i++)
    {
        printf("enter an elements of an array:");
        scanf("%d",&arr[i]);
        sum+=arr[i];
    }

    printf("sum=%d \n",sum);
    printf("avg=%d",sum/number);
}