#include <iostream>
#include <process.h>
#define max 5

using namespace std;

class Queue_using_arrays
{
	int Q[max], front, rear;
	public:
		Queue_using_arrays()
		{
			front = -1;
			rear = -1;
		}
		void show()
		{
			int i;
			for (i=front; i<=rear; i++)
			{
				cout << Q[i] << endl;
			}
		}
		void push()
		{
			if (rear==max-1)
				cout << "Overflow!!!!!!";
			else
			{
				int item;
				cout << "Enter item  ";
				cin >> item;
				rear++;
				if (front==-1)
					front++;
				Q[rear]=item;
			}
		}
		void pop()
		{
			if (front==-1)
				cout << "Underflow!!!!!";
			else
			{
				cout << Q[front];
				front++;
				if (front>rear)
				{
					front = -1;
					rear = -1;
				}
			}
		}
};

int main()
{
	int choice;
	Queue_using_arrays Que;
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
