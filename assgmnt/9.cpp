/*
9. Write a program to remove the duplicate element(s) in a Linked List.
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

void duplicate()
{
    ll *ptr1 = first, *ptr2, *dup;
    while(ptr1 -> next != NULL && ptr1 != NULL)
    {
        ptr2 = ptr1;
        while(ptr2 -> next != NULL && ptr2 != NULL)
        {
           if(ptr1 -> data == ptr2 -> next -> data)
           {
               dup = ptr2 -> next;
               ptr2 -> next = ptr2 -> next -> next;
               free(dup);
           } 
           else
           {
               ptr2 = ptr2 -> next;
           }
        }
        ptr1 = ptr1 -> next;
    }
    cout << "Linked list after removing duplicate elements : ";
    display();
}

int main()
{
    insert(10);
    insert(20);
    insert(30);
    display();
    insert(25);
    insert(30);
    insert(40);
    insert(95);
    insert(30);
    insert(20);
    duplicate();
}