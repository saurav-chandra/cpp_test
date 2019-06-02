/*
13. Write C++ programs to implement a double ended queue ADT using
        i) array and
        ii) doubly linked list respectively.
*/

#include<bits/stdc++.h>
using namespace std;
#define MAX 15

typedef struct doubly_linked_list
{
    int data;
    doubly_linked_list *prev;
    doubly_linked_list *next;
}dll;

dll *end1 = NULL;
dll *end2 = NULL;
dll *head1 = NULL;
dll *head2 = NULL;
int ch;
int array[MAX];
int rear1 = -1, rear2 = MAX + 1, headArr1 = 0, headArr2 = MAX;

void insertEnd1(int x)
{
    if(ch == 1)
    {
        ::array[++rear1] = x;
        cout << "Inserted " << x << " in the array from rear1\n";
    }
    if(ch == 2)
    {
        dll *temp;
        temp = (dll*)malloc(sizeof(dll));
        temp -> data = x;
        if(end1 != NULL)
            end1 -> prev = temp;
        else
            head1 = temp;
        temp -> next = end1;
        end1 = temp;
        cout << "Inserted " << end1 -> data << " at END1 in doubly ended queue\n";
    }
}

void insertEnd2(int x)
{
    if(ch == 1)
    {
        ::array[--rear2] = x;
        cout << "Inserted " << x << " in the array from rear2\n";
    }
    if(ch == 2)
    {
        end2 = (dll*)malloc(sizeof(dll));
        end2 -> data = x;
        end2 -> next = NULL;
        dll *s = end1;
        while(s -> next != NULL)
            {
                s = s -> next;
            }
            s -> next = end2;
            end2 -> prev = s;
        cout << "\nInsereted at end2 : " << end2 -> data;
    }
}

int  deleteEnd1()
{
    int x;
    if(ch == 1)
    {
        x = ::array[rear1--];
        //cout << "Deleted " << x << " in the array from rear1\n";

    }
    if(ch == 2)
    {
        dll *temp;
        temp = (dll*)malloc(sizeof(dll));
        temp = end1;
        end1 = end1 ->next;
        x = temp -> data;
        free(temp);
        //return x;
    }
    return x;
}

int  deleteEnd2()
{
    int x;
    if(ch == 1)
    {
        x = ::array[rear2--];
        //cout << "Deleted " << x << " in the array from rear2\n";
        //return x;
    }
    if(ch == 2)
    {
        dll *end2 = end1 -> next, *ptr = end1;
        while(end2 -> next != NULL)
        {
            end2 = end2 -> next;
            ptr = ptr -> next;
        }
        x = end2 -> data;
        ptr -> next = NULL;
        free(end2);
        //return x;
    }
    return x;
}

void display()
{
    if(ch == 1)
    {
        cout << "Important elements in Double ended queue using array are :-\n";
        cout << "Head1 : " << ::array[headArr1] << endl;
        cout << "Head2 : " << ::array[headArr2] << endl;
        cout << "Rear1 : " << ::array[rear1] << endl;
        cout << "Rear2 : " << ::array[rear2] << endl;
    }
    if(ch == 2)
    {
        int length= 0;
        if(end1 == NULL)
            cout << "Empty list";
        else
        {
            dll *head = end1;
            cout << "(End1) NULL -> ";
            while(head != NULL)
            {
                cout << "[ " << head -> data << " ] -> ";
                head = head -> next;
                length++;
            }
            cout << "NULL (End2)\n";
            cout << "Total elements in linked list are : " << length<< endl;
        }
    }
}

int main()
{
    int choice,x;
    string type;
    cout << "Implementation of Double Ended Queue using\n\t1. Array\n\t2. Doubly Linked List\nEnter your choice : ";
    cin >> ch;
    if(ch == 1)
        type = "ARRAY";
    else if(ch == 2)
        type = "DOUBLY LINKED LIST";
    else
    {
        cout << "Exiting program... Please choose either 1 or 2";
        exit (0);
    }
    while(1)
    {
        cout << "\n\t~~~>>>QUEUE USING " << type << "<<<~~~\nOperations to be perfomed are :\n\t1. Insert at End1\n\t2. Insert at End2\n\t3. Deletion at End1\n\t4. Deletion at End2\n\t5. Display\n\t6. Exit\nEnter your choice : ";
        cin >> choice;
        cout << endl;
        switch (choice)
        {
            case 1:
                cout << "Enter the element to insert in End1 : ";
                cin >> x;
                insertEnd1(x);
                break;
            case 2:
                cout << "Enter the element to insert in End2 : ";
                cin >> x;
                insertEnd2(x);
                break;
            case 3:
                cout << "Deleting the element from End1/Rear1 which is : " << deleteEnd1() << endl;
                break;
            case 4:
                cout << "Deleting the element from End2/Rear2 which is : " << deleteEnd2() << endl;
                break;
            case 5:
                cout << "Displaying the contents of double ended queue using " << type << endl;
                display();
                break;
            case 6:
                cout << "Exiting this program\n";
                return 0;
                break;
            default:
                cout << "Wrong choice, Please enter again\n";
                break;
        }
    }
}
