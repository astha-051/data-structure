#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void main()
{
    char str[10];
    char *start = (char *)malloc(sizeof(char));
    char *end = (char *)malloc(sizeof(char));
    int len,isplain = 1;

    printf("Enter a string: ");
    scanf("%s", str);

    len = strlen(str);
    start = str; // Point to the start of the string
    end = str + len - 1; // Point to the end of the string

    while(start < end)
    {
        if(*start != *end)
        {
            isplain = 0;
            break;
        }
        start++;
        end--;
    }

    if(isplain)
    {
        printf("The string is a palindrome.\n");
    }
    else
    {
        printf("The string is not a palindrome.\n");
    }

    free(start);
    free(end);
}