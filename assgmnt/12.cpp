/*
12. Write a C++ program that uses f unctions to perf orm the f ollowing:
a) Create a doubly linked list of integers.
b) Delete a given integer f rom the above doubly linked list.
c) Display the contents of the above list af ter deletion
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

void insert(int x)
{
    dll *temp;
    temp = (dll*)malloc(sizeof(dll));
    temp -> data = x;
    temp -> prev = NULL;
    temp -> next = first;
    first = temp;
    cout << "Inserted " << first -> data << " in doubly linked list" << endl;
}

void deleteElement(int x)
{
    dll *ptr = first;
    while(ptr -> next -> data != x)
    {
        ptr = ptr -> next;
    }
    ptr -> next = ptr -> next -> next;
    cout << "Deleted " << x << " from doubly linked list\n";
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
    display();
    insert(20);
    display();
    insert(30);
    display();
    insert(40);
    display();
    deleteElement(20);
    display();
}