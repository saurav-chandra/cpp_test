#include<iostream>
using namespace std;

int main()
{
    int i, j, k, n;
    cin >> n;
    for(i = 1; i <= 2*n; i++)
    {
        for(j = 0; j <= 2*n; j++)
        {
            if(i <= n)
                if(j >= n+1-i && j <= n-1+i)
                {
                    cout << " ";
                }
                else
                {
                    cout << "#";
                }
            else
                if(j <= n+1-i && j >= n-1+i)
                {
                    cout << "#";
                }
                else
                {
                    cout << "*";
                }
        }
        cout << "\n";
    }
}