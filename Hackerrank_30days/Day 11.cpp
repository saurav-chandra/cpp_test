#include <bits/stdc++.h>
using namespace std;

const int r = 6, c = 6;
int hourglass(int array[r][c])
{
    if(r < 3 || c < 3)
        return -1;

    int i, j, maxSum = INT_MIN, sum;
    //if(r < 4 || c < 4)
    {
        for(i = 0; i < r - 2; i++)
        {
            for(j = 0; j < c - 2; j++)
            {
                sum = (array[i][j]+array[i][j+1]+array[i][j+2]) + (array[i+1][j+1]) + (array[i+2][j]+array[i+2][j+1]+array[i+2][j+2]);
                maxSum = max(maxSum, sum);
            }
        }
    }
return maxSum;
}


int main()
{
    //vector<vector<int>> arr(6);
    int arr[r][c];
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
            cin >> arr[i][j];
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    int result = hourglass(arr);
    if(result == -1)
        cout << "not possible";
    else
        cout << result;
    return 0;
}