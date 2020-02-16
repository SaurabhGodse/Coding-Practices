#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    // vector<string> inp = {"code", "doce", "ecod", "framer", "frame"};
    // set<string> s;
    // set<string> res;
    // vector<int> ans;

    // for(int i = 0; i < 5; i++)
    // {
    //     string str = inp[i];
    //     sort(str.begin(), str.end());
    //     if(s.find(str) == s.end())
    //     {
    //         s.insert(str);
    //         ans.push_back(i);
    //         res.insert(inp[i]);
    //     }
    // }
    // for(auto s: res)
    // {
    //     cout << s << endl;
    // }
    
    vector<int> ans = {20, 40 , 3, 56, 11, 390, 10, 23};
    sort(ans.begin(), ans.end());
    for(auto e : ans){
        cout<<e<<" ";
    }
    cout<<endl<<lower_bound(ans.begin(), ans.end(), 40) - ans.begin();
    cout<<endl<<upper_bound(ans.begin(), ans.end(), 40) - ans.begin()<<endl;
    return 0;
}