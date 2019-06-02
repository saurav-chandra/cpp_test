/*
23. If we implement a queue as a circularly linked list then we need only one pointer rear (or tail) to
locate both the front and rear. Write C++ functions to process a queue stored in this way.
    a. Initialize
    b. Add Node
    c. Delete Node
*/

#include<bits/stdc++.h>
using namespace std;

typedef struct circular_linked_list_node
{
    int data;
    circular_linked_list_node * next;
}cll;

cll *rear = NULL;

void enqueue(int x)
{
    cll *temp;
    temp = (cll*)malloc(sizeof(cll));
    temp -> data = x;
    if(rear == NULL)
    {
        rear = temp;
        rear -> next = rear;
    }
    else
    {
        temp -> next = rear -> next;
        rear -> next = temp;
        rear = temp;
    }
    cout << "Inserted " << x << " in the queue\n";
}

int dequeue()
{
    //cll *temp;
    //temp = (cll*)malloc(sizeof(cll));
    //temp = rear -> next -> next;
    //rear = rear ->next;
    int x = rear -> next -> data;
    rear -> next = rear -> next -> next;
    //free(temp);
    return x;
}

void display()
{
    cout << "QUEUE : ";
    cll *ptr = rear -> next;
    do
    {
        cout << "[ " << ptr -> data << " ] -> ";
        ptr = ptr -> next;
    }while(ptr != rear -> next);
    cout << " again to first element : " << rear -> next -> data << endl;
    cout << "Head : " << rear -> next -> data << endl;
    cout << "Rear : " << rear -> data << endl;
}

int main()
{
    cout << "~~~>>>Queue using circular linked list<<<~~~\n";
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();
    cout << "\nDeleted " << dequeue() << " from rear in circular linked list\n";
    display();
    enqueue(40);
    display();
}