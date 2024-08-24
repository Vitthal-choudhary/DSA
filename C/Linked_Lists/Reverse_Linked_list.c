#include <stdio.h>
#include <stdlib.h>
#include <process.h>

struct Node
{
	int info;
	struct Node *link;
};

struct Node *ptr, *first, *newNode, *prev, *next;

void create()
{
	int N, count=1;
	printf("enter N  ");
	scanf("%d", &N);
	
	ptr = (struct Node *)malloc(sizeof(struct Node));
	printf("Enter Info for first node  ");
	scanf("%d", &ptr->info);
	
	ptr->link = NULL;
	
	first = ptr;
	
	while(count<=N-1)
	{
		newNode = (struct Node*)malloc(sizeof(struct Node));
		printf("Enter Info for %d node  ",count+1);
		scanf("%d", &newNode->info);
		
		newNode->link = NULL;
		ptr->link = newNode;
		
		ptr = newNode;
		count++;
	}
}

void traverse()
{
	ptr = first;
	while(ptr != NULL)
	{
		printf("%d\n", ptr->info);
		ptr = ptr->link;
	}
}

void Reverse(){
    prev = NULL;
    ptr = first;
    next = first;

    while(next != NULL){
        next = next->link;
        ptr->link = prev;
        prev = ptr;
        ptr = next;
    }
    first = prev;
}

void main(){
    create();
    traverse();
    Reverse();
    traverse();
}