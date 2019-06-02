/*
17. Write a C++ program to implement all the f unctions of a dictionary (ADT) using hashing.
*/

#include<bits/stdc++.h>
using namespace std;
#define node struct node
#define MAX 10

node
{
    int data;
    node *next;
} *ptr[MAX],*root[MAX],*temp[MAX];

class Dictionary
{
    private:
        int index;
    public:
        Dictionary();
        void insert(int x);
        void search(int x);
        void deleteElement(int x);
};

Dictionary::Dictionary()
{
    index=-1;
    for(int i=0; i < MAX; i++)
    {
        root[i]=NULL;
        ptr[i]=NULL;
        temp[i]=NULL;
    }
}

void Dictionary::insert(int x)
{
    index = int(x % MAX);
    ptr[index] = (node*)malloc(sizeof(node));
    ptr[index] -> data = x;
    if(root[index] == NULL)
    {
        root[index] = ptr[index];
        root[index] -> next=NULL;
        temp[index] = ptr[index];
    }
    else
    {
        temp[index] = root[index];
        while(temp[index] -> next != NULL)
            temp[index] = temp[index] -> next;
        temp[index] -> next = ptr[index];
    }
}
void Dictionary::search(int x)
{
    int flag = 0;
    index = int(x % MAX);
    temp[index] = root[index];
    while(temp[index] != NULL)
    {
        if(temp[index] -> data == x)
        {
            cout<< endl << x << " is found in dictionary";
            flag = 1;
            break;
        }
        else
            temp[index] = temp[index] -> next;
    }
    if (flag == 0)
        cout<< endl << "Element not found in dictionary";
}
void Dictionary::deleteElement(int x)
{
    index = int(x % MAX);
    temp[index] = root[index];
    while(temp[index] -> data != x && temp[index] != NULL)
    {
        ptr[index] = temp[index];
        temp[index] = temp[index] -> next;
    }
    ptr[index] -> next = temp[index] -> next;
    cout<< endl << temp[index] -> data << " is deleted from dicctionary";
    temp[index] -> data = -1;
    temp[index] = NULL;
    free(temp[index]);
}

int main()
{
    int value, choice, num;
    Dictionary dict;

    while(1)
    {
        cout << "\n\nDictionary Functions\n\t1. Insert element\n\t2. Search element\n\t3. Delete an element\n\t4. Exit\nEnter your choice : ";
        cin >> choice;
        cout << endl;
        switch(choice)
        {
        case 1:
            cout << "\nEnter the element to insert : ";
            cin >> num;
            dict.insert(num);
            break;
        case 2:
            cout << "\nEnter the element to search : ";
            cin >> num;
            dict.search(num);
            break;
        case 3:
            cout<<"\nEnter the element to delete : ";
            cin >> num;
            dict.deleteElement(num);
            break;
        case 4:
            cout << "Exiting Program";
            exit (0);
        default:
            cout<<"\nWrong input, Please try again\n";
        }
    }
    return 0;
}