#include<bits/stdc++.h>
using namespace std;



vector<int> parent_node(vector<int> U, vector<char> val, vector<int> V)
{


}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<char> val(n);
        for(int i = 0; i < n; i++)
        {
            cin >> val[i];
        }
        vector<int> U;
        vector<int> V;
        vector<vector<int>> adj(n, vector<int>());

        for(int i = 0; i < n - 1; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u - 1].push_back(v - 1);
            adj[v - 1].push_back(u - 1);
        }
        

    }
    return 0;
}