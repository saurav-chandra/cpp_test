#include<bits/stdc++.h>
using namespace std;

void insertion(int arr[], int n)
{
	int i, j, temp;
	for(i = 0; i<n; i++)
	{
		
		if(arr[a] > arr[b])
		{
			for(int j=b-1; j>=0; j--)
			{
				if(arr[j] < arr[b])
				{
					int temp = arr[j+1];
					arr[j+1] = arr[b];
					arr[b] = temp;
				}
			}
		}
		a++;
		b++;
	}

	for(int i=0; i<n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main()
{
	int n;
	cin >> n;
	int a[n];
	for(int i=0; i<n; i++)
	{
		cin >> a[i];
	}
	insertion(a,n);
return 0;
}
