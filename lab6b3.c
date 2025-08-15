#include<stdio.h>
#define size 5
int  top = -1;
int top2 = -1;
int arr[size];
int arr2[size];

void push_A(int x)
{
    if(top > size-1)
    {
        printf("stack overflow \n");
        return;
    }
    printf("pushed in array1 \n");
    arr[++top] = x;  //first increase the top and then push the value
    printf("pushed %d \n",x);
}

void push_B(int x)
{
    if(top2 > size-1)
    {
        printf("stack overflow \n");
        return;
    }
    printf("pushed in array2 \n");
    arr2[++top2] = x;  //first increase the top and then push the value
    printf("pushed %d \n",x);
}

void check()
{
    if(top == top2)
    {
        printf("a and b stacks are equal \n");
    }
    else
    {
        printf("a and b stacks are not equal \n");
    }
}

void main()
{
     push_A(12);
     push_B(23);

     push_A(34);
     push_B(45);

    check();
     push_A(56);
     check();
}