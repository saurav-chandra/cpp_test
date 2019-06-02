/*
21. Write a C ++ program to count the number of nodes in the binary search tree.
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

int count = 0;

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
        ::count++;
    }
}

tn *insert(tn *node, char x)
{
    if(node == NULL)
    {
        return newNode(x);
    }
    if(x < (node -> data))
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
    cout << "\nTotal no. of elements in tree are : " << ::count;
    return 0; 
}