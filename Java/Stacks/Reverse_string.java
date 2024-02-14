// Application 1 of Stacks:-------   Reversing a string

package Stacks;

import java.util.Scanner;

class Rev_Str_with_Stacks
{
    int max=20, top=-1;
    char[] Stack;
    Scanner Sc;

    public Rev_Str_with_Stacks()
    {
        Sc = new Scanner(System.in);
        Stack = new char[max];
    }
    public void push(char ch)
    {
        top++;
        Stack[top]=ch;
    }
    public char pop()
    {
        return Stack[top--];
    }
    public boolean is_empty()
    {
        return top==-1;
    }

}

public class Reverse_string
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        Rev_Str_with_Stacks obj = new Rev_Str_with_Stacks();

        String str;
        System.out.println("Enter the string you want to reverse");
        str = sc.nextLine();

        for (int i=0; i<str.length(); i++)
        {
            obj.push(str.charAt(i));
        }

        while (!obj.is_empty())
        {
            System.out.print(obj.pop());
        }
    }
}
