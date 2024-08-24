#include <stdio.h>
#include <stdlib.h>
#include <process.h>

struct Node
{
	int info;
	struct Node *link;
};

struct Node *ptr, *first, *newNode, *save;

void create();
void traverse();
void insert_at_begin();
void insert_at_end();
void insert_in_mid();
void del_at_begin();
void del_at_end();
void del_at_mid();

int main()
{
	int choice;
	do
	{
		printf("Enter your Choice\n1.Create linked list\n2.Traverse\n3.Insert at begin\n4.Insert at end\n5.Insert in mid\n6.Delete at Begin\n7.Delete at end\n8.Delete in middle\n9.Exit\n");
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
				insert_at_begin();
				break;
			case 4:
				insert_at_end();
				break;
			case 5:
				insert_in_mid();
				break;
			case 6:
				del_at_begin();
				break;
			case 7:
				del_at_end();
				break;
			case 8:
				del_at_mid();
				break;
			case 9:
				exit(0);
			default:
				printf("Wrong Choice");
		}
		
	}while (choice != 9);
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

void insert_at_begin()
{
	newNode = (struct Node*)malloc(sizeof(struct Node));
	printf("Enter Info of New Node  ");
	scanf("%d", &newNode->info);
	
	newNode->link = first;
	first = newNode;
}

void insert_at_end()
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

void insert_in_mid()
{
	int item;
	printf("Enter the Item after which u want to insert new element ");
	scanf("%d", &item);
	
	ptr = first;
	
	while(ptr->link != NULL)
	{
		if (ptr->info == item)
		{
			newNode = (struct Node*)malloc(sizeof(struct Node));
			printf("Enter info Of New Node  ");
			scanf("%d", &newNode->info);
			
			newNode->link = ptr->link;
			ptr->link = newNode;
			break;
		}
		ptr = ptr->link;
	}
	
	if (ptr->link == NULL)
	{
		printf("Not Found\n");
	}
}

void del_at_begin()
{
	ptr = first;
	first = ptr->link;
	free(ptr);
}

void del_at_end()
{
	ptr = first;
	while (ptr->link->link != NULL)
	{
		ptr = ptr->link;	
	}
	save = ptr->link;
	ptr->link = NULL;
	free(save);	
}

void del_at_mid()
{
	int item;
	printf("Enter the Item after which u want to delete item ");
	scanf("%d", &item);
	
	ptr = first;
	while(ptr->link->link != NULL)
	{
		if (ptr->link->info == item)
		{
			save = ptr->link;
			ptr->link = save->link;
			free(save);
			break;
		}
		ptr = ptr->link;
	}
	if (ptr->link->link == NULL)
	{
		printf("Not Found");
	}
}
