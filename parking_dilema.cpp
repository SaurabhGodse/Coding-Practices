#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v = {2, 10, 8, 17};
    sort(v.begin(), v.end());
    int n = v.size();
    int res = v[2] - v[0] + 1;
    for(int i = 1; i < n - 2; i++)
    {
        int temp = v[i + 2] - v[i] + 1;
        if(temp < res)
        {
            res = temp;
        }
    }
    cout << res << endl;

}
