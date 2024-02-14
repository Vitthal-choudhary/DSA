package Linked_List;

import java.util.Scanner;

public class Stack_Using_Linked_List
{
    private Node first, ptr, newNode, save;
    private Scanner sc = new Scanner(System.in);
    public void create()
    {
        int n, count = 1;
        System.out.print("Enter N: ");
        n = sc.nextInt();
        ptr = new Node();
        System.out.print("Enter info for " + 1 + " node: ");
        ptr.info = sc.nextInt();
        ptr.link = null;
        first = ptr;

        while (count <= n - 1)
        {
            newNode = new Node();
            System.out.print("Enter info for " + (count + 1) + " node: ");
            newNode.info = sc.nextInt();
            newNode.link = null;
            ptr.link = newNode;
            ptr = newNode;
            count++;
        }
    }

    public void traverse()
    {
        ptr = first;
        while (ptr != null)
        {
            System.out.println(ptr.info);
            ptr = ptr.link;
        }
    }
    public void push()
    {
        newNode = new Node();
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter Info of New Node: ");
        newNode.info = sc.nextInt();

        newNode.link = first;
        first = newNode;
    }
    public void pop()
    {
        ptr = first;
        first = ptr.link;
        ptr = null;
    }
}
