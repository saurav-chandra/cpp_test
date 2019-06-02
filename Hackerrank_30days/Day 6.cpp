#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,t,j;
    string temp;
    string str;
    cin >> t;
    for(j=0; j<t ; j++)
    {
        cin >> str;
        n = str.length();
        for(i=0;i<n;i++)
        {
            if(i%2==0)
                cout << str[i];
        }
        cout <<" ";
        for(i=0;i<n;i++)
        {
            if(i%2!=0)
                cout << str[i];
        }
        cout << endl;
    }
}