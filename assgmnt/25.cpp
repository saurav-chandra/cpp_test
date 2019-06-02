/*
25. Write a menu-driven program which will accept an array of 10 integer values and search an
elements within the array using f ollowing searching algorithms: Linear Search, Iterative Binary
Search, Recursive Binary Search, Interpolation Search and Exponential Search.
*/

#include <bits/stdc++.h>
using namespace std;

int linearSearch(int A[], int n, int x)
{
    int result, i;
    for(i = 0; i < n; i++)
    {
        if(x == A[i])
        {
            result = 1;
            return i;
        }
    }
    return -1;
}

int iterativeBinary(int A[], int N, int x)
{
    int low = 0, high = N - 1;
    while (low <= high)
    {
        int mid = (low + high)/2;
        if (x == A[mid])
            return mid;
        else if (x < A[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

int recursiveSearch(int A[], int low, int high, int x)
{
    if (low > high)
        return -1;
    int mid = (low + high)/2;
    if (x == A[mid])
        return mid;
    else if (x < A[mid])
        return recursiveSearch(A, low,  mid - 1, x);
    else
        return recursiveSearch(A, mid + 1,  high, x);
}

int interpolationSearch(int A[], int n, int x) 
{
    int low = 0, high = (n - 1); 
    while (low <= high && x >= A[low] && x <= A[high]) 
    { 
        int pos = low + (((double)(high-low) / 
              (A[high]-A[low]))*(x - A[low])); 
        if (A[pos] == x) 
            return pos; 
        if (A[pos] < x) 
            low = pos + 1; 
        else
            high = pos - 1; 
    } 
    return -1; 
} 

int exponentialSearch(int A[], int n, int x) 
{ 
    if (A[0] == x) 
        return 0; 
    int i = 1; 
    while (i < n && A[i] <= x) 
        i = i*2; 
    return recursiveSearch(A, i/2, min(i, n), x); 
}

int main()
{
    int A[] = {1,85,6,75,9,13,36,19,20,17};
    int target, index, choice;
    int n = sizeof(A)/sizeof(A[0]);
    int low = 0, high = n - 1;
    sort(A, A+n);
    cout << "\t~~~>>>SEARCHING<<<~~~\nArray : ";
    for(int i = 0 ; i < n; i++)
    {
        cout << A[i] <<" ";
    }
    cout << "\nEnter element to search : ";
    cin >> target;

    //while(1)
    {
        cout << "\nChoose how to search : "<< target << "\n\t1. Linear Search\n\t2. Iterative Binary Search\n\t3. Recursive Binary Search\n\t4. Interpolation Search\n\t5. Exponential Search\n\t6. Exit\nEnter your choice : ";
        cin >> choice;
        cout << endl;
        switch(choice)
        {
            case 1:
                cout << "Linear Search\n";
                index = linearSearch(A, n, target);
                break;
            case 2:
                cout << "Iterative Binary Search\n";
                index = iterativeBinary(A, n, target);
                break;
            case 3:
                cout << "Recursive Binary Search\n";
                index = recursiveSearch(A, low, high, target);
                break;
            case 4:
                cout << "Interpolation Search\n";
                index = interpolationSearch(A, n, target);
                break;
            case 5:
                cout << "Exponential Search\n";
                index = exponentialSearch(A, n, target);
                break;
            case 6:
                cout << "Exiting Program\n";
                exit (0);
            default:
                cout << "Wrong input, try again\n";
                break;
        }
        if (index != -1)
            cout << "Element found at index : " << index << endl;
        else
            cout << "Element not found in the array" << endl;
    }
    return 0;
}