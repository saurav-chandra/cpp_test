#include<bits/stdc++.h>
using namespace std;

int isPrime(int x, int n)
{
    int isPrime;
    for(int i=2; i<=n;i++)
    {
        if(n%i == 0)
        {
            isPrime = 1;
            for(int j=2; j <= i/2; j++)
            {
                if(i%2 == 0)
                {
                    isPrime = 0;
                    break;
                }
            }
/*
            if(isPrime == 1)
            {
                return isPrime
            }*/
        }
    }
return isPrime;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int arr[n];
        arr[0] = 1;
        int k=2;
        int count = 1;
        while(count != n)
        {
            int z = isPrime(k,n);
            if(z == 1)
            {
                if(k%2==0 || k%3==0 || k%5==0)
                {
                    arr[count] = k;
                    count++;
                }
            }
            k++;
        }
		for(int i=0; i<n; i++)
		{
			cout << i+1 << " : " << arr[i] << endl;
		}
        cout << arr[n-1] << endl;
    }
}