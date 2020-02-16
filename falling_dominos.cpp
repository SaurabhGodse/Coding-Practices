#include<bits/stdc++.h>
using namespace std;

bool comparator(pair<int, int> p1, pair<int, int> p2)
{
    if(p1.second == p2.second)
        return p1.first > p2.first;
    return p1.second < p2.second;
}
int main()
{
    int n;
    cin >> n;
    
    vector<int> x(n);
    vector<int> h(n);
    vector<pair<int, int>> dom;
    for(int i = 0; i < n; i++)
    {
        cin >> x[i] >> h[i];
    }
    cout << "input over" << endl;
    int i;
    for(i = 0; i < n; i++)
    {
        dom.push_back({x[i] - h[i], x[i]});
        dom.push_back({x[i], x[i] + h[i]});
    }
    cout << "dom created..." << endl;
    sort(dom.begin(), dom.end(), comparator);
    int count = 0;
    n = dom.size();
    i = 0;
    // for(auto t : dom)
    // {
    //     cout << t.first << " " << t.second << " upper bound : " << upper_bound(dom.begin(), dom.end(), t, comparator) - dom.begin() << endl;
    // }
    int right;
    while(i < n)
    {
        // left = dom[i].first;
        right = dom[i].second;
        cout << i << endl;
        count++;
        i++;
        while(i < n && dom[i].first <= right)i++;
        
    }
    cout << "count is : " << count << endl;
    // while(i < n)
    // {
    //     cout << i << endl;
    //     pair<int, int> curr = dom[i];
    //     count++;
    //     int idx = upper_bound(dom.begin(), dom.end(), curr, comparator) - dom.begin();
    //     // if(idx == n - 1)
    //         // break;
    //     if(dom[idx].first > curr.second)
    //         i = idx;
    //     else
    //     {
    //         while(dom[idx].first <= curr.second)
    //         {

    //             int temp = upper_bound(dom.begin(), dom.end(), dom[idx], comparator) - dom.begin();
    //             // cout << "dom idx : " << idx << " temp : " << temp << endl;
                
    //             if(temp != idx)
    //                 idx = temp;
    //             else
    //             {
    //                 i = n;
    //                 break;
    //             }
                
    //         }
    //         if(i < n)
    //             i = idx;

    //     }
        

    // }
    // cout << "count is : " << count << endl;



    

    return 0;
}