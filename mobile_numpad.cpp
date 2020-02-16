#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    map<string, char> m;
    map<int, int> num;
    for(int i = 2; i < 10; i++)
    {
        num[i] = 3;
    }
    num[6] = 4;
    num[9] = 4;

    m["1"] = ' ';
    char c = 'a';
    for(int i = 2; i < 10; i++)
    {
        string s = "";
        for(int j = 0; j < num[i]; j++)
        {
            s += to_string(i);
            m[s] = c;
            c++;
        }
    }

    for(auto it : m)
    {
        cout << it.first << " " << it.second << endl;
    }


    return 0;
}