/*
The below implementation of stack is done using arrays of C language
*/

#include <stdio.h>
#include <process.h>
#define MAX 5

int Stack[MAX], top=-1;

void show();
void push();
void pop();

int main()
{
	int choice;
	do
	{
		printf("Enter your Choice\n1.Show Stack\n2.Push\n3.Pop\n4.To Quit\n");
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
	for(i=top; i>=0; i--)
	{
		printf("%d \n", Stack[i]);
	}
}

void  push()
{
	if (top==MAX-1)
		printf("Overflow!!!!!!  Can't Push to Stack");
	else
	{
		int item;
		printf("enter item  ");
		scanf("%d", &item);
		top++;
		Stack[top] = item;
	}
}

void pop()
{
	if (top==-1)
		printf("Underflow !!!!!!!!  Can't pop from empty stack");
	else
	{
		printf("Item Popped is %d\n", Stack[top]);
		top--;
	}
}
