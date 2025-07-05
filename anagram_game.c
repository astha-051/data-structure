#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void main()
{
    char a[3][3];

    for(int i=0;i<3;i++)
        {
            printf("enter element a[%d]:",i);
            scanf(" %s",&a[i]);
        }

    int index=rand()%3;
    char word[10];

    printf("enter anagram of the word[%d]:\n",index);
    scanf("%s",&word);

   strcmp(a[index],word) == 0 ? printf("Correct!\n") : printf("Incorrect!\n");

    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            printf("%c",a[i][j]);
        }
        printf("\n");
    }
}