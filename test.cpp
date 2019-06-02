#include<bits/stdc++.h>
using namespace std;

int setDiff(int m, int n)
{
    int diff = 0;
    string binary1 = bitset<4>(m).to_string();
    string binary2 = bitset<4>(n).to_string();
    for(int i = 0; i<4; i++)
    {
        if(binary1[i] != binary2[i])
            diff++;
    }
return diff;
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
        int sum = 0;
        for(int i=0; i<n; i++)
        {
            cin >> arr[i];
        }
        for(int i=0; i<n-1; i++)
        {
            int temp;
            for(int j=i+1; j<n; j++)
            {
                temp = setDiff(arr[i],arr[j]);
                sum += temp;
            }
        }
        cout << sum*2 << endl;
    }
return 0;
}
