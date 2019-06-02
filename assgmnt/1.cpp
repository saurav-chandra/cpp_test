/*
1. Sometimes a program requires two stack containing the same type of items. If the two stacks are
stored in separate arrays. Then one stack might overf low while there was considerable unused space
in the other. A neat way to avoid the problem is to put all the space in one array and let one stack
grow f rom one end of the array and the other stack start at the other end and grow in opposite
direction i.e., toward the f irst stack, in this way, if one stack turns out to be large and the other
small, then they will still both f it, and there will be no overf low until all the space is actually used.
Declare a new structure type Double stack that includes the array and the two indices top A and top
B, and write f unctions Push A, Push B, Pop A and Pop B to handle the two stacks with in one
Double Stack
*/

#include<bits/stdc++.h>
using namespace std;
#define MAX 100

class Stack
{
    int topA;
    int topB;
    public:
        int a[MAX];
        int pushA(int x);
        int pushB(int y);
        int popA();
        int popB();
        void display();
        Stack()
        {
            cout << "Stack created with two tops A and B" << endl;
            topA = -1;
            topB = MAX;
        }
};

int Stack::pushA(int x)
{
    if(topA + 1 == topB)
    {
        cout << "Stack overflow\n";
        return 0;
    }
    else
    {
        a[++topA] = x;
        cout << x << " is pushed in A\n";
        return x;
    } 
}

int Stack::pushB(int y)
{
    if(topA + 1 == topB)
    {
        cout << "Stack overflow\n";
        return 0;
    }
    else
    {
        a[--topB] = y;
        cout << y << " is pushed in B\n";
        return y;
    } 
}

int Stack::popA()
{
    if(topA < 0)
    {
        cout << "Stack underflow in A\n";
        return 0;
    }
    else
    {
        int x = a[topA--];
        return x;
    }
}

int Stack::popB()
{
    if(topB > MAX-1)
    {
        cout << "Stack underflow in B\n";
        return 0;
    }
    else
    {
        int y = a[topB++];
        return y;
    }
}

void Stack::display()
{
    int i;
    cout << "\nStack items are (left to right,  ' -- ' is diving the both stack) : ";
    for(i = 0; i <= topA ; i++)
    {
        cout << a[i] << ", ";
    }
    cout << '\b' << '\b' <<"  ";
    cout << "-- ";
    for(i = topB; i < MAX ; i++)
    {
        cout << a[i] << ", ";
    }
    cout << '\b' << '\b' <<"  " <<endl;
    cout << "Value of topA is : " << a[topA] << endl << "Value of topB is : " << a[topB] << endl;
}

int main()
{
    Stack stk;
    int choice, i;
    while(1)
    {
        cout << "\nEnter one of the following : \n\t1. Insert from left end\n\t2. Insert from right end\n\t3. Delete from left end\n\t4. Delete from right end\n\t5. Display stack elements\n\t6. Exit" << endl;
        cin >> choice;
        switch(choice)
        {
            case(1):
                cout << "Enter item to push in A : ";
                cin >> i;
                stk.pushA(i);
                break;
            case(2):
                cout << "Enter item to push in B : ";
                cin >> i;
                stk.pushB(i);
                break;
                break;
            case(3):
                cout << endl << stk.popA() << " is popped" << endl;
                break;
            case(4):
                cout << endl << stk.popB() << " is popped" << endl;
                break;
            case(5):
                stk.display();
                break;
            case(6):
                cout << "exiting this wonderful program that was beautifully written by Saurav Chandra";
                exit (0);
        }
    }
}