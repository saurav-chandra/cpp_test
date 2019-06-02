#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

class Difference {
    private:
    vector<int> elements;
  
  	public:
  	int maximumDifference;
    int size;

	// Add your code here
    Difference(vector<int> a)
    {
        elements = a;
        maximumDifference = 0;
        size = a.size();
        return;
    }

    void computeDifference()
    {
        int temp, temp1, temp2;
        for(int i = 0; i < size; i++)
        {
            for(int j = i+1; j < size; j++)
            {
                temp1 = elements[i];
                temp2 = elements[j];
                temp = temp1 - temp2;
                temp = abs(temp);
               // cout << temp << endl;
                maximumDifference = max(maximumDifference, temp);
                //if(maximumDifference < abs(elements[i]-elements[j]))
                 //   maximumDifference = abs(elements[i]-elements[j]);
            }
        }
    }

};
int main() {
    int N;
    cin >> N;
    
    vector<int> a;
    
    for (int i = 0; i < N; i++) {
        int e;
        cin >> e;
        
        a.push_back(e);
    }
    
    Difference d(a);
    
    d.computeDifference();
    
    cout << d.maximumDifference;
    
    return 0;
}