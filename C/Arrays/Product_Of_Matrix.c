#include <stdio.h>

int main()
{
    int a[10][10],b[10][10],c[10][10],m,n,p,q,i,j,k;  // a[mXn] , b[pXq]
    printf("enter m,n,p,q");
    scanf("%d%d%d%d", &m,&n,&p,&q);

    if (n==p)
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
            for (j = 0; j < q; j++)
            {
                c[i][j] = 0;
                for (k = 0; k < n; k++)
                {
                    c[i][j] += a[i][j] * b[k][j];
                }
                printf("%d ", c[i][j]);                
            }
            printf("\n");
        }
    }
    else
        printf("multiplication not possible");

    return 0;
}