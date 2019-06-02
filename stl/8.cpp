/*
8. Define a format for records of references to papers and books kept in a file.
Write a program that can write out records from the file identified by year of
publication, name of author, keyword in title, or name of publisher. The user
should be able to request that the output be sorted according to similar
criteria.
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
	ifstream ifs;
	string year[50],name[50],title[50],publisher[50];
	vector<string> record[50];
	string str,item,y;
	char ch,ch1;
	int i,s=0,j,c,c1;
	ifs.open("8input.txt");
	while(getline(ifs,str))
	{
		stringstream ss(str);
		while(ss>>item)
			record[s].push_back(item);
		s++;
	}
	for(j=0;j<s;j++)
	{
		year[j]=record[j].at(0);
		name[j]=record[j].at(0);
		title[j]=record[j].at(0);
		publisher[j]=record[j].at(0);
	}
	do
	{
		cout<<"What service you want?\n";
		cout<<"1. Print the records\n";
		cout<<"2. Sort the Records\n";
		cin>>c1;
	switch(c1)
	{
	case 1: cout<<"Enter the criteria for printing the records:\n";
		do
		{
		cout<<"1. By Year\n";
		cout<<"2. By Author Name\n";
		cout<<"3. By Title\n";
		cout<<"4. By Publisher\n";
		cout<<"5. Exit\n";
		cin>>c;
		switch(c)
		{
		case 1: cout<<"Enter the year";
			cin>>y;
			for(i=0;i<s;i++)
			{
				if(y==record[i].at(0))
					for(j=0;j<record[i].size();j++)
						cout<<record[i].at(j)<<"\t";
			}
			cout<<"\n";
			break;
		case 2: cout<<"Enter the name of author";
			cin>>y;
			for(i=0;i<s;i++)
			{
				if(y==record[i].at(1))
					for(j=0;j<record[i].size();j++)
						cout<<record[i].at(j)<<"\t";
			}
			cout<<"\n";
			break;
		case 3: cout<<"Enter the title keyword";
			cin>>y;
			for(i=0;i<s;i++)
			{
				if(y==record[i].at(2))
					for(j=0;j<record[i].size();j++)
						cout<<record[i].at(j)<<"\t";
			}
			cout<<"\n";
			break;
		case 4: cout<<"Enter the name of publisher";
			cin>>y;
			for(i=0;i<s;i++)
			{
				if(y==record[i].at(3))
					for(j=0;j<record[i].size();j++)
						cout<<record[i].at(j)<<"\t";
			}
			cout<<"\n";
			break;
		case 5: return 0;
		}
		cout<<"Print more records?(y/n)";
		cin>>ch;
		}while(ch=='y'||ch=='Y');
		break;
	case 2: cout<<"Enter the criteria for sorting the records: \n";
		do
		{
		cout<<"1. By Year\n";
		cout<<"2. By Author Name\n";
		cout<<"3. By Title\n";
		cout<<"4. By Publisher\n";
		cout<<"5. Exit\n";
		cin>>c;
		switch(c)
		{
		case 1: for(i=1;i<s-1;i++)
			{
				for(j=1;j<s-i-1;j++)
				{
					if(record[j].at(0)>record[j+1].at(0))
						swap(record[j],record[j+1]);
				}
			}
			cout<<"Sorted records by year of publication:\n";
			for(i=0;i<s;i++)
			{
			cout<<record[i].at(0)<<"\t"<<record[i].at(1)<<"\t"<<record[i].at(2)<<"\t"<<record[i].at(3)<<"\t";
			cout<<"\n";
			}
			cout<<"\n";
			break;
		case 2: for(i=1;i<s-1;i++)
			{
				for(j=1;j<s-i-1;j++)
				{
					if(record[j].at(1)>record[j+1].at(1))
						swap(record[j],record[j+1]);
				}
			}
			cout<<"Sorted records by name of author\n";
			for(i=0;i<s;i++)
			{
			cout<<record[i].at(0)<<"\t"<<record[i].at(1)<<"\t"<<record[i].at(2)<<"\t"<<record[i].at(3)<<"\t";
			cout<<"\n";
			}
			cout<<"\n";
			break;
		case 3: for(i=1;i<s-1;i++)
			{
				for(j=1;j<s-i-1;j++)
				{
					if(record[j].at(2)>record[j+1].at(2))
						swap(record[j],record[j+1]);
				}
			}
			cout<<"Sorted records by title keyword\n";
			for(i=0;i<s;i++)
			{
			cout<<record[i].at(0)<<"\t"<<record[i].at(1)<<"\t"<<record[i].at(2)<<"\t"<<record[i].at(3)<<"\t";
			cout<<"\n";
			}
			cout<<"\n";
			break;
		case 4: for(i=1;i<s-1;i++)
			{
				for(j=1;j<s-i-1;j++)
				{
					if(record[j].at(3)>record[j+1].at(3))
						swap(record[j],record[j+1]);
				}
			}
			cout<<"Sorted records by name of publisher\n";
			for(i=0;i<s;i++)
			{
			cout<<record[i].at(0)<<"\t"<<record[i].at(1)<<"\t"<<record[i].at(2)<<"\t"<<record[i].at(3)<<"\t";
			cout<<"\n";
			}
			cout<<"\n";
			break;
		case 5: return 0;
		}
		cout<<"Sort by other criteria?(y/n)";
		cin>>ch;
		}while(ch=='y'||ch=='Y');
	}
	cout<<"Do you want to continue?(y/n)";
	cin>>ch1;
	}while(ch1=='y'||ch=='Y');
}