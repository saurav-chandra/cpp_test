/*
1. Write a find() function using STL in C++ that finds the first match for a
simple regular expression in a string. Use ? to mean ‘‘any character,’’ ∗to mean
any number of characters not matching the next part of the regular
expression, and [abc] to mean any character from the set specified between the
square braces (here a , b , and c ). Other characters match themselves. For
exam-ple, find(s,"name:") returns a pointer to the first occurrence of name: in s ;
find(s,"[nN]ame:") returns a pointer to the first occurrence of name: or Name: in s ;
and find(s,"[nN]ame( ∗ )") returns a pointer to the first occurence of Name or name
followed by a (possibly empty) parenthesized sequence of characters in s.
*/

#include<bits/stdc++.h>
using namespace std;

int find(string str,string exp)
{
	int i;
	if(exp[0]!='[')
	{
		i=str.find(exp.substr(0));
	}
	else if(exp[0]=='[')
	{
		int j=1;
		int k=exp.find("]")+1;
		string str1=exp.substr(k);
		while(exp[j]!=']')
		{
			char x[2];
			x[0]=(char)exp[j];
			x[1]='\0';
			string str2=string(x);
			str2=str2+str1;
			i=str.find(str2);
			if(i!=string::npos)
			{
				cout<<"Found "<<str2<<" regular expression first in the given string\n";
				break;
			}
			j++;
		}
	}
	return i;
}

int main()
{
	string str,exp;
	cout<<"Enter a string\n";
	getline(cin,str);
	cout<<"Enter a Regular expression\n";
	cin>>exp;
	int position=find(str,exp);
	if(position!=string::npos)
	{
		cout<<"Position of first occurrence of regular expression in string is at "<<position<<"\n";
	}
	else
		cout<<"Given regular expression does not exits in the string\n";
return 0;
}