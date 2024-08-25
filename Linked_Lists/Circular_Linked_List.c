#include <stdio.h>
#include <stdlib.h>
#include <process.h>

struct Node
{
	int info;
	struct Node *link;
};

struct Node *ptr, *tail, *newNode, *save;

void create();
void Display();
void insert_at_begin();
void insert_at_end();
void insert_in_mid();
void del_at_begin();
void del_at_end();
void del_at_mid();

void main(){
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
					Display();
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

void create(){
    int N, count=1;
	printf("enter Number of Nodes for Linked List  ");
	scanf("%d", &N);
	ptr = (struct Node *)malloc(sizeof(struct Node));
	printf("Enter Info for first node  ");
	scanf("%d", &ptr->info);
	ptr->link = NULL;
	tail = ptr;
	while(count<=N-1)
	{
		newNode = (struct Node*)malloc(sizeof(struct Node));
		printf("Enter Info for %d node  ",count+1);
		scanf("%d", &newNode->info);
		newNode->link = NULL;
		tail->link = newNode;
		tail = newNode;
		count++;
	}
    tail->link = ptr;
}

void Display(){
    ptr = tail->link;
    while(ptr != tail){
        printf("%d\n", ptr->info);
        ptr = ptr->link;
    }
    printf("%d\n", ptr->info);
}

void insert_at_begin(){
    newNode = (struct Node*)malloc(sizeof(struct Node));
	printf("Enter Info of New Node  ");
	scanf("%d", &newNode->info);

    newNode->link = tail->link;
    tail->link = newNode;
}

void insert_at_end(){
    ptr = tail;
    newNode = (struct Node*)malloc(sizeof(struct Node));
	printf("Enter Info of New Node  ");
	scanf("%d", &newNode->info);

    newNode->link = tail->link;
    tail->link = newNode;
    tail = newNode;
}

void insert_in_mid()
{
	int item;
	printf("Enter the Item after which u want to insert new element ");
	scanf("%d", &item);
	ptr = tail->link;
	while(ptr != tail)
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
	if (ptr == tail)
	{
 		if (ptr->info == item)
		{
            insert_at_end();
		}
        else
            printf("Not Found");
	}
}

void del_at_begin(){
    save = tail->link;
    tail->link = save->link;
    free(save);
}

void del_at_end(){
    ptr = tail->link;
    while(ptr->link != tail){
        ptr = ptr->link;
    }
	save = ptr->link;
	ptr->link = tail->link;
    tail = ptr;
    free(save);
}

void del_at_mid(){
	int item;
	printf("Enter the Item which u want to delete ");
	scanf("%d", &item);
	
	ptr = tail->link;
	while(ptr->link->link != tail)
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
	if (ptr->link->link == tail)
	{
		if (ptr->link->info == item)
		{
			save = ptr->link;
			ptr->link = save->link;
			free(save);
		}
		else
			printf("Not Found");
	}
}