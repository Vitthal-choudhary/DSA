#include <iostream>
#include <process.h>
#define max 5

using namespace std;

class Stack_using_arrays
{
	int Stack[max], top;
	public:
		Stack_using_arrays()
		{
			top = -1;
		}
		void show()
		{
			int i;
			for (i=top; i>=0; i--)
			{
				cout << Stack[i] << endl;
			}
		}
		
		void push()
		{
			if (top==max-1)
			{
				cout << "Overflow !!!  Can't Push to The Stack" << endl;
			}
			else
			{
				int item;
				cout << "enter item to push  ";
				cin >> item;
				top++;
				Stack[top] = item;
			}
		}
		
		void pop()
		{
			if (top==-1)
			{
				cout << "Under Flow !!!!!!!  Can't Pop from empty Stack" << endl;
			}
			else
			{
				cout << "Item Popped is " << Stack[top] <<  endl;
				top--;
			}
		}
};

int main()
{
	int choice;
	Stack_using_arrays St;
	do
	{
		cout << "Enter your choice" << endl << "1.Show the Stack" << endl << "2.Push" << endl << "3.Pop" << endl << "4.Exit" << endl;
		cin >> choice;
		
		switch(choice)
		{
			case 1:
				St.show();
				break;
			case 2:
				St.push();
				break;
			case 3:
				St.pop();
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


