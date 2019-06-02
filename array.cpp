#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,i;
	cin >> n;
	int arr[n];
	int mul = 1;
	for(i=0; i<n; i++)
	{
		cin >> arr[i];
		mul *= arr[i];
	}
	for(i=0; i<n; i++)
	{
		cout << mul/arr[i] << " ";
	}
}
