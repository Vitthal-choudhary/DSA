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
		void insert_at_begin()
		{
			newNode = new Node;
			cout << "Enter Info of New Node  ";
			cin >> newNode->info;
			
			newNode->link = first;
			first = newNode;
		}
		void insert_at_end()
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
		void insert_in_mid()
		{
			int item;
			cout << "Enter the Item after which u want to insert new element ";
			cin >> item;
			
			ptr = first;
			while(ptr->link != NULL)
			{
				if (ptr->info == item)
				{
					newNode = new Node;
					cout << "Enter info Of New Node  ";
					cin >> newNode->info;
					
					newNode->link = ptr->link;
					ptr->link = newNode;
					break;
				}
				ptr = ptr->link;
			}
			
			if (ptr->link == NULL)
			{
				cout << "Not Found" << endl;
			}
		}
		void del_at_begin()
		{
			ptr = first;
			first = ptr->link;
			delete ptr;
		}
		
		void del_at_end()
		{
			ptr = first;
			while (ptr->link->link != NULL)
			{
				ptr = ptr->link;	
			}
			save = ptr->link;
			ptr->link = NULL;
			delete save;	
		}
		void del_in_mid()
		{
			int item;
			cout << "Enter the Item after which u want to delete item ";
			cin >> item;
			
			ptr = first;
			while(ptr->link->link != NULL)
			{
				if (ptr->link->info == item)
				{
					save = ptr->link;
					ptr->link = save->link;
					delete save;
					break;
				}
				ptr = ptr->link;
			}
			if (ptr->link->link == NULL)
			{
				printf("Not Found");
			}	
		}
};

int main()
{
	Linked_List l;
	int choice;
    do {
        cout << "Enter your Choice\n1.Create linked list\n2.Traverse\n3.Insert at begin\n4.Insert at end\n5.Insert in mid\n6.Delete at Begin\n7.Delete at end\n8.Delete in middle\n9.Exit\n";
        cin >> choice;

        switch (choice) {
            case 1:
                l.create();
                break;
            case 2:
                l.traverse();
                break;
            case 3:
                l.insert_at_begin();
                break;
            case 4:
				l.insert_at_end();
                break;
            case 5:
                l.insert_in_mid();
                break;
            case 6:
                l.del_at_begin();
                break;
            case 7:
                l.del_at_end();
                break;
            case 8:
                l.del_in_mid();
                break;
            case 9:
                exit(0);
            default:
                cout << "Wrong Choice\n";
        }
    } while (choice != 9);
	return 0;
}
