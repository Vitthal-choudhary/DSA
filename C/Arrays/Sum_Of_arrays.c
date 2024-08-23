#include <stdio.h>

int main()
{
    int a[10][10],b[10][10],c[10][10],m,n,p,q,i,j;  // a[mXn] , b[pXq]
    printf("enter m,n,p,q");
    scanf("%d%d%d%d", &m,&n,&p,&q);

    if (m==p && n==q)
    {
        for (i = 0; i < m; i++)
        {
            for (j = 0; j < n; j++)
            {
                printf("enter element");
                scanf("%d",&a[i][j]);
            }
        }
        
        printf("\n For matrix 2 \n");
        for (i = 0; i < p; i++)
        {
            for (j = 0; j < q; j++)
            {
                printf("enter element");
                scanf("%d",&b[i][j]);
            }
        }

        printf("\nResultant Matrix\n");
        for (i = 0; i < m; i++)
        {
            for (j = 0; j < n; j++)
            {
                c[i][j] = a[i][j] + b[i][j];
                printf("%d ", c[i][j]);
            }
            printf("\n");
        }
    }
    else
        printf("addition not possible");

    return 0;
}