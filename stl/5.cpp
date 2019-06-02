/*
5. Write a program that lists the distinct words in a file in alphabetical order.
Make two versions: one in which a word is simply a whitespace-separated
sequence of characters and one in which a word is a sequence of letters
separated by any sequence of non-letters
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
	string temp;
	vector<string> str;
	int i,j;
	int count=0;
	ifstream sifile;
	sifile.open("5input.txt");
	for(i=0; !sifile.eof();i++)
	{
		sifile>>temp;
		str.push_back(temp);
		count++;
	}
	for(i=0;i<count;i++)
		for(j=i+1;j<count;j++)
		{
			if(str[i]>str[j])
			{
				temp=str[i];
				str[i]=str[j];
				str[j]=temp;
			}
		}
	ofstream sofile;
	sofile.open("5output.txt");
	for(i=0;i<count;i++)
	{
		sofile<<str[i]<<" ";
	}
		sofile.close();
}