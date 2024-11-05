#include<stdio.h>
#include<stdlib.h>
#include<process.h>

struct Node{
    int info, priority;
    struct Node *link;
};

struct Node *ptr, *first, *newNode;

void create();
void traverse();    
void push();
void pop();

int main(){
    create();
    int choice;
    do{
        printf("Enter your Choice\n1.Show\n2.Push\n3.Pop\n4.To Quit\n");
        scanf("%d", &choice);        
        switch(choice){
            case 1:
                traverse();
                break;
            case 2:
                push();
                break;
            case 3:
                pop();
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("Wrong Choice");
        }
    }while(choice!=4);
    return 0;
}

void create(){
    int N, count = 0;
    printf("Enter the number of elements\n");
    scanf("%d", &N);

    if (N > 0) {
        ptr = (struct Node*)malloc(sizeof(struct Node));
        printf("Enter the priority of the first element\n");
        scanf("%d", &ptr->priority);
        printf("Enter the info of the first element\n");
        scanf("%d", &ptr->info);
        ptr->link = NULL;
        first = ptr;
        count++;

        while(count < N){
            newNode = (struct Node*)malloc(sizeof(struct Node));
            printf("Enter the priority of element %d\n", count+1);
            scanf("%d", &newNode->priority);
            printf("Enter the info of element %d\n", count+1);
            scanf("%d", &newNode->info);
            newNode->link = NULL;
            ptr->link = newNode;
            ptr = newNode;
            count++;
        }
    }
}

void traverse(){
    ptr = first;
    while(ptr!=NULL){
        printf("%d  %d\n", ptr->info, ptr->priority);
        ptr = ptr->link;
    }
}

void push(){
    ptr = first;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter the priority of the new element\n");
    scanf("%d", &newNode->priority);
    printf("Enter the info of the new element\n");
    scanf("%d", &newNode->info);
    
    if(ptr->priority > newNode->priority){
        newNode->link = first;
        first = newNode;
    }
    else{
        while((ptr->priority <= newNode->priority)&&(ptr->link!=NULL)){
            ptr = ptr->link;
        }
        newNode->link = ptr->link;
        ptr->link = newNode;
    }
}

void pop(){
    ptr = first;
    first = ptr->link;
    free(ptr);
}
