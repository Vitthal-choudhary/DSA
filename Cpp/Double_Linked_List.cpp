#include <iostream>

using namespace std;

class Node
{
	public:
		int info;
		Node *rlink, *llink;
};

class Double_Linked_list
{
	private:	
		Node *ptr, *rfirst, *lfirst, *newNode, *save;
	public:
		void create()
		{
			int N, count=1;
			cout << "enter N  ";
			cin >> N;
			
			ptr = new Node;
			cout << "Enter info for " << 1 << " node ";
			cin >> ptr->info;
			
			ptr->rlink = NULL;
			ptr->llink = NULL;
			
			lfirst = ptr;
			rfirst = ptr;
			
			while(count<=N-1)
			{
				newNode = new Node;
				cout << "Enter info for " << count+1 << " node ";
				cin >> newNode->info;
				
				newNode->llink = ptr;
				newNode->rlink = NULL;
				
				ptr->rlink = newNode;
				
				rfirst = newNode;
				
				ptr = newNode;
				count++;
			}	
			
		}
		
		void Rtraverse()	// Right to left
		{
			ptr = rfirst;
			while(ptr != NULL)
			{
				cout << ptr->info << endl;
				ptr = ptr->llink;
			}
		}
		
		void Ltraverse()		// Left to Right
		{
			ptr = lfirst;
			while(ptr != NULL)
			{
				cout << ptr->info << endl;
				ptr = ptr->rlink;
			}	
		}
		
		void Insert_at_Left()
		{
			newNode = new Node;
			cout << "Enter info for new node ";
			cin >> newNode->info;
			
			newNode->llink = NULL;
			newNode->rlink = lfirst;
			
			lfirst->llink = newNode;
			lfirst = newNode;
		}
		
		void Insert_at_Right()
		{
			newNode = new Node;
			cout << "Enter info for new node ";
			cin >> newNode->info;
			
			newNode->rlink = NULL;
			newNode->llink = rfirst;
			
			rfirst->rlink = newNode;
			rfirst = newNode;
		}
		
		void Insert_after_a_node()
		{	
			// i will traverse from left to right in this example
			int item;
			cout << "Enter the Item after which u want to insert new element ";
			cin >> item;
			
			ptr = lfirst;
				
			while(ptr->rlink != NULL)
			{
				if (ptr->info == item)
				{
					newNode = new Node;
					cout << "Enter info for new node ";
					cin >> newNode->info;
					
					newNode->rlink = ptr->rlink;
					ptr->rlink->llink = newNode;
					ptr->rlink = newNode;
					newNode->llink = ptr;
					break;
				}
				ptr = ptr->rlink;
			}
			
			if (ptr->rlink == NULL)
			{
				cout << "Not Found" << endl;
			}	
		}
		
		void Delete_at_Left()
		{
			ptr = lfirst;
			lfirst = ptr->rlink;
			lfirst->llink = NULL;
			delete ptr;
		}
		
		void Delete_at_Right()
		{
			ptr = rfirst;
			rfirst = ptr->llink;
			rfirst->rlink = NULL;
			delete ptr;
		}	
		void Delete_after_a_Node()
		{
			// Using left to right approach
			int item;
			cout << "Enter the Item after which u want to delete item ";
			cin >> item;
			
			ptr = lfirst;
			
			while(ptr->rlink->rlink != NULL)
			{
				if (ptr->rlink->info == item)
				{
					save = ptr->rlink;
					ptr->rlink = save->rlink;
					save->rlink->llink = ptr;
					delete save;
					break;
				}
				ptr = ptr->rlink;
			}
			if (ptr->rlink->rlink == NULL)
			{
				cout << "Not Found" << endl;
			}
		}
};


int main()
{
	Double_Linked_list l;
	int choice;
    do {
        cout << "Enter your Choice\n1.Create linked list\n2.Traverse from Right\n3.Traverse from left\n4.Insert at Left\n5.Insert at Right\n6.Insert after a given Node\n7.Delete at Left\n8.Delete at Right\n9.Delete after a node\n10.Exit\n";
		cin >> choice;

        switch (choice) {
            case 1:
                l.create();
                break;
            case 2:
                l.Rtraverse();
                break;
            case 3:
                l.Ltraverse();
                break;
            case 4:
				l.Insert_at_Left();
                break;
            case 5:
                l.Insert_at_Right();
                break;
            case 6:
                l.Insert_after_a_node();
                break;
            case 7:
                l.Delete_at_Left();
                break;
            case 8:
                l.Delete_at_Right();
                break;
            case 9:
            	l.Delete_after_a_Node();
            	break;
            case 10:
                exit(0);
            default:
                cout << "Wrong Choice\n";
        }
    } while (choice != 10);
	return 0;
}
