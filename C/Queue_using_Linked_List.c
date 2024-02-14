#include <stdio.h>
#include <stdlib.h>
#include <process.h>

struct Node
{
	int info;
	struct Node *link;
};

struct Node *ptr, *first, *newNode;

void create();
void traverse();
void push();
void pop();

int main()
{
	int choice;
	do
	{
		printf("Enter your Choice\n1.Create Queue\n2.Traverse\n3.Push \n4.Pop\n5.Exit\n");
		scanf("%d", &choice);
		
		switch (choice)
		{
			case 1:
				create();
				break;
			case 2:
				traverse();
				break;
			case 3:
				push();
				break;
			case 4:
				pop();
				break;
			case 5:
				exit(0);
				break;
			default:
				printf("Wrong Choice Nigga!!!\n");
		}
	}while (choice != 5);
	return 0;				
}

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

void push()
{
	newNode = (struct Node*)malloc(sizeof(struct Node));
	printf("Enter Info for new Node  ");
	scanf("%d", &newNode->info);
	ptr = first;
	while(ptr->link != NULL)
	{
		ptr = ptr->link;
	}
	newNode->link = NULL;
	ptr->link = newNode;
}

void pop()
{
	ptr = first;
	first = ptr->link;
	free(ptr);
}
