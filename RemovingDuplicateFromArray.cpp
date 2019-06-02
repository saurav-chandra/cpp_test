#include<bits/stdc++.h>
using namespace std;

int a[] = {1,2,5,2,1,4,7,8,9,2};
int size = sizeof(a)/sizeof(int);

void print()
{
    cout << "Array : ";
    for(int x=0; x < size ; x++)
    {
        cout << "|" << a[x];
    }
    cout << "|\n";
}

int main()
{
    int i, j;
    cout << "Initial ";
    print();
    for(i=0; i<size; i++)
    {
        for(j=i+1 ; j<size; j++)
        {
            if(a[i] == a[j])
            {
                cout << "\nDuplicate element detected : " << a[j] << " at position "<< j << endl ;
                for(int k = j; k < size ; k++)
                {
                    a[k] = a[k+1];
                    
                }
                size--;
                cout << "After removing Duplicate Element -> ";
                print();
            }
        }
    }
    cout << "\nFinal array after removing all duplicates -> ";
    print();
   /*
    printf("The repeating elements are: \n"); 
    for (i = 0; i < size; i++) 
    { 
        if (a[abs(a[i])] >= 0) 
        a[abs(a[i])] = -a[abs(a[i])]; 
        else
        printf(" %d ", abs(a[i]));
    }
    */
}