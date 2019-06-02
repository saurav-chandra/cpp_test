#include<bits/stdc++.h>
using namespace std;
#define MAX 10

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
        return 0;
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
        return 0;
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
    cout << "\nStack items are (top to down -> ) : ";
    for(i = 0; i <= topA ; i++)
    {
        cout << a[i] << ", ";
    }
    cout << '\b' << '\b' <<"  ";
    cout << "- ";
    for(i = topB; i < MAX ; i++)
    {
        cout << a[i] << ", ";
    }
    cout << '\b' << '\b' <<"  " <<endl;
}

/*
void Stack::display()
{
    cout << "\nStack items are (top to down -> ) : ";
    for(int i; i<MAX ; i++)
    {
        cout << a[i] << ", ";
    }
    cout << '\b' << '\b' <<"  " <<endl;
}
*/

int main()
{
    Stack st;
    st.pushA(10);
    st.pushA(53);
    st.pushB(33);
    st.pushB(78);
    st.display();
    cout << endl << st.popA() << " is popped" << endl;
    cout << endl << st.popB() << " is popped" << endl;
    st.display();
}