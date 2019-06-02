#include<bits/stdc++.h>
using namespace std;

void display(stack<int> stk)
{
	cout << "Stack items : ";
	while(!stk.empty())
	{
		cout<<stk.top() << " ";
		stk.pop();
	}
}

int main()
{
	stack<int> stk;
	int x, n;
	cout << "Enter the numbers of items to insert in stack : ";
	cin>>n;
	for(int i = 0; i < n; i++)
	{
		cin >> x;
		stk.push(x);
	}
	stk.pop();
	cout << "Removing stack top : " << stk.top();
	cout << endl;
	display(stk);
}
