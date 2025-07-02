#include<stdio.h>
void main()
{
    int c[10][10]; // Assuming a maximum size for the resultant matrix
    int i, j, k, m, n, p, q;

    printf("Enter the number of rows and columns for first matrix: ");
    scanf("%d %d", &m, &n);
    int a[m][n];

    printf("Enter the elements of first matrix:\n");
    for(i = 0; i < m; i++)
        for(j = 0; j < n; j++)
            scanf("%d", &a[i][j]);

    printf("Enter the number of rows and columns for second matrix: ");
    scanf("%d %d", &p, &q);
    int b[p][q];

    printf("Enter the elements of second matrix:\n");
    for(i = 0; i < p; i++)
        for(j = 0; j < q; j++)
            scanf("%d", &b[i][j]);

    for(i = 0; i < m; i++)
        for(j = 0; j < q; j++)
            c[i][j] = a[i][j] + b[i][j];

    printf("Resultant matrix after addition:\n");
    for(i = 0; i < m; i++) {
        for(j = 0; j < q; j++)
            printf("%d ", c[i][j]);
        printf("\n");
    }
}