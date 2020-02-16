#include<bits/stdc++.h>
using namespace std;

bool comparator(vector<int> a, vector<int> b)
{
    return a[2] < b[2];
}

int find(int p, int parent[])
{
    while(parent[p] != p)
    {
        parent[p] = parent[parent[p]];
        p = parent[p];
    }
    return p;
}
void unionall(int p, int q, int parent[])
{
    int pp = find(p, parent);
    int pq = find(q, parent);
    parent[pp] = parent[pq];
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj;
    int parent[n + 1];
    int i,j;
    for(i = 0; i <= n; i++)
    {
        parent[i] = i;
    }
    for(j = 0; j < m; j++)
    {
        vector<int> temp(3, 0);
        cin >> temp[0] >> temp[1] >> temp[2];
        adj.push_back(temp);
    }
    sort(adj.begin(), adj.end(), comparator);
    int count = 0;
    int sum = 0;
    for(i = 0; i < m; i++)
    {
        if(count == n - 1)
            break;
        vector<int> edge = adj[i];
        if(find(edge[0], parent) != find(edge[1], parent))
        {
            unionall(edge[0], edge[1], parent);
            count++;
            sum += edge[2];
        }
    }
    cout << sum << endl;
    return 0;

    
}