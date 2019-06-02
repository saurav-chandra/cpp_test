/*
3. Write a function in C++ to produce all anagrams of the word food. That is,
all four-letter combinations of the let-ters f,o,o, and d. Do not generate
duplicates. Generalize this program to take a word as input and produce
anagrams of that word.
*/

#include<bits/stdc++.h>
using namespace std;

vector <string> check;

bool ifExists(string a)
{
	int i;
	for(i=0;i<check.size();i++)
	{
		if(check[i]==a)
		return true;

	}
	return false;
}

void generateAnagram(string str,string out)
{
	bool a;
	if(str.size()==0)
	{
		a=ifExists(out);
		if(!a)
		{
			check.push_back(out);
			cout<<out<<endl;

		}
		return;
	}
	for (int i = 0; i < str.size(); i++)
    {

        generateAnagram(str.substr(1), out + str[0]);
        rotate(str.begin(), str.begin() + 1, str.end());
    }
}

int main()
{
    string str = "food";
	cout << "All anagrams of the word 'food' are:\n";
    generateAnagram(str, "");
    cout<<"\n\nGeneralizing the same concept to any word\nEnter a string to find its anagrams: ";
    cin>>str;
    generateAnagram(str, "");
    return 0;
}
