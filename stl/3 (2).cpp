/*
3. 
*/

#include<bits/stdc++.h>
using namespace std;
#define MAX 10

void permutation(char word2[MAX],int begin,int end)
{
    int j;
    if (begin == end)
        cout << word2 << endl;
    else
    {
        for (j = begin; j < strlen(word2); j++)
        {
            swap(word2[begin],word2[j]);
            permutation(word2, begin + 1, end);
            swap(word2[begin],word2[j]);
        }  
    }
}

int main()
{
	char word[MAX];
	cout << "Enter a word : ";
	cin >> word;
	cout << "Word entered by user is : '" << word << "', now we will write all the anagrams.";
	cout << endl;
	//cout << word[2];
	//cout << strlen(word);
}
