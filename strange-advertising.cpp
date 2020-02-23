#include <bits/stdc++.h>

using namespace std;

// Complete the viralAdvertising function below.
int viralAdvertising(int n) {
    int liked = 2, cumulative = 2, day = 1, shared = 5;
    while(day < n)
    {
        shared = liked * 3;
        liked = shared / 2;
        cumulative += liked;
        day++;
    }
    return cumulative;


}

int main()
{
	int n;
	cin >> n;
	cout << viralAdvertising(n) << endl;
	return 0;

}