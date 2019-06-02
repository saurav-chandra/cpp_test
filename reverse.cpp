#include<bits/stdc++.h>
using namespace std;

int main()
{
    string arr;
    string arr2;
    int  f=0;
    int i=0;
    cout << "enter a string : ";
    getline(cin,arr);
    cout << "entered string is : " ;
    for(int i = 0; i < arr.length() ; i++)
    cout << arr[i];
    cout << "\nreverse of the string : ";
    for(int i = arr.length()-1 ; i >=0 ; i--)
    cout << arr[i];
    cout << "\nreverse of the words : ";
    int s = arr.length();
    while(i < s)
    {
        if(f)
        cout << arr[i];
        
        else
        if(arr[i] == ' ')
        f++;
        else
        arr2 = arr2+arr[i];
        
        i++;
    }
    cout << " " << arr2;
}
