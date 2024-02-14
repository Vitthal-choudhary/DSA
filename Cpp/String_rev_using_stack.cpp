// 1st application of stack -----> Reversing a string

#include<iostream>
#include<string.h>
#define max 20

using namespace std;

class Str_Stak
{
	private:
		char S[max];
	public:
		int top;
		Str_Stak()
		{
			top=-1;
		}
		
		void push(char c)
		{
			top++;
			S[top] = c;
		}
		
		char pop()
		{
			return S[top--];
		}
		bool is_empty()
		{
			return top==-1;
		}
};


int main()
{	
	Str_Stak st;
	
	char a[20];
	cout << "Enter the string ";
	cin.getline(a, 20);
	
	int i=0;
	
	while (a[i]!='\0')
	{
		st.push(a[i]);
		i++;
	}
	
	while (!st.is_empty())
	{
		cout << st.pop();
	}
	
	return 0;
}
