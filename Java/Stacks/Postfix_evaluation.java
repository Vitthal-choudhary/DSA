package Stacks;

import java.util.Scanner;

class int_Stk_operations
{
    int top=-1, max=100;
    int[] stack = new int[max];
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
    boolean is_empty()
    {
        return top==-1;
    }
}
public class Postfix_evaluation extends int_Stk_operations
{
    int eval_postfix(char[] postfix)
    {
        int i, operand, result;
        char token;

        for (i=0; i<postfix.length; i++)
        {
            token = postfix[i];

            if (Character.isDigit(token))
            {
                operand = token-'0';
                push(operand);
            }
            else
            {
                int o2 = pop();
                int o1 = pop();

                switch (token)
                {
                    case '+':
                        result=o1+o2;
                        push(result);
                        break;
                    case '-':
                        result=o1-o2;
                        push(result);
                        break;
                    case '*':
                        result=o1*o2;
                        push(result);
                        break;
                    case '/':
                        result=o1/o2;
                        push(result);
                        break;
                    default:
                        System.out.println("Wrong Choice");
                }
            }
        }
        if (!is_empty())
        {
            result = pop();
            return result;
        }
        else
            return 0;
    }
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        String postfix;
        System.out.println("Enter a postfix expression ");
        postfix = sc.next();

        Postfix_evaluation ex = new Postfix_evaluation();
        int result = ex.eval_postfix(postfix.toCharArray());
        System.out.println(result);
    }
}
