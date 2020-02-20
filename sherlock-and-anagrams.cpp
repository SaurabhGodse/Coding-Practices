#include <bits/stdc++.h>

using namespace std;

// function to check whether two strings are anagrams or not
bool isanagram(string str1, string str2)
{
	if(str1.size() != str2.size())
		return false;
    int freq1[26] = {0}, freq2[26] = {0};
    for(char c : str1)
    {
        freq1[c - 'a']++;
    }
    for(char c : str2)
    {
        freq2[c - 'a']++;
    }
    for(int i = 0; i < 26; i++)
    {
        if(freq1[i] != freq2[i])
            return false;
    }
    return true;
}

// Break this problem into two parts:
// 	1. Traverse all possible substrings within #include <string>
// 	2. Check if any two substrings of equal length are anagrams

int sherlockAndAnagrams(string s) {
    int count = 0;
    int n = s.size();
    string str1, str2;
    for(int len = 1; len < n; len++)
    {
        for(int i = 0; i < n - len; i++)
        {
            for(int j = i + 1; j < n - len + 1; j++)
            {
                str1 = s.substr(i, len);
                str2 = s.substr(j, len);
                // cout << str1 << " " << str2 << endl;
                if(isanagram(str1, str2))
                    count++;

            }
        }
    }
    return count;

}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		string s;
		cin >> s;
		cout << sherlockAndAnagrams(s) << endl;
	}
	return 0;
}