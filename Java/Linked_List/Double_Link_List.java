package Linked_List;

import java.util.Scanner;

public class Double_Link_List
{
    private Node rfirst, lfirst, ptr, newNode, save;
    private Scanner sc = new Scanner(System.in);

    public void create()
    {
        int n, count = 1;
        System.out.print("Enter N: ");
        n = sc.nextInt();

        ptr = new Node();
        System.out.print("Enter info for " + 1 + " node: ");
        ptr.info = sc.nextInt();
        ptr.rlink = ptr.llink =  null;
        lfirst = rfirst =  ptr;

        while (count <= n - 1)
        {
            newNode = new Node();
            System.out.print("Enter info for " + (count + 1) + " node: ");
            newNode.info = sc.nextInt();

            newNode.llink = ptr;
            newNode.rlink = null;

            ptr.rlink = newNode;
            rfirst = newNode;
            ptr = newNode;
            count++;
        }
    }

    public void Rtraverse()
    {
        ptr = rfirst;
        while (ptr != null)
        {
            System.out.println(ptr.info);
            ptr = ptr.llink;
        }
    }
    public void Ltraverse()
    {
        ptr = lfirst;
        while (ptr != null)
        {
            System.out.println(ptr.info);
            ptr = ptr.rlink;
        }
    }

    public void Insert_at_Left()
    {
        newNode = new Node();
        System.out.println("Enter info for new node ");
        newNode.info = sc.nextInt();

        newNode.llink = null;
        newNode.rlink = lfirst;

        lfirst.llink = newNode;
        lfirst = newNode;
    }
    public void Insert_at_Right()
    {
        newNode = new Node();
        System.out.println("Enter info for new node ");
        newNode.info = sc.nextInt();

        newNode.rlink = null;
        newNode.llink = rfirst;

        rfirst.rlink = newNode;
        rfirst = newNode;
    }

    public void Insert_after_a_node()
    {
        // i will traverse from left to right in this example
        int item;
        System.out.println("Enter the Item after which u want to insert new element ");
        item = sc.nextInt();

        ptr = lfirst;

        while(ptr.rlink != null)
        {
            if (ptr.info == item)
            {
                newNode = new Node();
                System.out.println("Enter info for new node ");
                newNode.info = sc.nextInt();

                newNode.rlink = ptr.rlink;
                ptr.rlink.llink = newNode;
                ptr.rlink = newNode;
                newNode.llink = ptr;
                break;
            }
            ptr = ptr.rlink;
        }

        if (ptr.rlink == null)
        {
            System.out.println("Not Found");
        }
    }

    public void Delete_at_Left()
    {
        ptr = lfirst;
        lfirst = ptr.rlink;
        lfirst.llink = null;
    }

    public void Delete_at_Right()
    {
        ptr = rfirst;
        rfirst = ptr.llink;
        rfirst.rlink = null;
    }

    void Delete_after_a_Node()
    {
        // Using left to right approach
        int item;
        System.out.println("Enter the Item after which u want to delete item ");
        item = sc.nextInt();

        ptr = lfirst;

        while(ptr.rlink.rlink != null)
        {
            if (ptr.rlink.info == item)
            {
                save = ptr.rlink;
                ptr.rlink = save.rlink;
                save.rlink.llink = ptr;
                break;
            }
            ptr = ptr.rlink;
        }
        if (ptr.rlink.rlink == null)
        {
            System.out.println("Not Found");
        }
    }

}
