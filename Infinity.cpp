// Created by Infinity
// problem link ->

#include <bits/stdc++.h>

using namespace std;

#define ll             long long int
#define mod            1000000007
#define inf            1e18

void init_code() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}





int main()
{
	init_code();
	int n;
	cin >> n;
	vector<int>v(n);
	for (int i = 0; i < n; i++)cin >> v[i];
	vector<int>prefix, suffix(n);
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += v[i];
		prefix.push_back(sum / (i + 1));
	}

	sum = 0;
	int cn = 1;
	for (int i = n - 1; i >= 0; i--) {
		sum += v[i];
		suffix[i] = sum / cn;
		cn++;
	}
	for (int i = n - 1; i >= 0; i--)cout << suffix[i] << " " << endl;

	int mini = INT_MAX;
	int ans;
	for (int i = 0; i < n - 1; i++) {
		int p1 = prefix[i];
		int p2 = suffix[i + 1];
		int val = abs(p1 - p2);
		if (val < mini) {
			val = mini;
			ans = i;
		}
	}


	cout << ans << endl;


	return 0;
}