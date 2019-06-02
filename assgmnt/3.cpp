/*
3.Write a C program to reverse the elements in the stack using recursion.
*/

#include<bits/stdc++.h>
using namespace std;
#define MAX 10

class Stack
{
    public:
        Stack();
        int a[MAX];
        //int arr[MAX];
        void push(int x);
        int pop();
        void display();
        void copy();
        void swap(int bottom , int above);
    private:
        int top;
        //int topB;
};

Stack::Stack()
{
    cout << "stack created\n";
    top = -1;
    //topB = -1;
}

void Stack::push(int x)
{
    if(top >= MAX)
    {
        cout << "stack full";
    }
    else
    {
        a[++top] = x;
    }
}

int Stack::pop()
{
    if(top < 0)
    {
        cout <<"stack empty";
        return 0;
    }
    else
    {
        int x = a[top--];
        return x;
    }
}

void Stack::display()
{
    cout << "stack items : \n";
    for(int i = 0 ; i <= top  ; i++)
    cout <<"|"<< a[i];
    cout << "|-->(top)\n";
}

/*
void Stack::copy()
{
    cout << "\nnew ";
    //Stack  newStack;
    int arr[MAX];
    int x = top;
    for(int i = 0 ; i <= x ; i++)
    {
        topB++;
        arr[topB] = a[top];
        top--;
        cout <<"|"<< arr[i];
    }
    cout << "|-->(top)\n";
}
*/

void Stack::copy()
{
    int bottom = 0;
    int above = top;
    swap(bottom , above);
}

void Stack :: swap(int bottom, int above)
{
    if ( bottom <= top/2)
    {
        int temp;
        temp = a[bottom];
        a[bottom] = a[above];
        a[above] = temp;
        swap(bottom+1 , above-1);
    }
}

int main()
{
    Stack stk;
    Stack newStack;
    stk.push(74);
    stk.push(56);
    stk.push(85);
    stk.push(60);
    stk.push(22);
    stk.push(33);
    stk.push(52);
    stk.push(36);
    stk.display();
    cout << "\npopped item : " << stk.pop() << "\n";
    stk.display();
    stk.copy();
    cout << "\nafter reversing - ";
    stk.display();
}
