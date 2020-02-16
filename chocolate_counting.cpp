#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v{2, 4, 4, 5, 5, 5, 6, 6, 6, 6, 6, 6, 8, 8, 8, 8, 8, 9};
    
    vector<int> v1{2, 4, 5, 6, 7, 8, 9, 10};
    int n = v1.size();
    for(int i = 0; i < n; i++)
    {
        cout << "upper bound of : " << v1[i] << " is : " << upper_bound(v.begin(), v.end(), v1[i]) - v.begin() << endl;
        cout << "lower bound of : " << v1[i] << " is : " << lower_bound(v.begin(), v.end(), v1[i]) - v.begin() << endl;
    }
    return 0;
    
}