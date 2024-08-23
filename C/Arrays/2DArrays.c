#include <stdio.h>

int main()
{
    // init  --->  a[3][3] = {{1,2,3}, {4,5,6}, {7,8,9}}
    int a[3][3],i,j, rowsum,colsum,disum=0;
;
    for (i = 0; i <= 2; i++)
    {
        for (j = 0; j <= 2; j++)
        {
            printf("enter element ");
            scanf("%d", &a[i][j]);
        }
    }

    for ( i = 0; i <= 2; i++)
    {
        for (j = 0; j <= 2; j++)
        {
            printf("%d  ", a[i][j]);        // to print column wise  put a[j][i]
        }
        printf("\n");
    }   


    // Calculating Row Sum, Column SUm and Sum of Diagonal Elements
    for (int i = 0; i < 3; i++)
    {
        rowsum = 0;
        colsum = 0;
        for (int j = 0; j < 3; j++)
        {
            rowsum += a[i][j];
            colsum += a[j][i];
            if (i==j)
                disum += a[i][j];
        }
        printf("%dth row's sum = %d\n%dth Column sum = %d\n", i, rowsum, i, colsum);
    }
    
    printf("%d", disum);  

    return 0;
}