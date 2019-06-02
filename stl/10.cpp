/*
10. Write a program in C++ which reads a sequence of lines of text from a file
into a fixed-sized character buffer. Remove all whitespace characters and
replace each alphanumeric character with the next character in the alphabet
(replace z by a and 9 by 0 ). Write out the resulting line.
*/

#include<bits/stdc++.h>
using namespace std;

char line[1000], newline[1000];
int count1=0;

int main()
{
	int i, j=0, k=0, n=0, ch;
	char c;
	ifstream ifile;
	ifile.open("10input.txt");
	for(i=0; ifile>>noskipws; i++)
	{
		ifile>>line[i];
		n++;
	}
	ifile.close();
	for(i=0; i<n; i++)
	{
		if(line[i] == ' ')
			continue;
		else
		{
			c=line[i];
			if(c=='z')
			newline[k]='a';
			else if(c=='9')
			newline[k]='0';
			else
			newline[k]=c+1;
			k++;
		}
	}
	ofstream outfile;
	outfile.open("10output.txt");
	for(j=0;j<i-1;j++)
		outfile<<newline[j];
	outfile.close();
return 0;
}
