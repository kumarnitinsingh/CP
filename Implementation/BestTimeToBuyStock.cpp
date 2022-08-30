// Created by Nitin kumar singh
#include <bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
//#include<ext/pb_ds/trie_policy.hpp>


//using namespace_-gnu_pbds;
using namespace std;

#define ll             long long int
#define ld             long double
#define mod            1000000007
#define inf            1e18
#define vec            vector<long long>
#define vect           vector<vector<long long>>
#define vecb           vector<vector<bool>
#define pb             push_back
#define all(n)         n.begin(),n.end()
#define loop(i,n)      for(int i=0;i<(n);++i)
#define loopa(i,a,n)    for(int i=a;i<=(n);++i)
#define loopr(i,a,n)   for(int i=a;i>=(n);--i)
#define sq(x)          x*x
#define cube(x)        x*x*x



void init_code() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

class node {
public:
	ll low;
	ll high;
	ll sum;
};

node FindMaxCrossingSum(vector<ll>v, ll low, ll mid, ll high) {
	ll leftSum = -inf;
	ll maxLeft = low;
	ll sum = 0;
	for (ll i = mid; i >= low; i--) {
		sum += v[i];
		if (sum > leftSum) {
			leftSum = sum;
			maxLeft = i;
		}
	}

	ll rightSum = -inf;
	sum = 0;
	ll maxright = high;
	for (ll j = mid + 1; j <= high; j++) {
		sum += v[j];
		if (sum > rightSum) {
			rightSum = sum;
			maxright = j;
		}
	}

	node ans;
	ans.low = maxLeft;
	ans.high = maxright;
	ans.sum = leftSum + rightSum;

	return ans;
}

node Ans;
node FindMaximumSubarray(vector<ll>v, ll low, ll high) {
	//base case
	if (low == high) {
		Ans.low = low;
		Ans.high = high;
		Ans.sum = v[low];
		return Ans;
	}
	else {
		ll mid = (low + high) / 2;
		node left = FindMaximumSubarray(v, low, mid);
		node right = FindMaximumSubarray(v, mid + 1, high);
		node cross = FindMaxCrossingSum(v, low, mid, high);
		if (left.sum > right.sum and left.sum > cross.sum)return left;
		else if (right.sum > left.sum and right.sum > cross.sum)return right;
		return cross;

	}
}


int main(int argc, char const *argv[])
{
	clock_t start = clock();
	init_code();


	//write your code here

	ll n;
	cin >> n;
	vector<ll>v(n);
	for (ll i = 0; i < n; i++)cin >> v[i];
	vector<ll>a(n);
	for (ll i = 1; i < n; i++) {
		a[i] = v[i] - v[i - 1];
	}

	node Myans = FindMaximumSubarray(a, 1, n - 1);
	cout << Myans.low - 1 << " " << Myans.high << " " << Myans.sum << " ";




#ifndef  ONLINE_JUDGE
	clock_t end = clock();
	cout << "\n\n\n\nExecuted in: " << double(end - start) / (CLOCKS_PER_SEC * 1000) << " ms" << endl;
#endif
	return 0;
}