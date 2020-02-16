#include<bits/stdc++.h>
using namespace std;

void sieve(int n, int g, vector<int> &s)
{
    int i = g + 1;
    while(i <= n)
    {
        int minele = INT_MAX;
        for(int j = i; j < n + 1; j += i)
        {
            minele = min(minele, s[j]);
        }
        for(int j = i; j < n + 1; j += i)
            s[j] = minele;
        i++;
    }
}
vector <int> connectedCities(int n, int g, vector <int> originCities, vector <int> destinationCities) {
    // Complete this function
    vector<int> s(n + 1);
    for(int i = 0; i < n + 1; i++)
    {
        s[i] = i;
    }
    sieve(n, g, s);
    int k = originCities.size();
    vector<int> res;
    for(int i = 0; i < k; i++)
    {
        int a = originCities[i];
        int b = destinationCities[i];
        if(a <= g || b <= g || s[a] != s[b])
        {
            res.push_back(0);
            // continue;
        }
        else
        {
            res.push_back(1);
        }
    }
    return res;
        
}

int main()
{
    return 0;
}