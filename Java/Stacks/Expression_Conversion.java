package Stacks;

import java.util.Scanner;

class Stk_operations
{
    int top=-1, max=100;
    char[] stack = new char[max];
    void push(char item)
    {
        if (top==max-1)
            System.out.println("Overflow!!\n");
        else
            stack[++top] = item;
    }
    char pop()
    {   char ch = ' ';
        if (top==-1)
            System.out.println("Underflow!!\n");
        else
            ch = stack[top--];
        return ch;
    }
    char peek()
    {   char ch=' ';
        if (top==-1)
            System.out.println("Underflow!!!\n");
        else
            ch = stack[top];
        return ch;
    }
    boolean is_empty()
    {
        return top==-1;
    }
}

public class Expression_Conversion extends Stk_operations
{
    public int get_precedence(char operator)
    {
        switch (operator)
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
    public void In_to_pos(char[] infix, char[] postfix)
    {
        int i,j;
        char token;

        for (i=0, j=0; i<infix.length; i++)
        {
            token = infix[i];

            if (Character.isAlphabetic(token))
                postfix[j++] = token;
            else if (token=='(')
                push(token);
            else if (token==')')
            {
                while (!is_empty() && peek()!='(')
                    postfix[j++] = pop();
                if (!is_empty() && peek()=='(')
                    pop();
                else
                    System.out.println("Mismatched parantheses");
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
                System.out.println("Mismatched Parantheses");
            else
                postfix[j++] = pop();
        }
    }

    public static void main(String[] args)
    {
        String infix;
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the infix expression");
        infix = sc.next();
        char[] postfix = new char[infix.length()];

        Expression_Conversion ex = new Expression_Conversion();
        ex.In_to_pos(infix.toCharArray(), postfix);

        System.out.println("Postfix expression");
        int i=0;
        while (Character.isDefined(postfix[i]))
        {
            System.out.println(postfix[i]);
            i++;
        }
    }
}
