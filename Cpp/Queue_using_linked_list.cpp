#include <iostream>

using namespace std;

class Node
{
	public:
		int info;
		Node *link;
};

class Linked_List
{
	private:
		Node *first, *ptr, *newNode, *save;
	public:
		void create()
		{
			int n, count=1;
			cout << "Enter N  ";
			cin >> n;
			
			ptr = new Node;
			cout << "Enter info for " << 1 << " node ";
			cin >> ptr->info;
			
			ptr->link = NULL;
			first = ptr;
			
			while (count <= n-1)
			{
				newNode = new Node;
				cout << "Enter info for " << count+1 << " node ";
				cin >> newNode->info;
				
				newNode->link = NULL;
				ptr->link = newNode;
				
				ptr = newNode;
				count ++;		
			}
		}
		void traverse()
		{
			ptr = first;
			while (ptr != NULL)
			{
				cout << ptr->info << endl;
				ptr = ptr->link;
			}
		}
		void push()
		{
			newNode = new Node;
			cout << "Enter Info of New Node  ";
			cin >> newNode->info;
			
			ptr = first;
			while(ptr->link != NULL)
			{
				ptr = ptr->link;
			}
			newNode->link = NULL;
			ptr->link = newNode;
		}
		void pop()
		{
			ptr = first;
			first = ptr->link;
			delete ptr;
		}
};

int main()
{
	int choice;
	Linked_List l;
    do 
	{
		cout << "Enter your Choice\n1.Create Queue\n2.Traverse\n3.Push\n4.Pop\n5.Exit\n";
		cin >> choice;

        switch (choice) 
		{
            case 1:
                l.create();
                break;
            case 2:
                l.traverse();
                break;
            case 3:
            	l.push();
            	break;
            case 4:
            	l.pop();
            	break;
            case 5:
            	exit(0);
            	break;
            default:
            	cout << "Wrong Choice Nigga!!";
    	}
	}while (choice != 5);
	
	return 0;
}
