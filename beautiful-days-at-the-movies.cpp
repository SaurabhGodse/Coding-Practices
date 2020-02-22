#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

int reverse(int num)
{
    int revnum = 0, rem;
    while(num != 0)
    {
        rem = num % 10;
        num = num / 10;
        revnum = revnum * 10 + rem;
    }
    return revnum;
}
// Complete the beautifulDays function below.
int beautifulDays(int i, int j, int k) {
    int count = 0;
    for(int num = i; num <= j; num++)
    {
        if(abs(num - reverse(num)) % k == 0)
            count++;
    }
    return count;
}

int main()
{
	int i, j, k;
	cin >> i >> j >> k;
	cout << beautifulDays(i, j, k) << endl;
	return 0;

}