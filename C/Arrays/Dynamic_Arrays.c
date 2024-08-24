#include<stdio.h>

int main(){
    // int a[] = {6,58,42,69,41};

    // gives address of a[0]
    // printf("%d\n", a);    
    // printf("%d\n", &a[0]);
    // printf("%d\n", &a);


    // 2 ways to access arrays elements
    //printf("%d\n", a[2]);
    //printf("%d\n", *(a+2));

    int a[] = {6,58,42,69,41};
    int *p = a;

    for(int i=0; i<5; i++){
        printf("%d\n", *p);
        p++;
    }

    //2D Arrays
    int b[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    int *q = b[0];

    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            printf("%d ", *q);
            q++;
        }
        printf("\n");
    }


    return 0;
}