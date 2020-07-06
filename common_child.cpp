#include<iostream>
#include <bits/stdc++.h>

using namespace std;

void lcs(vector<vector<int>>&dp, string s, string t, int m, int n){
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            if(s[i - 1] == t[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
            
        }
    }
}


int main(){
    string s, t;
    // cout << "Enter first string : ";
    cin >> s;
    // cout << endl << "Enter second string : ";
    cin >> t;
    int m = s.length();
    int n = t.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    lcs(dp, s, t, m, n);
    cout << dp[m][n];
    return 0;
}
