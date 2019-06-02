/*
20. Write a C++ program to implement stack using linked list
*/

#include<bits/stdc++.h>
using namespace std;

typedef struct node
{
    int value;
    struct node *next;
}ll;

ll *top = NULL;

void push(int x)
{
    ll *temp;
    temp = (ll*)malloc(sizeof(ll));
    temp -> value = x;
    temp -> next = top;
    top = temp;
}

int pop()
{
    ll *temp;
    temp = top;
    int n = temp -> value;
    top = top -> next;
    free (temp);
    return n;
}

void display()
{
    if(top == NULL)
        cout << "empty stack";
    else
    {
        ll *head = top;
        cout << "(top)--> ";
        while(head != NULL)
        {
            cout << "[ " << head -> value <<" ] -> ";
            head = head -> next;
        }
        cout << " NULL\n";
    }
}

int main()
{
    push(1);
    push(2);
    push(3);
    display();
    cout << "popped value : [" << pop() << "]\n";
    push(4);
    display();
}
