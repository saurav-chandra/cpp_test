/*
2. Let stack_ptr be a pointer to stack of integers and item be an integer variable. Write f unction like
Push, Pop, Initialize, Empty, and Full f or doing the f ollowing tasks. [You may declare additional
variable in your f unctions in needed]
a) Return the top element of the stack and leave the top element unchanged. If the stack is
empty, return INT_MAX.
b) Return the third element f rom the top of the stack, provided that the stack contains at least
three integers. If not, return INT_MAX. Leave the stack unchanged.
c) Returns the bottom element of stack ( or INT_MAX if stack empty), and leave the stack
unchanged.
d) Delete all occurrences of x f rom the stack, leaving the other elements of the stack in the
same order.
*/

#include<bits/stdc++.h>
using namespace std;
#define MAX 10

class Stack
{
    int top;
    int int_max = 0;
    public:
        int a[MAX];
        int push(int x);
        int pop();
        void display();
        Stack()
        {
            cout << "Stack created with two tops A and B" << endl;
            top = -1;
        }
        int topElement();
        int third();
        int bottom();
        int deleteElement(int n);
};

int Stack::push(int x)
{
    if(top >= MAX)
    {
        cout << "Stack overflow\n";
        return 0;
    }
    else
    {
        a[++top] = x;
        cout << x << " is pushed in stack\n";
        return 0;
    } 
}

int Stack::pop()
{
    if(top < 0)
    {
        cout << "Stack underflow\n";
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
    int i;
    cout << "\nStack items are (top to down -> ) : ";
    for(i = 0; i <= top ; i++)
    {
        cout << a[i] << ", ";
    }
    cout << '\b' << '\b' <<"  "<<endl;
    cout << "Value of top is : " << a[top];
}

int Stack::topElement()
{
    if(top < 0 )
        return int_max;
    else
        return  a[top];
}

int Stack::third()
{
        if(top < 0 )
        return int_max;
    else
        return a[top-2];
}

int Stack::bottom()
{
    if(top < 0 )
        return int_max;
    else
        return a[0];
}


int Stack::deleteElement(int n)
{
    int i=0; 
    for(int j=0; j<MAX; j++)
    {
        if(a[j]!=n)
        {
            a[i]=a[j];
            i++;
        }
        else
            top--;
    }
return n;
}

int main()
{
    Stack stk;
    Stack *stkPtr;
    stkPtr = &stk;
    stkPtr -> push(10);
    stkPtr -> push(53);
    stk.display();
    cout << endl << stkPtr -> pop() << " is popped" << endl;
    stk.display();
    cout << endl;
    stkPtr->push(28);
    stkPtr->push(2);
    stkPtr->push(12);
    stkPtr->push(28);
    stk.display();
    cout <<"\n\n"<< "Top of Stack is : " << stkPtr->topElement();
    cout << endl << "Third Element of Stack is : " << stkPtr->third();
    cout << endl << "Bottom of Stack is : " << stkPtr->bottom();
    stk.display();
    cout << endl << "\nDeleted " << stkPtr->deleteElement(28) << " from the stack\n";
    stk.display();

return 0;
}