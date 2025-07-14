#include<stdio.h>
void main()
{
    int day;
    int day1,week,year;

    printf("enter days:");
    scanf("%d",&day);

    year=day/365;
    week=(day%365)/7;
    day1=(day%365)%7;

    printf("%d:%d:%d",year,week,day1);
}