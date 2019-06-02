/*
18. Write a C++ program f or implementing Knuth-Morris- Pratt pattern matching algorithm.
*/

#include<bits/stdc++.h>
using namespace std;

void prefix(string pattern, int find[])
{
    int n = pattern.length(), x;
    find[0] = -1;
    for (int i = 1; i < n; i++)
    {
        x = find[i - 1];
        while (x >= 0)
        {
            if (pattern[x] == pattern[i - 1])
                break;
            else
                x = find[x];
        }
        find[i] = x + 1;
    }
}

int KMP(string pattern, string target)
{
    int m = pattern.length();
    int n = target.length();
    int find[m];     
    prefix(pattern, find);     
    int i = 0;
    int k = 0;        
    while (i < n)
    {
        if (k == -1)
        {
            i++;
            k = 0;
        }
        else if (target[i] == pattern[k])
        {
            i++;
            k++;
            if (k == m)
                return 1;
        }
        else
            k = find[k];
    }
    return 0;
}
 
int main()
{
    string pattern, target;
    cout << "Enter any sentence : ";
    getline(cin, target);
    cout << "Enter word to find in the above sentence : ";
    getline(cin, pattern);
    
    if(KMP(pattern, target))
        cout<<"'"<<pattern<<"' found in string '"<<target<<"'"<<endl;
    else
        cout<<"'"<<pattern<<"' not found in string '"<<target<<"'"<<endl;
    return 0;
}