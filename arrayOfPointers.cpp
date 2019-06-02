#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a[] = {0,1,2,3,4,5};
    int *b[] = {a, a+1, a+2, a+3, a+4};
    cout << b << endl;
    cout << b+3 << endl;
    cout << *(b+3) << endl;
    cout << **(b+3) << endl;
    int **ptr = b;
    cout << ptr - b << *ptr - a << **ptr << endl;
    ptr++;
    cout << ptr - b << *ptr - a << **ptr << endl;
    *ptr++;
    cout << ptr - b << *ptr - a << **ptr << endl;
    (*ptr)++;
    cout << ptr - b << *ptr - a << **ptr << endl;
    ++*ptr;
    cout << ptr - b << *ptr - a << **ptr << endl;
    *((*ptr)++);
    cout << ptr - b << *ptr - a << **ptr << endl;
}