// 1st application of stack :--------->  Reversing a string

#include <stdio.h>
#include <process.h>
#define max 10

void push(char);
char pop();

char S[max];
int top=-1;

main()
{
	char a[10];
	int index=0;
	printf("Enter String   ");
	gets(a);
	while (a[index] != '\0')
	{
		push(a[index]);
		index++;
	}
	while (top >= 0)
	{
		printf("%c", pop());
		top--;
	}
}

void push(char t)
{
	top++;
	S[top] = t;
}
char pop()
{
	return S[top];
}
