#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t; 
    while(t--)
    {
        int n;
        cin >> n;
        int arr[n];
        int sum = 0;
        for(int i=1;i<=n;i++)
        {
            cin >> arr[i];
            sum += arr[i];
        }
        cout << "sum: " << sum << endl;
        int j;
        int repeated;
        for(int i=1; i<=n; i++)
        {
            j = arr[i];
            if(arr[j] < 0)
            {
                repeated = arr[j];
                break;
            }
            else
                arr[j] = -arr[j];
        }
        int total = (n*(n+1))/2;
        cout << "total: " << total << endl;
        repeated = abs(repeated);
        cout << "repeated: " << repeated << endl;
        int temp = sum - repeated;
        int left = total - temp;
        cout << "left: " << left << endl;
        cout << repeated << " " << left << endl << endl;
    }
}
