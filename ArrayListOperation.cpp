#include<bits/stdc++.h>
using namespace std;

void insert(vector<char> &array, char element)
{
	array.push_back(element);
}

int freq(vector<char> &array, char element)
{
	int count = 0;
	for(int i = 0; i<array.size(); i++)
	{
		if(array[i] == element)
		{
			count++;
		}
		
	}
return count;
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int q;
		cin >> q;
		char arr[2*q];
		vector<char> array;
		int frequency;

		for(int i=0; i< 2*q; i++)
		{
			cin >> arr[i];
		}

		for(int i = 0; i < 2*q; i+=2)
		{
			if(arr[i] == 'i')
				insert(array, arr[i+1]);
			else if(arr[i] == 'f')
				frequency = freq(array, arr[i+1]);
		}

		if(frequency == 0)
			cout << "Not Present";
		else
			cout << frequency;
	cout << endl;
	}
return 0;
}