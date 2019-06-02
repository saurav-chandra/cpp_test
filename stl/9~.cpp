/*
9. Write a program in C++ which reads a sequence of (name, value) pairs as
command line argument and prints a sorted list according to the name in
descending order. The names may be duplicated in the command line
arguments. The program also prints a sorted list (name, total, mean,median,
variance).
*/

#include<bits/stdc++.h>
using namespace std;

int main(int argc,char *argv[])
{
	int i,var,t,j;
	string temp;
	vector<string> str;
	vector<int> arr;
	for(i=1;i<argc;i++)
	{
		if(i%2==0)
		{
			var=int(argv[i]);
			arr.push_back(var);
		}
		else
		str.push_back(argv[i]);
	}
	for(i=0;i<argc;i++)
	{
      for(j=i+1;j<argc;j++)
		{
           if(str[i]<str[j])
			{
				temp=str[i];
				str[i]=str[j];
				str[j]=temp;
				t=arr[i];
				arr[i]=arr[j];
				arr[j]=t;
           	}
    	}
	}
	for(i=1;i<argc;i++)
		cout<<str[i]<<"\t"<<arr[i]<<"\n";
return 0;
}