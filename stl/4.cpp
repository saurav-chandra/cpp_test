/*
4. Write a program that produces anagrams of sentences; that is, a program
that produces all permutations of the words in the sentences (rather than
permutations of the letters in the words).
*/

#include<bits/stdc++.h>
using namespace std;

vector<string> arr;

void swap(string *str1, string *str2)
{
	string a=*str1;
	string b=*str2;
    *str1=b;
    *str2=a;
}

void generateAnagram(vector<string> a, int l, int r)
{
   int i, j;
   if (l == r)
   {
   	for(j=0;j<a.size();j++)
   	{
   		 cout<<a[j]<<"\t";
	   }
	   cout<<"\n";
   }
   else
   {
       for (i = l; i <= r; i++)
       {
          swap(&a[0+l], &a[0+i]);
          generateAnagram(a, l+1, r);
          swap(&a[0+l], &a[0+i]);
       }
   }
}

int main()
{
    arr.push_back("hello");
    arr.push_back("world");
    arr.push_back("this");
    arr.push_back("is");
    arr.push_back("Saurav");
    int n = arr.size();
    generateAnagram(arr, 0, n-1);
    return 0;
}
