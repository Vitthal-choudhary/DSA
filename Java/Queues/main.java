package Queues;

import java.util.Scanner;

class Circular_Queues
{
    int max=5, front=-1, rear=-1;
    int[] Q;
    Scanner Sc;

    public Circular_Queues()
    {
        Q = new int[max];
        Sc = new Scanner(System.in);
    }
    void show()
    {
        if (front==-1 && rear==-1)
            System.out.println("Empty Queue");
        else
        {
            int i=front;
            while (i != rear)
            {
                System.out.println(Q[i]);
                i=(i+1)%max;
            }
            System.out.println(Q[rear]);
        }
    }
    void push()
    {
        if ((rear+1)%max==front)
            System.out.println("Overflow!!!");
        else
        {
            int item;
            item=Sc.nextInt();
            if (front==-1)
                front++;
            rear=(rear+1)%max;
            Q[rear]=item;
        }
    }
    void pop()
    {
        if (front==-1)
            System.out.println("Underflow!!!");
        else
        {
            System.out.println(Q[front]);
            if (front==rear)
            {
                front=-1;
                rear=-1;
            }
            else
                front = (front+1)%max;
        }
    }
}
class Queues_using_arrays
{
    int max=5, front=-1, rear=-1;
    int[] Q;
    Scanner Sc;
    public Queues_using_arrays()
    {
        Q = new int[max];
        Sc = new Scanner(System.in);
    }
    void show()
    {   if (front==-1 && rear==-1)
            System.out.println("Empty Queue");
        else
        {
            for (int i=front; i<=rear; i++)
                System.out.println(Q[i]);
        }
    }
    void push()
    {
        if (rear==max-1)
            System.out.println("Overflow!!!");
        else
        {
            int item;
            System.out.println("Enter Item to push");
            item = Sc.nextInt();
            if (front==-1)
                front++;
            rear++;
            Q[rear]=item;
        }
    }
    void pop()
    {
        if (front==-1)
            System.out.println("Underflow!!!!");
        else
        {
            System.out.println(Q[front]);
            front++;
            if (front>rear)
            {
                front=-1;
                rear=-1;
            }
        }
    }
}


public class main
{
    public static void main(String[] args)
    {
        Scanner sc2;
        sc2 = new Scanner(System.in);
        Queues_using_arrays Que = new Queues_using_arrays();
        Circular_Queues CQ = new Circular_Queues();
        int choice;
        do
        {
            System.out.println("Enter choice \n1.Show\n2.push\n3.pop\n4.exit");
            choice = sc2.nextInt();
            switch (choice)
            {
                case 1:
                    CQ.show();
                    break;
                case 2:
                    CQ.push();
                    break;
                case 3:
                    CQ.pop();
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
