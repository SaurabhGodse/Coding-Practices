#include<bits/stdc++.h>
using namespace std;

bool isvalid(string str, map<char, int> &m, int n)
{
    
    
    if(n & 1)
    {
        int count = 0;
        for(char i = 'a'; i <= 'z'; i++)
        {
            if(m[i] & 1)
                count++;
        }
        if(count == 1)
            return true;
        return false;

    }
    else
    {
        int count = 0;
        for(char i = 'a'; i <= 'z'; i++)
        {
            if(m[i] & 1)
                count++;
        }
        if(count == 0)
            return true;
        return false;
        
    }
    
}

int countswaps(string str, int n, int start)
{
    if(n / 2 <= start)
        return 0;
    int i;
    char c = str[start];
    // string c1;
    // c1.push_back(c);
    int count;
    bool found = false;
    for(i = n - 1 - start; i > start; i--)
    {
        if(str[i] == c)
        {
            count = n - 1 - start - i;
            // cout << n - 1 - start << " " << i << endl;
            // str.erase(i, 1);
            // str.insert(n - 1 - start, c1);
            for(int j = i; j < n - 1 - start; j++)
            {
                str[j] = str[j + 1];
            }
            str[n - 1 - start] = c;
            found = true;
            break;
        }

    }
    if(!found)
    {
        count = (n - 1) / 2 - start;
        for(int j = start; j < (n - 1) / 2; j++)
        {
            str[j] = str[j + 1];
        }
        str[(n - 1) / 2] = c;
        return count + countswaps(str, n, start);
        // str.erase(start);
        // str.insert((n - 1) / 2, c1);

    }
    // cout << "start is : " << start << " string is : " << str << endl;
    
    return count + countswaps(str, n, start + 1);

    

}
int main()
{
    while(true)
    {
        string str;
        cin >> str;
        if(str == "0")
            break;
        map<char, int> m;
        int n = str.size();
        int i;
        
        for(i = 0; i < n; i++)
        {
            m[str[i]]++;
        }// cout << isvalid(str, m, n);
        if(isvalid(str, m, n))
        {
            cout << countswaps(str, n, 0) << endl;
            // if(n & 1)
            // {
            //     int c;
            //     for(i = 0; i < n; i++)
            //     {
            //         if(m[str[i]] & 1)
            //         {
            //             c = m[str[i]];
            //             break;
            //         }
            //     }
            //     if(c == 1)
            //     {

            //     }
            // }
        }
        else
        {
            cout << "impossible" << endl;
        }
        
    }

    // cout << isvalid("aab") << endl;
    // cout << isvalid("abc") << endl;
    // cout << isvalid("aabbcc") << endl;
    // cout << isvalid("abcdbda") << endl;

    // while(true)
    // {
    //     string str;
    //     cin >> str;
    //     if(str == "0")
    //         break;
    //     else
    //     {
            
    //     }
        
    // }
    return 0;
}