/*
8. Write a program to reverse the content of a Singly Linked List.
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
    cout << "Inserted " << x << " in the linked list\n";
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

void reverse()
{
    ll *prev = NULL , *next, *head = first;
    while(head != NULL)
    {
        next = head -> next;
        head -> next = prev;
        prev = head;
        head = next;
    }
    first = prev;
    cout << "Linked list after reversing : ";
    display();
}

int main()
{
    insert(10);
    insert(20);
    insert(30);
    display();
    reverse();
}