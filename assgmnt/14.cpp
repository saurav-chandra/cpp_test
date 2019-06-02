/*
14. Write a C++ program that uses f unctions to perf orm the f ollowing:
a) Create a binary search tree of characters.
b) Traverse the above Binary search tree recursively in Postorder.\
*/

#include<bits/stdc++.h>
using namespace std;
#define tn struct tree_node

tn
{
    char data;
    tn * left;
    tn * right;
};

tn *newNode(char x)
{
    tn *temp = (tn *)malloc(sizeof(tn));
    temp -> data = x;
    temp -> left = temp -> right = NULL;
    return temp;
}

void postorder(tn *root)
{
    if(root != NULL)
    {
        postorder(root -> left);
        postorder(root -> right);
        cout << root -> data;
    }
}

tn *insert(tn *node, char x)
{
    if(node == NULL)
    {
        return newNode(x);
    }
    if(x <= (node -> data))
    {
        node -> left = insert(node -> left, x);
    }
    else if (x > (node-> data))
    {
        node -> right = insert(node -> right, x);
    }
    cout << "inserted " << x << endl;
    return node;
}

int main()
{
    tn *root = NULL; 
    root = insert(root, 'E'); 
    insert(root, 'C'); 
    insert(root, 'B'); 
    insert(root, 'D'); 
    insert(root, 'G'); 
    insert(root, 'F'); 
    insert(root, 'H');
    cout << "Postorder traversal of the tree is : ";
    postorder(root); 
    return 0; 
}