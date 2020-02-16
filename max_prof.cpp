#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr = {3, 4, 5, 3, 5, 2};
    int i;
    int n = arr.size();
    int max = arr[n - 1];
    int res = 0;
    for(i = n - 2; i >= 0; i--)
    {
        if(max < arr[i])
        {
            max = arr[i];
        }
        res += max - arr[i];

    }
    cout << res << endl;

    return 0;
}