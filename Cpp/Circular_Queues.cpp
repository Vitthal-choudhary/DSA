#include <iostream>
#include <process.h>
#define max 5

using namespace std;

class Circular_Queue
{
	int Q[max], front, rear;
	public:
		Circular_Queue()
		{
			front=-1;
			rear=-1;
		}
		void show()
		{
			int i=front;
			while (i != rear)
			{
				cout << Q[i] << endl;
				i=(i+1)%max;	
			}
			cout << Q[rear] << endl;	
		}
		void push()
		{
			int item;
			if ((rear+1)%max == front )
				cout << "Overflow";
			else
			{
				cout << "Enter item   ";
				cin >> item;
				if (front==-1)
					front++;
				rear = (rear+1)%max;
				Q[rear]=item;
			}
		}
		void pop()
		{
			if (front == -1)
				cout << "Underflow!!";
			else
			{
				cout << Q[front];
				if (front==rear)
				{
					front=-1;
					rear=-1;
				}
				else
					front = (front+1)%max;
			}
		}
};


int main()
{
	int choice;
	Circular_Queue Que;
	do
	{
		cout << "Enter your choice" << endl << "1.Show " << endl << "2.Push" << endl << "3.Pop" << endl << "4.Exit" << endl;
		cin >> choice;
		
		switch(choice)
		{
			case 1:
				Que.show();
				break;
			case 2:
				Que.push();
				break;
			case 3:
				Que.pop();
				break;
			case 4:
				exit(0);
				break;
			default:
				cout << "Wrong Choice Nigga!";
		}
	}while (choice != 4);
	
	return 0;
}
