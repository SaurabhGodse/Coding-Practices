#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the saveThePrisoner function below.
int saveThePrisoner(int n, int m, int s) {
    return ((m % n ? m % n : n) + s - 1) % n ? ((m % n ? m % n : n) + s - 1) % n : n;
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int m, n, s;
		cin >> m >> n >> s;
		cout << saveThePrisoner(m, n, s) << endl;
	}
}