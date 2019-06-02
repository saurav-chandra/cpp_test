/*
7. Write a small program that removes adjacent repeated words from a file.
Eg -> Statement: Write a small program that that removes adjacent repeated
words from from a file file.
The program should remove a that,
a from, and a file from the previous
statement.
*/

#include<bits/stdc++.h>
using namespace std;

string str[1000];
int count1=0;
std::list <string> a;

void remove1 (std::list<string> x)
{
	int i=0;
	std::list<string>::iterator it=x.begin();
	while(it!=x.end())
	{
		it = std::adjacent_find (it++, x.end());
		if (it!=x.end())
			x.erase(it++);
	}
	for(it=x.begin();it!=x.end();it++)
	{
		str[i]=*it;
		i++;
		count1++;
	}
}

int main()
{
	int i;
	ifstream ifile;
		ifile.open("7input.txt");
		cout << "Taking input from '7input.txt'\nGenerating output to '7output.txt'\n";
		for(i=0;!ifile.eof();i++)
		{
			ifile>>str[i];
			a.push_back(str[i]);
		}
		ifile.close();
	remove1(a);
	ofstream outfile;
	outfile.open("7output.txt");
	for(i=0;i<count1;i++)
		outfile<<str[i]<<" ";
	outfile.close();
	return 0;
}
