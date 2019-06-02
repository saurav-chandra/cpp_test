/*
24. Write a menu-driven program which will accept an array of 10 integer values and sort them with
f ollowing sorting algorithms: Insertion Sort, Selection Sort, Bubble Sort, Quick sort, Merge Sort,
Heap Sort, Bucket Sort, Radix Sort, and Shell Sort.
*/

#include<bits/stdc++.h>
using namespace std;

void insertion(int *a, int n)
{
    int i;
    for(i=2; i<=n; i++)
    {
    if(a[i] < a[i-1])
    {
    int x = a[i];
    int j = i-1;
    while(j >= 1 && a[j] > x)
    {
    a[j+1] = a[j];
    j--;
    }
    a[j+1] = x;
    }
    }
}

void selection(int *a, int n)
{
    int i, min, j;
    for(i = 1; i <= n; i++){
    min = i;
    for(j = i; j <= n; j++)
    if(a[j] < a[min])
    min = j;

    int temp = a[min];
    a[min] = a[i];
    a[i] = temp;
    }
}

void bubble(int *a, int n)
{
    int i, j;
    for(i=1; i<=n; i++){
    for(j=i+1; j<=n; j++){
    if(a[i] > a[j]){
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
    }
    }
    }
}

int partition(int *a, int p, int q)
{
    int pi = a[p], i, j=p;
    for(i=p+1; i<=q; i++){
    if(a[i] <= pi){
    j++;
    int temp = a[j];
    a[j] = a[i];
    a[i] = temp;
    }
    }
    int temp = a[p];
    a[p] = a[j];
    a[j] = temp;

    return j;
}

void quick_s(int *a, int p, int q)
{
    if(p >= q)
    return;

    int x = partition(a, p, q);
    quick_s(a, p, x-1);
    quick_s(a, x+1, q);
}

void merge(int *a, int p, int mid, int q)
{
    int b[p+q], i, k=1, k1=p, k2=mid+1;
    for(i=p; i<=q; i++){
    if(k1 == mid+1 || k2 == q+1)
    break;

    if(a[k1] <= a[k2]){
    b[k] = a[k1];
    k1++;
    }
    else{
    b[k] = a[k2];
    k2++;
    }
    k++;
    }

    if(k1 <= mid){
    for(k1; k1<=mid; k1++){
    b[k] = a[k1];
    k++;
    }
    }
    if(k2 <= q){
    for(k2; k2<=mid; k2++){
    b[k] = a[k2];
    k++;
    }
    }
    k--;
    for(i = 1; i<=k; i++)
    a[p+i-1] = b[i];

    return;
}

void merge_s(int *a, int p, int q)
{
    if(p>=q)
    return;

    int mid = (p+q)/2;
    merge_s(a, p, mid);
    merge_s(a, mid+1, q);
    merge(a, p, mid, q);
}

void heapify(int *a, int n, int i)
{
    int largest = i, left, right;
    left = 2*i;
    right = (2*i)+1;

    if(left<=n && a[largest]<a[left])
    largest = left;

    if(right<=n && a[largest]<a[right])
    largest = right;

    if(largest != i){
    int temp = a[largest];
    a[largest] = a[i];
    a[i] = temp;

    heapify(a, n, largest);
    }
}

void heap_sort(int *a, int p, int q)
{
    int i;
    for(i=(q/2); i>=1; i--)
    heapify(a, q, i);

    for(i=q; i>=1; i--){
    int temp = a[p];
    a[p] = a[i];
    a[i] = temp;

    heapify(a, i-1, 1);
    }
}

void bucket(int *a, int p, int q)
{
    int b[q][10], k[10], i, t, j, t1;
    for(i=1; i<=10; i++)
    k[i] = 0;

    for(i=p; i<=q; i++){
    t = (a[i]/q) + 1;
    k[t]++;
    t1 = k[t];
    b[t][t1] = a[i];
    }

    for(i=p; i<=q; i++){
    if(k[i] > 0){
    int c;
    for(c=2; c<=k[i]; c++){
    if(b[i][c] < b[i][c-1]){
    int x = b[i][c];
    int d = c-1;
    while(d >= 1 && b[i][d] > x){
    b[i][d+1] = b[i][d];
    d--;
    }
    b[i][d+1] = x;
    }
    }
    }
    }

    int ind = 1;
    for(i=p; i<=q; i++)
    if(k[i] != 0)
    for(j=1; j<=k[i]; j++){ 
    a[ind] = b[i][j];
    ind++;
    }
}

void count_sort(int *a, int p, int q, int r)
{
    int b[q], i, count[10];

    for(i=p; i<=10; i++)
    count[i] = 0;

    int t;
    for(i=p; i<=q; i++){
    t = a[i]/r;
    count[t%10]++;
    }

    for(i=p+1; i<=q; i++)
    count[i] += count[i-1];

    int c=0, l=0;
    for(i=p; i<=q; i++){
    t = a[i]/r;
    l = count[t%10];
    b[l] = a[i];
    count[t%10]--;
    }

    for(i=p; i<=q; i++)
    a[i] = b[i];
    }

void radix(int *a, int p, int q)
{
    int i, max=0;
    for(i=p; i<=q; i++)
    if(a[i]>max)
    max = a[i];

    for(i = 1; max/i > 0; i*=10){
    count_sort(a, p, q, i);
    }
}

void shell(int *a, int p, int q)
{
    for(int i=q/2; i>0; i/=2){
    for(int j=i; j<=q; j++){
    int temp = a[j];
    int k;
    for(k=j; k>=i && a[k-i+1]>temp; k-=i)
    a[k] = a[k-i];

    a[k] = temp;
    }
    }
}

void displayArray(int A[],  int n)
{
    for(int i = 1 ; i <= n; i++)
        cout << A[i] <<" ";
}

int main()
{
    int A[10];// = {1,85,6,75,9,13,36,19,20,17};
    int n = sizeof(A)/sizeof(A[0]);
    int choice, i;
    cout << n << endl;
    
    cout<<"Enter 10 elements: "<<endl;
    for(i = 1; i <= 10; i++)
    {
        cout<< i <<": ";
        cin>>A[i];
    }
    cout << "\t~~~>>>SORTING<<<~~~\nArray Before Sorting : \n";
    displayArray(A, 10);

    {
        cout << "\nChoose how to Sort : \n\t1. Insertion Sort\n\t2. Selection Sort\n\t3. Bubble Sort\n\t4. Quick Sort\n\t5. Merge Sort\n\t6. Heap Sort\n\t7. Bucket Sort\n\t8. Radix Sort\n\t9. Shell Sort\n\t10. Exit\nEnter your choice : ";
        cin >> choice;
        cout << endl;
        switch(choice)
        {
            case 1:
                cout << "Insertion Sort\n";
                insertion(A, 10);
                break;
            case 2:
                cout << "Selection Sort\n";
                selection(A, n);
                break;
            case 3:
                cout << "Bubble Sort\n";
                bubble(A, n);
                break;
            case 4:
                cout << "Quick Sort\n";
                quick_s(A, 1, n);
                break;
            case 5:
                cout << "Merge Sort\n";
                merge_s(A, 1, n);
                break;
            case 6:
                cout << "Heap Sort\n";
                heap_sort(A, 1, n);
                break;
            case 7:
                cout << "Bucket Sort\n";
                bucket(A, 1, n);
                break;
            case 8:
                cout << "Radix Sort\n";
                radix(A, 1, n);
                break;
            case 9:
                cout << "Shell Sort\n";
                shell(A, 1, n);
                break;
            case 10:
                cout << "Exiting Program\n";
                exit (0);
            default:
                cout << "Wrong input, try again\n";
                break;
        }
        cout << "Array After Sorting : ";
        displayArray(A, 10);
        cout << endl;
    }

}