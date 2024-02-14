//  Application of stack :-------->>>>   infix to postfix conversion

#include <stdio.h>
#include <process.h>
#define max 100

char stack[max];
int top=-1;

void push(char item)
{
	if (top==max-1)
		printf("Overflow!!\n");
	else
		stack[++top] = item;
}

char pop()
{
	if (top==-1)
		printf("Underflow!!\n");
	else
		return stack[top--];
}

char peek()
{
	if (top==-1)
		printf("Underflow!!!\n");
	else
		return stack[top];
}

int is_empty()
{
	return (top==-1);
}


int get_precedence(char opr)		// function to check the precedence of the operator
{
	switch(opr)
	{
		case '+':
		case '-':
			return 1;
		case '*':
		case '/':
			return 2;
		case '^':
			return 3;
		default:
			return 0;
	}
}

void infix_to_postfix(char infix[], char postfix[])
{
	int i,j;
	char token;
	
	for (i=0, j=0; infix[i] != '\0'; i++)
	{
		token = infix[i];
		
		if (isalnum(token))
			postfix[j++]=token;
		else if (token == '(')
			push(token);
		else if (token==')')
		{
			while (!is_empty() && peek()!='(')
				postfix[j++] = pop();
			if (!is_empty() && peek()=='(')
				pop();
			else
				printf("Mismatched Parantheses");
		}
		else
		{
			while (!is_empty() && get_precedence(peek()) >= get_precedence(token))
				postfix[j++] = pop();
			push(token);
		}
	}
	
	while (!is_empty())
	{
		if (peek()=='(')
			printf("Mismatched parantheses");
		else
			postfix[j++] = pop();
	}
	postfix[j]='\0';
}

int main()
{
	char infix[max], postfix[max];
	
	printf("Enter an infix Expression");
	gets(infix);
	
	infix_to_postfix(infix, postfix);
	
	printf("postfix Expression\n");
	puts(postfix);
	
	return 0;
}
