#include<bits/stdc++.h>
using namespace std;  
int main()
{  
    int n, number;   
    cin >> n;  
    string name1, name2;  
    map<string, int> list;  
    for(int i=0;i<n;i++)
    {  
         cin>>name1;  
         cin>>number;  
         cin.ignore();
         list[name1]=number;  
    }  
    while(getline(cin,name2))
    {  
         if(list.find(name2) !=list.end()) 
           cout<< name2 << "=" <<list[name2]<<endl;    
         else   
           cout<<"Not found"<<endl;  
    }  
    return 0;  
}