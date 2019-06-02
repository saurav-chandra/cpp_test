#include<bits/stdc++.h>
using namespace std;

int main()
{
    map<string, string> phone;
    int i, n;
    string name, num;
    //cout << "enter no. of test cases : ";
    cin >> n; 
    for(i = 0; i < n; i++)
    {
        //cout << "Please enter name and number : ";
        cin >> name;
        cin >> setw(8) >> num;
        phone.insert(pair<string, string> (name, num));
    }
    for(i = 0; i < 3; i++)
    {
        //cout << "enter name to find : ";
        cin >> name;
        bool result = false;
        map<string, string>::iterator itr, itr2;
        for(itr = phone.begin(); itr != phone.end(); ++itr)
        {
            cout << name << endl;
            if(name == itr -> first)
            {
                //bool result = true;
                //itr2 = itr;
                //cout << "name and number : ";
                cout << itr -> first << "=" << itr -> second << endl;
            }
            else
                cout << "Not found" << endl;
        /*
            if(result == true)
                cout << itr2 -> first << "=" << itr2 -> second << endl;
            else
                cout << "Not found" << endl;
                */

        cout << endl;
        }
        
       // }
    }
    return 0;
}