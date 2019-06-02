#include<iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, count = 0;
        cin >> n;
        while(n > 0)
        {
            if(n%2 != 0)
            {
                count++;
                n /= 2;
            }
            else
                n/= 2;
        }
        cout << count;
    }
	return 0;
}