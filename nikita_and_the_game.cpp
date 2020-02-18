#include <bits/stdc++.h>
#include <numeric>

using namespace std;

vector<string> split_string(string);

int getscore(vector<int>& arr, int l, int r, vector<long> &presum)
{
    int size = r - l + 1;
    // cout << "l : " << l << " r : " << r << endl;
    if(size <= 1)
        return 0;
    long sum;
    if(l == 0)
        sum = presum[r];
    else
        sum = presum[r] - presum[l - 1];
    // for(int i = l; i <= r; i++)
    //     sum += arr[i];
    // cout << "sum : " << sum << endl;
    // cout << "l : " << l << " r : " << r << " sum : " << sum << endl;
    if(sum & 1)
        return 0;
    
    long halfsum = sum / 2;
    // cout << "half sum : " << halfsum << endl;
    long total = 0, index;
    for(int i = l; i <= r; i++)
    {
        total += arr[i];
        if(total >= halfsum)
        {
            index = i;
            break;
        }
    }
    if(total == halfsum)
    {
        int leftscore = getscore(arr, l, index, presum);
        int rightscore = getscore(arr, index + 1, r, presum);
        return 1 + max(leftscore, rightscore);
    }
    else
        return 0;


}
/*
 * Complete the arraySplitting function below.
 */
int arraySplitting(vector<int> arr) {
    int n = arr.size();
    vector<long> presum(n, 0);
    presum[0] = arr[0];
    for(int i = 1; i < n; i++)
        presum[i] = presum[i - 1] + arr[i];
    return getscore(arr, 0, n - 1, presum);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int arr_count;
        cin >> arr_count;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string arr_temp_temp;
        getline(cin, arr_temp_temp);

        vector<string> arr_temp = split_string(arr_temp_temp);

        vector<int> arr(arr_count);

        for (int arr_itr = 0; arr_itr < arr_count; arr_itr++) {
            int arr_item = stoi(arr_temp[arr_itr]);

            arr[arr_itr] = arr_item;
        }

        int result = arraySplitting(arr);

        fout << result << "\n";
    }

    fout.close();

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
