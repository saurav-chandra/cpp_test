/*
15. Design, Develop and Implement a menu driven Program in C++ f or the f ollowing operations on
Binary Search Tree (BST) of Integers
    a. Create a BST of N Integers: 6, 9, 5, 2, 8, 15, 24, 14, 7, 8, 5, 2
    b. Traverse the BST in Inorder, Preorder and Post Order
    c. Search the BST for a given element (KEY) and report the appropriate message
    d. Delete an element(ELEM) from BST
    e. Exit
*/

#include<bits/stdc++.h>
using namespace std;
#define tn struct tree_node
#define MAX 15

int array[MAX];
int i = 0;

tn
{
    int data;
    tn * left;
    tn * right;
};


tn *newNode(int x)
{
    tn *temp = (tn *)malloc(sizeof(tn));
    temp -> data = x;
    temp -> left = NULL;
    temp -> right = NULL;
    return temp;
}

void postorder(tn *root)
{
    if(root == NULL)
    return;

        postorder(root -> left);
        postorder(root -> right);
        cout << root -> data << " ";
}

void preorder(tn *root)
{
    if(root != NULL)
    {
        cout << root -> data << " ";
        preorder(root -> left);
        preorder(root -> right);
    }
}

void inorder(tn *root)
{
    if(root != NULL)
    {
        inorder(root -> left);
        cout << root -> data << " ";
        ::array[i++] = root -> data; // To store all elements in array to make it easier for searching
        inorder(root -> right);
    }
}

tn *insert(tn *node, int x)
{
    if(node == NULL)
    {
        return newNode(x);
    }
    if(x == node -> data)
    {
        return node;
    }
    else
    {
        if(x < (node -> data))
        {
            node->left = insert(node -> left, x);
        }
        else
        {
            node->right = insert(node -> right, x);
        }
        cout << "Inserting " << x << " in BST\n";
        return node;
    }
}

void search(int x)
{
    bool result;
    for(int t = 0; t < i; t++)
    {
        if(x == ::array[t])
            result = 1;
    }
    if(result == 1)
        cout << "Element found";
    else
        cout << "Element not found";
    cout << endl;
}

tn * minVal(tn *node) 
{ 
    tn *current = node;
    while (current -> left != NULL)
        current = current->left;
    return current;
}

tn *deleteNode(tn *root, int key)
{
    if (root == NULL)
        return root;
    if (key < root -> data)
        root->left = deleteNode(root->left, key);
    else if (key > root -> data)
        root->right = deleteNode(root->right, key);
    else
    {
        if (root -> left == NULL)
        {
            tn *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            tn *temp = root->left;
            free(root);
            return temp;
        }

        tn *temp = minVal(root->right);
        root -> data = temp -> data;
        root -> right = deleteNode(root -> right, temp -> data);
    }
    return root;
}

int main()
{
    tn *root = NULL;
    int choice, y;
    while(1)
    {
        cout << "\n~~~>>>Operations on Binary Search Tree (BST)<<<~~~\n\t1. Create a BST and insert nodes\n\t2. Traverse the BST in Inorder, Preorder and Postorder\n\t3. Search a key\n\t4. Delete an element\n\t5. Exit\nEnter your choice : ";
        cin >> choice;
        cout << endl;
        switch(choice)
        {
            case 1:
                cout << "Inserting given nodes in BST : 6, 9, 5, 2, 8, 15, 24, 14, 7, 8, 5, 2\n";
                root = insert(root, 6);
                root = insert(root, 9);
                root = insert(root, 5);
                root = insert(root, 2);
                root = insert(root, 8);
                root = insert(root, 15);
                root = insert(root, 24);
                root = insert(root, 14);
                root = insert(root, 7);
                root = insert(root, 8);
                root = insert(root, 5);
                root = insert(root, 2);
                break;
            case 2:
                cout << "\nInorder traversal of the tree is : ";
                inorder(root);
                cout << "\nPreorder traversal of the tree is : ";
                preorder(root);
                cout << "\nPostorder traversal of the tree is : ";
                postorder(root);
                cout << endl;
                break;
            case 3:
                cout << "\nEnter any element to search : ";
                cin >> y;
                search(y);
                break;
            case 4:
                cout << "\nEnter an element to delete : ";
                cin >> y;
                root = deleteNode(root , y);
                cout << "Deleted " << y << " from BST" << endl;
                break;
            case 5:
                cout << "\nExiting program... Thank You";
                exit (0);
                break;
            default:
                cout << "\nWrong input... Please enter again\n";
                break;
        }
    }
    return 0; 
}