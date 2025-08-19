#include<stdio.h>
#include<stdlib.h>

void main()
{
    int *intp = (int *)malloc(sizeof(int));
    float *floap = (float *)malloc(sizeof(float));
    char *charp = (char *)malloc(sizeof(char));

    printf("Enter an integer: ");
    scanf("%d", intp);

    printf("enter a float:");
    scanf("%f",floap);

    printf("enter a char:");
    scanf(" %c",charp);

    printf("int =%d \n float = %f \n char = %c\n",*intp , *floap , *charp);

    free(intp);
    free(floap);
    free(charp);
}