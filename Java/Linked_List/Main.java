package Linked_List;

import java.util.Scanner;

class Node
{
    public int info;
    public Node link, rlink, llink;
}

public class Main
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        int choice;

        /*
        LinkedList l = new LinkedList();
        do
        {
            System.out.println("Enter your Choice\n1.Create linked list\n2.Traverse\n3.Insert at begin\n4.Insert at end\n5.Insert in mid\n6.Delete at Begin\n7.Delete at end\n8.Delete in middle\n9.Exit");
            choice = sc.nextInt();

            switch (choice) {
                case 1:
                    l.create();
                    break;
                case 2:
                    l.traverse();
                    break;
                case 3:
                    l.insertAtBegin();
                    break;
                case 4:
                    l.insertAtEnd();
                    break;
                case 5:
                    l.insertInMid();
                    break;
                case 6:
                    l.deleteAtBegin();
                    break;
                case 7:
                    l.deleteAtEnd();
                    break;
                case 8:
                    l.deleteInMid();
                    break;
                case 9:
                    System.exit(0);
                default:
                    System.out.println("Wrong Choice");
            }
        } while (choice!=9);
        */


        /*
        Stack_Using_Linked_List stack = new Stack_Using_Linked_List();
        do
        {
            System.out.println("Enter your Choice\n1.Create stack\n2.Traverse\n3.Push\n4.Pop\n5.Exit");
            choice = sc.nextInt();

            switch (choice)
            {
                case 1:
                    stack.create();
                    break;
                case 2:
                    stack.traverse();
                    break;
                case 3:
                    stack.push();
                    break;
                case 4:
                    stack.pop();
                    break;
                case 5:
                    System.exit(0);
                default:
                    System.out.println("Wrong Choice");
            }
        } while (choice!=9);



        Queue_using_Linked_List queue = new Queue_using_Linked_List();
        do
        {
            System.out.println("Enter your Choice\n1.Create Queue\n2.Traverse\n3.Push\n4.Pop\n5.Exit");
            choice = sc.nextInt();

            switch (choice)
            {
                case 1:
                    queue.create();
                    break;
                case 2:
                    queue.traverse();
                    break;
                case 3:
                    queue.push();
                    break;
                case 4:
                    queue.pop();
                    break;
                case 5:
                    System.exit(0);
                default:
                    System.out.println("Wrong Choice");
            }
        } while (choice!=9);

         */

        Double_Link_List dl = new Double_Link_List();
        do
        {
            System.out.println("Enter your Choice\n1.Create linked list\n2.Traverse from Right\n3.Traverse from left\n4.Insert at Left\n5.Insert at Right\n" +
                    "6.Insert after a given Node\n7.Delete at Left\n8.Delete at Right\n9.Delete after a node\n10.Exit\n");
            choice = sc.nextInt();

            switch (choice)
            {
                case 1:
                    dl.create();
                    break;
                case 2:
                    dl.Rtraverse();
                    break;
                case 3:
                    dl.Ltraverse();
                    break;
                case 4:
                    dl.Insert_at_Left();
                    break;
                case 5:
                    dl.Insert_at_Right();
                    break;
                case 6:
                    dl.Insert_after_a_node();
                    break;
                case 7:
                    dl.Delete_at_Left();
                    break;
                case 8:
                   dl.Delete_at_Right();
                    break;
                case 9:
                    dl.Delete_after_a_Node();
                    break;
                case 10:
                    System.exit(0);
                default:
                    System.out.println("Wrong Choice");
            }
        } while (choice!=10);

    }
}

