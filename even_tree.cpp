#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &adj, vector<int> &freq, vector<bool> &visited, int node)
{
    // cout<<"CAlling "<<node<<endl;
    visited[node] = true;
    // int sum = 0;
    // cout << node << endl;
    for(auto i : adj[node])
    {
        if(visited[i]){
            continue;
        }
        // cout<<"CAlling "<<i<<" from "<<node<<endl;
        dfs(adj, freq, visited, i);
        // cout << node << " : " << i << endl;
        freq[node] += freq[i];
    }
    // freq[node] += sum;
    // return 1+sum;
}

void countedges(vector<vector<int>> &adj, vector<int> &freq, vector<bool> &visited, int node, int &count)
{
    // if(visited[node])
    //     return;
    visited[node] = true;
    for(auto i : adj[node])
    {
        if(visited[i])continue;
        if(freq[node] % 2 == 0 && freq[i] % 2 == 0)
        {
            // cout << node << " : " << i << endl;
            count++;
        }
        countedges(adj, freq, visited, i, count);
    }

}
int main()
{
    int n, e;
    cin >> n >> e;
    vector<vector<int>> adj(n+1, vector<int>());
    for(int i = 0; i < e; i++)
    {
        int e1, e2;
        cin >> e1 >> e2;
        adj[e1].push_back(e2);
        adj[e2].push_back(e1);
    }
    vector<int> freq(n + 1, 1);
    // memset(freq, 1, sizeof(freq));
    // for(auto f : freq)
    // {
    //     cout << f << " ";
    // }
    vector<bool> visited(n + 1, false);
    // memset(visited, false, sizeof(visited));

    dfs(adj, freq, visited, 1);

    // for(auto f : freq)
    // {
    //     cout << f << " ";
    // }
    // cout << endl;

    // visited.resize(11, false);
    for(int i = 0; i < visited.size(); i++)
        visited[i] = false;
    // for(auto i : visited)
    //     cout << i << " ";
    // memset(visited, false, sizeof(visited));
    int count = 0;
    countedges(adj, freq, visited, 1, count);
    cout << count << endl;


    return 0;

}