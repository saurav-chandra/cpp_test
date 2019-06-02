#include<bits/stdc++.h>
using namespace std;
#define MAX 10

int array[MAX];
int i = 0;
int y;

void convertToBinary(int x)
{
    ::array[i++] = x%2;
    x /= 2;
    //for(int z = 0; z < MAX; z++)
    //    cout << ::array[i-1];
    //cout << endl;
    if(x > 0)
        convertToBinary(x);
}

int consecutiveOnes(int arr[MAX])
{
    int count = 0, maximum = 0;
    for(int q = 0; q < MAX; q++)
    {
        if(arr[q] == 1)
        {
            count++;
        }
        else
        {
            if(maximum < count)
                maximum = count;
            count = 0;
        }
    }
return maximum;

}

int main()
{
    int n;
    cin >> n;
    convertToBinary(n);
    //for(int a = 0; a < MAX; a++)
    //    cout << ::array[a] << " ";
    cout << consecutiveOnes(::array);
}