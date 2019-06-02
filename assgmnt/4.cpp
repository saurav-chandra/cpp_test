/*
4. Write a C program that uses stack operations to convert a given infix expression into its postfix
Equivalent, Implement the stack using an array.
*/

#include<bits/stdc++.h>
using namespace std;
#define MAX 15

class Stack
{
    private:
        int top;
    public:
        void push(char x);
        char pop();
        void display();
        int stackTop();
        bool empty();
        char arr[MAX];
        Stack()
        {
            top = -1;
        }
};

void Stack::push(char x)
{
    if(top == MAX)
        cout << "Stack Full";
    else
        arr[++top] = x;
}

char Stack::pop()
{
    if(top <= -1)
    {
        cout << "Stack Empty";
        return 0;
    }
    else
    {
        int x = arr[top--];
        return x;
    }
}

void Stack::display()
{
    cout << "Postfix expression is : ";
    for(int i = 0; i <= top ; i++)
    {
        cout << arr[i];
    }
}

int Stack::stackTop()
{
    return arr[top];
}

bool Stack::empty()
{
    if(top == -1)
        return true;
    
        return false;
}

int priority(char a)
{
    int temp;
    if (a == '^')
        temp = 3;
    else  if (a == '*' || a == '/')
        temp = 2;
    else  if (a == '+' || a == '-')
        temp = 1;
    return temp;
}

int main()
{
    Stack postfix, operators;
    //stack<char> operators;
    string infix;
    int i;
    cout << "Enter an infix expression : ";
    getline(cin, infix);

    for(i = 0; i < infix.length(); i++)
    {
        if(infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/' || infix[i] == '^')
        {
            while(!operators.empty() && priority(operators.stackTop()) >= priority(infix[i]))
            {
                postfix.push(operators.stackTop());
                operators.pop();
            }
            operators.push(infix[i]);
        }
        else
            postfix.push(infix[i]);
    }
    while (!operators.empty())
    {
        postfix.push(operators.stackTop());
        operators.pop();
    }
    postfix.display();
    return 0;
}