/*
6. Define a queue using (only) two stacks.
*/

#include<bits/stdc++.h>
using namespace std;

stack<int> stk1;
stack<int> stk2;
	
void dequeue()
{
	if(stk2.empty())
	{
		while(!stk1.empty())
		{
			stk2.push(stk1.top());
			stk1.pop();
		}
	}
	cout << "Deleted element : " << stk2.top() << endl;
	stk2.pop();
}

int main()
{

	int choice,x;
	cout << "~~>>Queue using two stacks<<~~";
	while(1)
	{
		cout << "\n\t1. enqueu\n\t2. dequeue\n\t3. exit\nEnter your choice : ";
		cin >> choice;
		switch(choice)
		{
			case 1:
				cout << "Enter element to insert : ";
				cin >> x;
				stk1.push(x);
				//enqueue(x);
				break;
			case 2:
				dequeue();
				break;
			case 3:
				cout << "\nExiting...";
				return 0;
			default:
				cout << "Wrong input, enter again";
		}
	}
}
