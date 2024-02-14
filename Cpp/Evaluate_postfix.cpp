#include<iostream>
#define max 100

using namespace std;

class Stack_operations
{
	int stack[max];
	int top;
	public:
		Stack_operations()
		{
			top=-1;
		}
		void push(int item)
		{
			stack[++top] = item;
		}
		
		int pop()
		{
			return stack[top--];
		}
		
		int peek()
		{
		    return stack[top];
		}
		
		int isEmpty()
		{
		    return (top == -1);
		}
};

int evaluate_postfix(char postfix[])
{
	int i,operand,result;
	char token;
	Stack_operations st;
	
	for (i = 0; postfix[i] != '\0'; i++)
	{
        token = postfix[i];

        if (isdigit(token))
		{
            operand = token - '0';
            st.push(operand);
        } 
        else
        {
        	int operand2 = st.pop();
            int operand1 = st.pop();

            switch (token) 
			{
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
                    cout << "Error: Invalid operator\n";
            }
            st.push(result);
		}
	}
    if (!st.isEmpty()) 
	{
        result = st.pop();
        return result;
    } 
	else
        cout << "Error: Empty postfix expression\n";
}

int main()
{
    char postfix[max];

    cout << "Enter a postfix expression: ";
    gets(postfix);

    int result = evaluate_postfix(postfix);

    printf("Result of postfix expression: %d\n", result);

    return 0;
}
