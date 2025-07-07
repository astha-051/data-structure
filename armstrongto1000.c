#include<stdio.h>

int armstrong(int n)
{
    int r,temp,sum=0;

    temp=n;

    while(n > 0)
    {
        r=n%10;
        sum=sum+(r*r*r);
        n/=10;
    }

    if(sum==temp)
    {
        return sum;
    }

    return 0;
}

void main()
{
    for(int i=0;i<=1000;i++)
    {
        if(armstrong(i))
        {
            printf("%d  \n",i);
        }
    }
}