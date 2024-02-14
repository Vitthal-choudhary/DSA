//  Application of stack :-------->>>>   infix to postfix conversion

#include <iostream>
#define max 100

using namespace std;

class Expression_Conversion
{
	int top;
	char stack[max];
	
	public:
	Expression_Conversion()
	{
		top=-1;	
	}
	
	void push(char item)
	{
		if (top==max-1)
			cout << "Overflow!!\n";
		else
			stack[++top] = item;
	}	
	
	char pop()
	{
		if (top==-1)
			cout << "Underflow!!\n";
		else
			return stack[top--];
	}
	
	char peek()
	{
		if (top==-1)
			cout << "Underflow!!!\n";
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
					cout << "Mismatched Parantheses";
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
				cout << "Mismatched parantheses";
			else
				postfix[j++] = pop();
		}
		postfix[j]='\0';
	}
};

int main()
{
	char infix[max], postfix[max];
	Expression_Conversion ex;
	
	cout << "Enter an infix Expression";
	gets(infix);
	
	ex.infix_to_postfix(infix, postfix);
	
	cout << "postfix Expression\n";
	puts(postfix);
	
	return 0;
}
