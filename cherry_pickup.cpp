#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

int solve(vector<vector<int>> &grid, vector<vector<vector<int>>> &dp, int r1, int c1, int c2, int n)
{
    int r2 = r1 + c1 - c2;
    if(n == r1 || n == r2 || n == c1 || n == c2 || grid[r1][c1] == -1 || grid[r2][c2] == -1)
        return INT_MIN;
    else if(r1 == n - 1 && c1 == n - 1)
        return grid[r1][c1];
    else if(dp[r1][c1][c2] != -1)
        return dp[r1][c1][c2];
    else
    {
        int ans = grid[r1][c1] + (c1  != c2) * grid[r2][c2];
        ans += max(
            max(
                solve(grid, dp, r1 + 1, c1, c2, n),solve(grid, dp, r1, c1 + 1, c2, n)
            ),
            max(
                solve(grid, dp, r1 + 1, c1, c2 + 1, n),solve(grid, dp, r1, c1 + 1, c2 + 1, n)
            )
        );
        dp[r1][c1][c2] = ans;
        return ans;
    }
}
int cherryPickup(vector<vector<int>>& grid) {
    int n = grid.size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(n, -1)));
    return max(0, solve(grid, dp, 0, 0, 0, n));
    
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> grid;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
        }
    }
    cout << "Result : " << cherryPickup(grid) << endl;
    return 0;
}