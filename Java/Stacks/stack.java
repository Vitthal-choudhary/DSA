package Stacks;

import java.util.Scanner;

class Stack_operations_using_array_approach
{
    int max = 5, top = -1;
    int[] stack;
    Scanner sc;

    public Stack_operations_using_array_approach()
    {
        stack = new int[max];
        sc = new Scanner(System.in);
    }
    void show()
    {
        for (int i=top; i>=0; i--)
            System.out.println(stack[i]);
    }

    void push()
    {
        if (top==max-1)
            System.out.println("Overflow !!!!!!  Can't push to stack");
        else
        {
            int item;
            System.out.println("enter item");
            item = sc.nextInt();
            top++;
            stack[top]=item;
        }
    }

    void pop()
    {
        if (top == -1)
            System.out.println("Underflow !!!  Can't pop from empty stack");
        else
        {
            System.out.println("Item Popped is " + stack[top]);
            top--;

        }
    }
}


public class stack
{
    public static void main(String[] args)
    {
        Scanner sc2;
        sc2 = new Scanner(System.in);
        Stack_operations_using_array_approach st = new Stack_operations_using_array_approach();
        int choice;
        do
        {
            System.out.println("Enter choice \n1.Show\n2.push\n3.pop\n4.exit");
            choice = sc2.nextInt();
            switch (choice)
            {
                case 1:
                    st.show();
                    break;
                case 2:
                    st.push();
                    break;
                case 3:
                    st.pop();
                    break;
                case 4:
                    System.exit(0);
                    break;
                default:
                    System.out.println("Wrong Choice Nigga !!");
            }
        }while (choice!=4);
    }
}
