#include <bits/stdc++.h>
using namespace std;

vector<string> split_string(string);

void plusMinus(vector<int> arr)
{
    float countPos = 0.0, countNeg = 0.0, countZero = 0.0;
    int size = arr.size();
    for (int i = 0; i < size; i++)
    {
        if (arr[i] < 0)
            countNeg++;
        else if (arr[i] > 0)
            countPos++;
        else if (arr[i] == 0)
            countZero++;
    }
    cout << setprecision(6) << fixed;
    cout << countPos / size << endl;
    cout << countNeg / size << endl;
    cout << countZero / size << endl;
}

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    plusMinus(arr);

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}