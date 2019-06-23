#include<bits/stdc++.h>
using namespace std;

int main()
{
	int i, x;
    while(1)
    {
        cout << "options available:\n\t1. insert at beg\n\t2. insert at end\n\t3. insert at a place\n\t";
        cout << "4. delete at beg\n\t5. delete at end\n\t6. delete at place\n\t7. search an element\n\t8. display\n\t9. exit\nenter your choice: ";
        cin >> i;
        cout << endl;
        switch(i)
        {
            case 1:
                cout << "enter a value to insert: ";
                cin >> x;
                // insertBeg(head,x);
            case 2:
                cout << "enter a value to insert: ";
                cin >> x;
                // insertEnd(head,x);
            case 3:
                cout << "enter a value to insert: ";
                cin >> x;
                // insertAt(head,x);
            case 4:
                // cout << "deleted from begining" << deleteBeg(head,x);
            case 5:
                // cout << "deleted from end" << deleteBeg(head,x);
            case 6:
                // cout << "deleted from an index" << deleteBeg(head,x);
            case 7:
                cout << "enter a value to insert: ";
                cin >> x;
                // search(head,x);
            case 8:
                // display(head);
            case 9:
                cout << "exiting the code, thanx";
                exit(1);
            default:
                cout << "enter again";
        } 
    } 
}



