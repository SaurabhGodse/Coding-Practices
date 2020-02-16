#include<bits/stdc++.h>
using namespace std;

int caseno = 1;
int main()
{
    while(true)
    {
        int n;
        cin >> n;
        if(n == 0)
            break;
        int hiringcost, salary, severence;
        cin >> hiringcost >> salary >> severence;
        vector<int> employeereq(n + 1);
        employeereq[0] = 0;
        int i, j;
        for(i = 1; i < n + 1; i++)
        {
            cin >> employeereq[i];
        }
        int maxele = *max_element(employeereq.begin(), employeereq.end());
        vector<vector<long>> dp(n + 1, vector<long>(maxele + 1, INT_MAX));

        for(i = 1; i < n + 1; i++)
        {
            for(j = 1; j < maxele + 1; j++)
            {
                if(i == 1 && j >= employeereq[i])
                {
                    dp[i][j] = j * hiringcost + j * salary;
                }
                else
                {
                    if(j >= employeereq[i])
                    {
                        for(int k = 1; k < maxele + 1; k++)
                        {
                            dp[i][j] = min(dp[i][j], dp[i - 1][k] 
                            + hiringcost * max(0, j - k) 
                            + salary * j
                            + severence * max(0, k - j));
                        }
                    }
                }
                

            }
        }
        long ans = dp[n][employeereq[n]];
        for(j = employeereq[n] + 1; j < maxele + 1; j++)
        {
            ans = min(ans, dp[n][j]);
        }
        cout << "Case " << caseno << ", cost = $" << ans << endl;
        caseno++;
        // for(i = 0; i < n + 1; i++)
        // {
        //     for(j = 0; j < maxele + 1; j++)
        //     {
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }


    }
    return 0;
}