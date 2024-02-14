#include<stdio.h>
#define max 100

int stack[max];
int top=-1;

void push(int item)
{
	if (top == max - 1) 
        printf("Error: Stack overflow\n");
    else
    	stack[++top] = item;
}

int pop()
{
    if (top == -1)
        printf("Error: Stack underflow\n");
    else
    	return stack[top--];
}

int peek()
{
    if (top == -1)
        printf("Error: Stack is empty\n");
    else
    	return stack[top];
}

int isEmpty()
{
    return (top == -1);
}

int evaluatePostfix(char postfix[]) {
    int i, operand, result;
    char token;

    for (i = 0; postfix[i] != '\0'; i++) {
        token = postfix[i];

        if (isdigit(token))
		{
            operand = token - '0';
            push(operand);
        } 
		else
		{
            int operand2 = pop();
            int operand1 = pop();

            switch (token) {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    result = operand1 / operand2;
                    break;
                default:
                    printf("Error: Invalid operator\n");
            }
            push(result);
        }
    }

    if (!isEmpty()) 
	{
        result = pop();
        return result;
    } 
	else
	{
        printf("Error: Empty postfix expression\n");
    }
}

int main()
{
    char postfix[max];

    printf("Enter a postfix expression: ");
    scanf("%s", postfix);

    int result = evaluatePostfix(postfix);

    printf("Result of postfix expression: %d\n", result);

    return 0;
}

