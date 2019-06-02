#include<bits/stdc++.h>
using namespace std;

vector< vector <int> > pascal(int n)
{
	vector<vector<int> > arr;
	vector<int> s;
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			s.push_back(0);
			arr.push_back(s);
		}
	}
return arr;
}

int main()
{
	int t = 5;
	vector<vector<int> > arr = pascal(t);
	for(int i=0; i<arr.size(); i++)
	{
		for(int j=0; j<arr[i].size(); j++)
		{
			cout << arr[i][j];
		}
		cout << endl;
	}
}
