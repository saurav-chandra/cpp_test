#include<bits/stdc++.h>
using namespace std;

int main()
{
    char *a[] = {"ice", "green", "cone", "please"};
    char **p[] = {a+3, a+2, a+1, a};
    char ***ptr = p;
    cout << **++ptr << endl;
    //++ptr will go to a+2 and then ** will print whole "cone"....... ptr is at a+2
    cout << *--*++ptr+3 << endl;
    //cout << (*(--(*(++ptr))))+3 << endl;   //both lines are equivalent, they both will print null or nothing from "ice", p+3 means null character after e in ice
    //++ptr will go to a+1 and * will anter and door of "green" and -- will get to door of "ice" and * will get inside ice and +3 will print 4th digit, which is null in this case
    //... ptr is at a+1
    cout << *ptr[-2]+3 << endl;
    //ptr will go -2 from a+1, which is a+3 and enter.. after that * will get inside "please" and +3 means starting from 4th character "ase"
    //.... ptr is still at a+1
    cout << ptr[-1][-1]+1 << endl;
    //[-1] will get inside a+2 means at door of "cone" and again [-1] means door of "green" and inside it... and +1 will read 2nd character and print full means "reen"
}