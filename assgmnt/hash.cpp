#include<bits/stdc++.h>
using namespace std;

class HashTable
{
	private:
		int bucketSize;
		list<int> *hashTable;
	
	public:
		HashTable(int x);
		void insertKey(int y);
		int hashFn(int p);
		void displayTable();
};

HashTable::HashTable(int x)
{
	bucketSize = x;
	hashTable = new list<int>[bucketSize];
}

void HashTable::insertKey(int y)
{
	int index = hashFn(y);
	hashTable[index].push_back(y);
}

int HashTable::hashFn(int p)
{
	int hash = p % 10 ;
	return hash;
}

void HashTable::displayTable()
{
	for(int i = 0; i < bucketSize; ++i)
	{
		  cout << "\nBucket No : "<< i;
		  cout << " -- elements in this bucket : ";
		  
		  list <int> :: iterator x;
		  for(x = hashTable[i].begin(); x != hashTable[i].end(); ++x)
		  {
		          cout << *x << " --> ";
		  }
		  cout << "NULL\n";
	}
}

int main()
{
int size = 10;
cout << "\nHash Table with chaining\n";
HashTable ht( size );
int choice, key;
while( 1 )
{
	cout << "Enter one of the following :";
	cout << "\n\t 1. Insert a key ";
	cout << "\n\t 2. Display the hash table ";
	cout << "\n\t 3. Exit \n";
	cin >> choice;

	switch( choice )
	{
		case 1:
                    cout << "\nEnter element to insert : ";
                    cin >> key;
                    ht.insertKey( key );
                    cout << "\n";
                    break;
		case 2: 
                    cout << "\nThe hash table looks like : \n";
                    ht.displayTable();
                    cout << "\n";
                    break;
		case 3:
                  exit(0);
                  break;
		default:
                  cout << "\nEnter a valid choice..!\n";       
	}
}
return 0; 
}
