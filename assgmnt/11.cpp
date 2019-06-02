/*
11. Write a program to sort the contents of a singly linked list.
*/

#include<bits/stdc++.h>
using namespace std;

typedef struct linked_list_node
{
    int data;
    linked_list_node * next;
}ll;

ll *first = NULL;

void insert(int x)
{
    ll *temp;
    temp = (ll*)malloc(sizeof(ll));
    temp -> data = x;
    temp -> next = first;
    first = temp;
    //cout << "Inserted " << x << " in the linked list\n";
}

void display()
{
    ll *ptr = first;
    while(ptr != NULL)
    {
        cout << "[ " << ptr -> data << " ] -> ";
        ptr = ptr -> next;
    }
    cout << "NULL\n";
}

void sort()
{
    ll *i = first, *j;
    int temp;
    for(i = first; i -> next != NULL ; i = i -> next)
    {
        for(j = i -> next ; j != NULL ; j = j -> next)
        {
            if ( i -> data > j -> data)
                {
                    temp = i -> data;
                    i -> data = j -> data;
                    j -> data = temp;
                }
        }
    }
    cout << "Linked list after sorting : ";
    display();
}

int main()
{
    insert(95);
    insert(105);
    insert(30);
    insert(25);
    insert(35);
    insert(40);
    insert(95);
    insert(30);
    insert(20);
    cout << "Linked list before sorting : ";
    display();
    sort();
}