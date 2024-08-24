#include <stdio.h>
#include <stdlib.h>
#include <process.h>

struct Node
{
	int info;
	struct Node *rlink, *llink;
};

struct Node *ptr, *rfirst, *lfirst, *newNode, *save;

void create();
void Rtraverse();
void Ltraverse();
void Insert_at_Left();
void Insert_at_Right();
void Insert_after_a_node();
void Delete_at_Left();
void Delete_at_Right();
void Delete_after_a_Node();

int main()
{
	int choice;
		do
	{
		printf("Enter your Choice\n1.Create linked list\n2.Traverse from Right\n3.Traverse from left\n4.Insert at Left\n5.Insert at Right\n6.Insert after a given Node\n7.Delete at Left\n8.Delete at Right\n9.Delete after a node\n10.Exit\n");
		scanf("%d", &choice);
		
		switch (choice)
		{
			case 1:
				create();
				break;
			case 2:
				Rtraverse();
				break;
			case 3:
				Ltraverse();
				break;
			case 4:
				Insert_at_Left();
				break;
			case 5:
				Insert_at_Right();
				break;
			case 6:
				Insert_after_a_node();
				break;
			case 7:
				Delete_at_Left();
				break;
			case 8:
				Delete_at_Right();
				break;
			case 9:
				Delete_after_a_Node();
				break;
			case 10:
				exit(0);
			default:
				printf("Wrong Choice");
		}
	}while (choice != 10);	
	
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
	
	ptr->rlink = NULL;
	ptr->llink = NULL;
	
	lfirst = ptr;
	rfirst = ptr;
	
	while(count<=N-1)
	{
		newNode = (struct Node*)malloc(sizeof(struct Node));
		printf("Enter Info for %d node  ",count+1);
		scanf("%d", &newNode->info);
		
		newNode->llink = ptr;
		newNode->rlink = NULL;
		
		ptr->rlink = newNode;
		
		rfirst = newNode;
		
		ptr = newNode;
		count++;
	}	
	
}

void Rtraverse()	// Right to left
{
	ptr = rfirst;
	while(ptr != NULL)
	{
		printf("%d\n", ptr->info);
		ptr = ptr->llink;
	}
}

void Ltraverse()		// Left to Right
{
	ptr = lfirst;
	while(ptr != NULL)
	{
		printf("%d\n", ptr->info);
		ptr = ptr->rlink;
	}	
}

void Insert_at_Left()
{
	newNode = (struct Node*)malloc(sizeof(struct Node));
	printf("Enter Info of New Node  ");
	scanf("%d", &newNode->info);
	
	newNode->llink = NULL;
	newNode->rlink = lfirst;
	
	lfirst->llink = newNode;
	lfirst = newNode;
}

void Insert_at_Right()
{
	newNode = (struct Node*)malloc(sizeof(struct Node));
	printf("Enter Info of New Node  ");
	scanf("%d", &newNode->info);
	
	newNode->rlink = NULL;
	newNode->llink = rfirst;
	
	rfirst->rlink = newNode;
	rfirst = newNode;
}

void Insert_after_a_node()
{	
	// i will traverse from left to right in this example

	int item;
	printf("Enter the Item after which u want to insert new element ");
	scanf("%d", &item);
	
	ptr = lfirst;
		
	while(ptr->rlink != NULL)
	{
		if (ptr->info == item)
		{
			newNode = (struct Node*)malloc(sizeof(struct Node));
			printf("Enter info Of New Node  ");
			scanf("%d", &newNode->info);
			
			newNode->rlink = ptr->rlink;
			ptr->rlink->llink = newNode;
			ptr->rlink = newNode;
			newNode->llink = ptr;
			break;
		}
		ptr = ptr->rlink;
	}
	
	if (ptr->rlink == NULL)
	{
		printf("Not Found\n");
	}
	
}

void Delete_at_Left()
{
	ptr = lfirst;
	lfirst = ptr->rlink;
	lfirst->llink = NULL;
	free(ptr);
}

void Delete_at_Right()
{
	ptr = rfirst;
	rfirst = ptr->llink;
	rfirst->rlink = NULL;
	free(ptr);
}

void Delete_after_a_Node()
{
	// Using left to right approach
	int item;
	printf("Enter the Item after which u want to delete item ");
	scanf("%d", &item);
	
	ptr = lfirst;
	
	while(ptr->rlink->rlink != NULL)
	{
		if (ptr->rlink->info == item)
		{
			// This one deletes, the entered node. comment one deletes node after.
			save = ptr->rlink;
			ptr->rlink = save->rlink;
			save->rlink->llink = ptr;
			/*
			save = ptr->rlink->rlink;
			ptr->rlink->rlink = save->rlink;
			save->rlink->llink = ptr->rlink;
			*/
			free(save);
			break;
		}
		ptr = ptr->rlink;
	}
	if (ptr->rlink->rlink == NULL)
	{
		printf("Not Found");
	}
}
