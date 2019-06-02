/*
7. Write a C program to f ind the largest element in a given doubly linked list.
*/

#include<bits/stdc++.h>
using namespace std;

typedef struct doubly_linked_list
{
    int data;
    doubly_linked_list *prev;
    doubly_linked_list *next;
}dll;

dll *first = NULL;
dll *last = NULL;

void insert(int x)
{
    dll *temp;
    temp = (dll*)malloc(sizeof(dll));
    temp -> data = x;
    if(first != NULL)
        first -> prev = temp;
    temp -> next = first;
    first = temp;
    cout << "Inserted " << first -> data << " in doubly linked list" << endl;
    
}

void largest()
{
    dll *ptr, * max;
    ptr = max = first;
    while(ptr != NULL)
    {
        if(ptr -> data > max -> data)
            max -> data = ptr -> data;
        else
            ptr = ptr -> next;
    }
    cout << "Largest element in linked list is : " << max -> data;
}

void display()
{
    dll *head = first;
    while (head != NULL)
    {
        cout <<" [ " << head -> data << " ] ->";
        head = head -> next;
    }
    cout << "NULL\n" << endl;
}

int main()
{
    insert(10);
    insert(5);
    insert(11);
    insert(12);
    insert(6);
    display();
    largest();
}