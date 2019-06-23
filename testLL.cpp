//to test linked list with functions
#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

void insertEnd(struct Node** headR, int n)
{
    struct Node* newN = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *headR;
    newN -> data = n;
    newN -> next = NULL;
    

    if(*headR == NULL)
    {
        *headR = newN;
    return;
    }

    while(last -> next != NULL)
    {
        last = last -> next;
    }
    last -> next = newN;
    //cout << "inserted at end\n" << newN -> next -> data;
    return;
}

void printLL(struct Node* node)
{
    /*
    struct Node  *temp;
    temp = (struct Node*)malloc(sizeof(struct Node));
    temp = head;
    while(temp -> next != NULL)
    */
    while(node != NULL)
    {
        cout << node -> data << " ";
        node = node -> next;
    }
}

int main()
{
    struct Node* head = NULL;
    // head -> data = 20;
    // head -> next = NULL;
    insertEnd(&head, 36);
    insertEnd(&head, 45);
    printLL(head);
}