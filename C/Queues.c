#include<stdio.h>
#include<process.h>
#define max 5

int Q[max], front=-1, rear=-1;

void show();
void push();
void pop();

main()
{
	int choice;
	do
	{
		printf("Enter your Choice\n1.Show\n2.Push\n3.Pop\n4.To Quit\n");
		scanf("%d", &choice);
		
		switch(choice)
		{
			case 1:
				show();
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
		
	}while (choice!=4);
}

void show()
{
	int i;
	for(i=front; i<=rear;i++)
	{
		printf("%d \n", Q[i]);
	}
}

void push()
{
	if (rear==max-1)
		printf("Overflow!!!!");
	else
	{
		int item;
		printf("Enter item   ");
		scanf("%d",&item);
		rear++;
		if (front==-1)
			front++;
		Q[rear]=item;
	}
}

void pop()
{
	if (front==-1)
		printf("Underflow!!!!");
	else
	{
		printf("%d ", Q[front]);
		front++;
		if (front>rear)
		{
			front = -1;
			rear = -1;
		}
	}
}
