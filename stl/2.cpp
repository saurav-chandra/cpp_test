/*
2. Write a program in C++ to create lists of students taking Math, English,
French, and Biology. Pick about 20 names for each class out of a set of 40
names. The program lists students who take both Math and English. It also
Lists students who take French but not Biology or Math. It also lists students
who do not take a science course. Finally, it lists students who take French
and Math but neither English nor Biology.
*/

#include<bits/stdc++.h>
using namespace std;

vector<string> maths, english, french, biology;
vector<string> v1,v2,v3,v4,v5,v6,v7,temp1,temp;
set<string> s1,  s2, s3, s4;
string x;

int main()
{
	int i,j;
	ifstream ifile;
	string str;
	ifile.open("2names.txt");
	for(i=0;i<20;i++)
	{
		ifile>>str;
		maths.push_back(str);
	}
	for(i=0;i<20;i++)
	{
		ifile>>str;
		english.push_back(str);
	}
	for(i=0;i<20;i++)
	{
		ifile>>str;
		french.push_back(str);
	}
	for(i=0;i<20;i++)
	{
		ifile>>str;
		biology.push_back(str);
	}

	//check maths & english
	for(i=0;i<20;i++)
	{
		for(j=0;j<20;j++)
		{
			if(maths[i]==english[j])
			{
				str=maths[i];
				v1.push_back(maths[i]);
			}
		}
	}
	cout<<"Students enrolled in Maths & English:\n";
	for(i=0;i<v1.size();i++)
	{
		cout<<v1[i]<<"\t";
	}
	//check french but not bio or math
	cout<<"\nStudents enrolled in French but not in Biology or Maths:\n";
	set_difference(
		french.begin(), french.end(),
		maths.begin(), maths.end(),back_inserter( temp ));
	set_difference(
		temp.begin(), temp.end(),
		biology.begin(), biology.end(),back_inserter( v2 )
	);

	for(i=0;i<v2.size();i++)
	{
		cout<<v2[i]<<"\t";
	}

	//check for no science course
	v3=french;
	v3.insert( v3.end(), english.begin(), english.end() );
	v3.insert( v3.end(), biology.begin(), biology.end() );
	set_difference(
		v3.begin(), v3.end(),
		maths.begin(), maths.end(),back_inserter( temp )
	);
	cout<<"\nStudents not enrolled in Science are:\n";
	for(i=0;i<temp.size();i++)
	{
		x=temp[i];
		s1.insert(x);
	}
	set<string> ::iterator itr;
	for(itr=s1.begin();itr!=s1.end();itr++)
	{
		cout<<*itr<<"\t";
	}

	// code for last part of the question 
	v4=french;
	v4.insert( v4.end(), maths.begin(), maths.end() );
	for(i=0;i<v4.size();i++)
	{
		x=v4[i];
		s2.insert(x);
	}
	v5=english;
	v5.insert( v5.end(), biology.begin(), biology.end() );
	for(i=0;i<v5.size();i++)
	{
		x=v5[i];
		s3.insert(x);
	}
	set <string> :: iterator it1;
		
		for (it1=s2.begin(); it1!=s2.end(); it1++)
		{
			x=*it1;
			v6.push_back(x);
		}
	set <string > :: iterator i2;
		
		for (i2=s3.begin(); i2!=s3.end(); ++i2)
		{
			x=*i2;
			v7.push_back(x);
		}
	set_difference(
		v6.begin(),v6.end(),
		v7.begin(), v7.end(),back_inserter( temp1 )
	);

	cout<<"\nStudents enrolled in French & Maths but not in English or Biology are:\n";

	for(i=0;i<temp1.size();i++)
	{
		cout<<temp1[i]<<"\t";
	}
	return 0;
}