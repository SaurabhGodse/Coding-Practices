#include<iostream>
using namespace std;
#define ll long long

int main()
{
        int T;
        cin >> T;
        for(int x = 1; x <= T; x++)
        {
                ll n, m;
                cin >> n >> m;
                // cout << n << m;
                int i;
                ll nums[n];
                for(i = 0; i < n; i++)
                {
                        cin >> nums[i];
                }
                if(m == 0)
                {
                        int res = 0;
                        for(i = 0; i < n; i++)
                        {
                                res = res ^ nums[i];

                        }
                        cout << "Case #" << x << ": " << res << endl;
                        

                }
                else
                {
                        
                        
                        

                        // bool flag = false;
                        ll maximum = 0;
                        for(i = 0; i < n; i++)
                        {
                                if(nums[i] > maximum)
                                {
                                        maximum = nums[i];
                                }

                        }
                        // if(flag)
                        // {
                        //         cout << "Case #" << x << ": " << -1 << endl;

                        // }
                        // else
                        // {
                                
                        
                        

                        
                                ll bits = 0;
                                ll temp = max(m, maximum);
                                // cout << "temp is : " << temp;
                                while(temp > 0)
                                {

                                        temp = temp / 2;
                                        bits++;
                                }
                                // cout << "bits are : " << bits;
                                ll set_bits[bits] = {0};
                                ll mask = 1;
                                ll j = 0;
                                for(ll k = 0; k < bits; k++)
                                {
                                        // cout << "mask is : " << mask << "j : " << j << endl;
                                        for(i = 0; i < n; i++)
                                        {
                                                if(nums[i] & mask)
                                                        set_bits[j]++;
                                                

                                        }
                                        mask = mask << 1;
                                        j++;
                                }
                                // cout << mask << endl;
                                // for(i = 0; i < bits + 1; i++)
                                // {
                                //         cout << set_bits[i] << " ";
                                // }
                                mask = mask / 2;
                                // cout << "mask is : " << mask;
                                ll left, right;
                                for(i = bits - 1; i >= 0; i--)
                                {
                                        // cout << mask << " " << n << " " << set_bits[i] << endl;
                                        if(mask * (n - set_bits[i]) <= m)
                                        {
                                                left = mask;
                                                right = min(mask * 2, m);
                                                break;

                                        }
                                        mask = mask / 2;

                                }
                                // cout << "left is : " << left << " " << right << endl;
                                ll mid;
                                ll ans = -1;
                                while(left <= right)
                                {
                                        mid = left + (right - left) / 2;
                                        // cout << left << " " << mid << " " << right << endl;
                                        ll sum = 0;
                                        for(i = 0; i < n; i++)
                                        {
                                                sum += mid ^ nums[i];
                                        }
                                        if(sum <= m)
                                        {
                                                ans = mid;
                                                left = mid + 1;

                                        }
                                        else
                                        {
                                                right = mid - 1;
                                        }
                                        
                                }
                                cout << "Case #" << x << ": " << ans << endl;
                        }
                }
        // }
        return 0;

}