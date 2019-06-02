/*
10. Write a program to merge two sorted linked list.
*/

#include<bits/stdc++.h>
using namespace std;

typedef struct linked_list_node
{
    int data;
    linked_list_node * next;
}ll;

ll *ll1 = NULL;
ll *ll2 = NULL;

void insert(ll **first, int x)
{
    ll *temp;
    temp = (ll*)malloc(sizeof(ll));
    temp -> data = x;
    temp -> next = *first;
    *first = temp;
}

void display(ll *ptr)
{
    while(ptr != NULL)
    {
        cout << "[ " << ptr -> data << " ] -> ";
        ptr = ptr -> next;
    }
    cout << "NULL\n";
}

void merge(ll *i, ll *j)
{
    ll *newLL = NULL;
    if (i == NULL)
        newLL = j;
    if (j == NULL)
        newLL = i;
    while(i != NULL && j != NULL)
    {
        if(i -> data > j -> data)
        {
            insert(&newLL , j -> data);
            j = j-> next;
        }
        else
        {
            insert(&newLL , i -> data);
            i = i -> next;
        }
        if(j == NULL)
            {
                insert(&newLL , i -> data);
                i = i -> next;
            }
        if(i == NULL)
            {
                insert(&newLL , j -> data);
                j = j-> next;
            }
    }
    display(newLL);
}

int main()
{
    insert(&ll1,105);
    insert(&ll1,95);
    insert(&ll1,35);
    insert(&ll1,30);
    insert(&ll1,25);

    insert(&ll2,140);
    insert(&ll2,96);
    insert(&ll2,40);
    insert(&ll2,31);
    insert(&ll2,20);
    insert(&ll2,15);
    cout << "Both Linked lists before sorting are : \n";
    cout << "1st list : ";
    display(ll1);
    cout << "2nd list : ";
    display(ll2);
    cout << "\nAfter merging both sorted linked lists in descending order: \n";
    cout << "New list : ";
    merge(ll1, ll2);
}