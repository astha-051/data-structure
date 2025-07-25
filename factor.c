#include<stdio.h>
void main()
{
    int number;

    printf("enter a number:");
    scanf("%d",&number);

    for(int i=1;i<=number;i++)
    {
        if(number % i == 0)
        {
            printf("%d\n",i);
        }
    }
}