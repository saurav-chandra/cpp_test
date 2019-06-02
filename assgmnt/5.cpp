/*
5. Write C++ f unctions to implement queues by the simple method of keeping the head of the queue
always in the f irst position of a linear array
*/

#include<bits/stdc++.h>
using namespace std;
#define MAX 10

class Queue 
{
    private:
        int head;
        int rear;
    public:
        int a[MAX];
        Queue()
        {
            cout << "queue created\n";
            head = 0;
            rear = 0;
        }
        void enqueue(int x);
        int dequeue();
        void display();
};

void Queue::enqueue(int x)
{
    if( rear > MAX)
    {
        cout << "queue full";
    }
    else
    {
        a[rear++] = x;
    }
}

int Queue::dequeue()
{
    if(rear < 0)
    {
        cout << "queue empty";
        return 0;
    }
    else
    {
        int x = a[--rear];
        return x;
    }
}

void Queue::display()
{
    cout << "(head)<--";
    for(int i = head ; i < rear ; i++)
    {
        cout <<"|"<< a[i];
    }
    cout << "|-->(rear)\n";
}

int main ()
{
    Queue qu;
    qu.enqueue(58);
    qu.enqueue(90);
    qu.enqueue(12);
    qu.enqueue(5);
    qu.enqueue(64);
    qu.display();
    cout << "deleted element : " << qu.dequeue() << endl;
    qu.display();
}