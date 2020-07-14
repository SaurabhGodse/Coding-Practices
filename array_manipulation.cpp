#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main(){
	int n, m;
	cin >> n >> m;
	vector<long> arr(n + 1, 0);
	while(m--){
		int a, b, k;
		cin >> a >> b >> k;
		arr[a] += k;
		if(b + 1 <= n)
			arr[b + 1] -= k;
	}
	long max = 0;
	long x = 0;
	for(int i = 0; i < n + 1; i++){
		x += arr[i];
		if(x > max)
			max = x;
	}
	cout << max;
	return 0;
}