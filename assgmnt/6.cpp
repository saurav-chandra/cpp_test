/*
6. Write a program to implement a Singly Linked List that perf orms the f ollowing operations:
(i) Insertion of an element in the beginning of the list
(ii) Insertion of an element in the middle of the list
(iii) Insertion of an element at the end of the list
(iv) Deletion of an element f rom the beginning of the list
(v) Deletion of an element f rom the middle of the list
(vi) Deletion of an element f rom the end of the list
(vii) Traverse a linked list
(viii) Finding an element in the linked list
(ix) Printing the elements of a linked list.
*/

#include<bits/stdc++.h>
using namespace std;

typedef struct node
{
    int data;
    struct node *next;
}ll;

ll *first = NULL;

void insertBeg(int x)
{
    ll *temp;
    temp = (ll*)malloc(sizeof(ll));
    temp -> data = x;
    temp -> next = first;
    first = temp;
    cout << "Inserted at beginning : " << first -> data;
}

void insertMid(int x)
{
	int length = 0;
    ll *mid;
    mid = (ll*)malloc(sizeof(ll));
	mid -> data = x;
    mid -> next = NULL;
	ll *s = first;
    while(s != NULL)
    {
        length++;
        s = s -> next;
    }
    cout << "total elements in linked list are : " << length << endl;
    int count = ((length % 2) == 0) ? (length / 2) : (length+1) /2;
    s = first;
    while( count-- > 1)
    {
    	s = s -> next;
    }
    mid -> next = s -> next;
    s -> next = mid;
}

/*
void insertMid(int x)
{
	ll* mid = (ll*)malloc(sizeof(ll));
	mid -> data = x;
    mid -> next = NULL;
	ll *fast = first -> next;
	ll *slow = first;
	while(fast != NULL && fast -> next != NULL)
    //while(fast && fast->next)
	{
        slow = slow -> next;
		fast = fast -> next -> next;
	}
	mid -> next = slow -> next;
	slow -> next = mid;
}
*/

void insertEnd(int x)
{
	ll *last;
	last = (ll*)malloc(sizeof(ll));
	last -> data = x;
	last -> next = NULL;
	ll *s = first;
	while(s -> next != NULL)
        {
            s = s -> next;
        }
        s -> next = last;
	cout << "\nInsereted at last : " << last -> data;
}

int  deleteBeg()
{
    ll *temp;
    temp = (ll*)malloc(sizeof(ll));
    temp = first;
    first = first ->next;
    int x = temp -> data;
    free(temp);
    return x;
}

int  deleteMid()
{
	ll *fast = first -> next;
	ll *slow = first;
    ll *mid = first;
	while(fast != NULL && fast -> next != NULL)
    //while(fast && fast->next)
	{
        slow = slow -> next;
		fast = fast -> next -> next;
	}
    while(mid -> next != slow)
    {
        mid = mid -> next;
    }
    int x = slow -> data;
	mid -> next = slow -> next;
	free(slow);
    return x;
}

int  deleteEnd()
{
    ll *last = first -> next, *ptr = first;
    while(last -> next != NULL)
    {
        last = last -> next;
        ptr = ptr -> next;
    }
    int x = last -> data;
    ptr -> next = NULL;
    free(last);
    return x;
}

void traverse()
{
	int length= 0;
    if(first == NULL)
        cout << "Empty list";
    else
    {
        ll *head = first;
        cout << "(first)--> ";
        while(head != NULL)
        {
            cout << "[ " << head -> data <<" ] -> ";
            head = head -> next;
            length++;
        }
        cout << "NULL\n";
        cout << "total elements in linked list are : " << length<< endl;
    }
}

void search(int x)
{
    ll *ptr = first;
    int pos = 0;
    while(ptr -> data != x)
    {
        ptr = ptr -> next;
        pos++;
    }
    cout << "Found " << x << " at index : " << pos << endl << "Its position in linked list is : " << pos+1;
}

void display()
{
	int length= 0;
    if(first == NULL)
        cout << "Empty list";
    else
    {
        ll *head = first;
        cout << "(first)--> ";
        while(head != NULL)
        {
            cout << "[ " << head -> data <<" ] -> ";
            head = head -> next;
            length++;
        }
        cout << "NULL\n";
        cout << "total elements in linked list are : " << length<< endl;
    }
}

int main()
{
    int choice,x;
    while(1)
    {
        cout << "\n\t~~~>>>SINGLY LINKED LIST<<<~~~\nOperations to be perfomed are :\n\t1. Insert at beginning\n\t2. Insert at middle\n\t3. Insert at end\n\t4. Deletion at beginning\n\t5. Deletion at middle\n\t6. Deletion at end\n\t7. Traverser the linked list\n\t8. Find an element in linked list\n\t9. Print linked list\n\t10. Exit\nEnter your choice : ";
        cin >> choice;
        cout << endl;
        switch (choice)
        {
            case 1:
                cout << "Enter the element to insert in beginning : ";
                cin >> x;
                insertBeg(x);
                break;
            case 2:
                cout << "Enter the element to insert in middle : ";
                cin >> x;
                insertMid(x);
                break;
            case 3:
                cout << "Enter the element to insert in end : ";
                cin >> x;
                insertEnd(x);
                break;
            case 4:
                cout << "Deleting the element from beginning which is : " << deleteBeg() << endl;
                break;
            case 5:
                cout << "Deleting the element from middle which is : " << deleteMid() << endl;
                break;
            case 6:
                cout << "Deleting the element from end which is : " << deleteEnd() << endl;
                break;
            case 7:
                cout << "Traversing linked list \n";
                traverse();
                break;
            case 8:
                cout << "Enter the element to search : ";
                cin >> x;
                search(x);
                break;
            case 9:
                cout << "Print all the elements of linked list\n";
                display();
                break;
            case 10:
                cout << "Exiting this program\n";
                return 0;
                break;
        }
    }
}
