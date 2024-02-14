package Linked_List;

import java.util.Scanner;

public class LinkedList
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

    public void traverse() {
        ptr = first;
        while (ptr != null) {
            System.out.println(ptr.info);
            ptr = ptr.link;
        }
    }

    public void insertAtBegin() {
        newNode = new Node();
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter Info of New Node: ");
        newNode.info = sc.nextInt();

        newNode.link = first;
        first = newNode;
    }

    public void insertAtEnd() {
        newNode = new Node();
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter Info of New Node: ");
        newNode.info = sc.nextInt();

        ptr = first;
        while (ptr.link != null) {
            ptr = ptr.link;
        }
        newNode.link = null;
        ptr.link = newNode;
    }

    public void insertInMid() {
        int item;
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the Item after which you want to insert a new element: ");
        item = sc.nextInt();

        ptr = first;
        while (ptr.link != null) {
            if (ptr.info == item) {
                newNode = new Node();
                System.out.print("Enter info Of New Node: ");
                newNode.info = sc.nextInt();

                newNode.link = ptr.link;
                ptr.link = newNode;
                break;
            }
            ptr = ptr.link;
        }

        if (ptr.link == null) {
            System.out.println("Not Found");
        }
    }

    public void deleteAtBegin() {
        ptr = first;
        first = ptr.link;
        ptr = null;
    }

    public void deleteAtEnd() {
        ptr = first;
        while (ptr.link.link != null) {
            ptr = ptr.link;
        }
        save = ptr.link;
        ptr.link = null;
        save = null;
    }

    public void deleteInMid() {
        int item;
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the Item after which you want to delete an item: ");
        item = sc.nextInt();

        ptr = first;
        while (ptr.link.link != null) {
            if (ptr.link.info == item) {
                save = ptr.link;
                ptr.link = save.link;
                save = null;
                break;
            }
            ptr = ptr.link;
        }
        if (ptr.link.link == null) {
            System.out.println("Not Found");
        }
    }
}
