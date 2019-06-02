#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node* next;
};

//node* head;

//void insert(int data)
void insert(node* head, int data)
{
    node* last = new node;
	last -> data = data;
	last -> next = NULL;
	
	if(head == NULL)
		head = last;
	else
	{
		node* temp = new node;
		temp = head;
		while(temp -> next != NULL)
			temp = temp -> next;
		temp -> next = last;
	}
		
}

void prints(node* head)
{
	node* ptr = new node;
	ptr = head;
	while(ptr != NULL)
	{
		cout << ptr -> data << " "; 
		ptr = ptr -> next;
	}
	cout << endl;
}

void print(node* head)
{
    node* temp = new node;
    temp = head;
    node* temp2 = new node;
    temp2 = head;
    while(temp != NULL)
    {
        if(temp->data %2 == 0)
            cout << temp->data << " ";
        temp = temp -> next;
    }
    
    while(temp2 != NULL)
    {
        if(temp2->data %2 != 0)
            cout << temp2->data << " ";
        temp2 = temp2 -> next;
    }
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n,temp;
        cin >> n;
        node* head;
        node* temps = new node;
        temps = head;
        while(n--)
        {
            cin >> temp;
            insert(temps,temp);
        }
        //prints(head);

        print(temps);
        
        cout << endl;
    }
return 0;
}
