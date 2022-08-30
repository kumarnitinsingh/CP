// Created by Nitin kumar singh
// problem link -> https://leetcode.com/problems/egg-drop-with-2-eggs-and-n-floors/

#include <bits/stdc++.h>

//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
//#include<ext/pb_ds/trie_policy.hpp>

using namespace std;

//using namespace __gnu_pbds;
//typedef tree <int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>Set;

//find_by_order(k) and order_of_key(k)



#define ll             long long int
#define ld             long double
#define mod            1000000007
#define inf            1e18
#define vecl            vector<long long>
#define vect           vector<vector<long long>>
#define vecb           vector<vector<bool>>
#define pb             push_back
#define all(n)         n.begin(),n.end()
#define loop(i,n)      for(int i=0;i<(n);++i)
#define loopa(i,a,n)    for(int i=a;i<=(n);++i)
#define loopr(i,a,n)   for(int i=a;i>=(n);--i)
#define sq(x)          x*x
#define cube(x)        x*x*x
#define endl           "\n"


void init_code() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

int dp[1001][3];
int solve(int n, int k) {
	if (n == 0 or n == 1)return n;
	if (k == 1)return n;


	if (dp[n][k] != -1)return dp[n][k];
	int ans = INT_MAX;
	for (int f = 1; f <= n; f++) {
		int op1 = 1 + solve(n - f, k);
		int op2 = 1 + solve(f - 1, k - 1);
		ans = min(ans, max(op1, op2));
	}
	return dp[n][k] = ans;
}
class Solution {
public:
	int twoEggDrop(int n) {
		memset(dp, -1, sizeof dp);
		int ans = solve(n, 2);
		return ans;
	}
};



int main(int argc, char const *argv[])
{
	//clock_t start=clock();
	init_code();






	/*
	 #ifndef  ONLINE_JUDGE
	  clock_t end=clock();
	 cout<<"\n\n\n\nExecuted in: "<<double(end-start)/(CLOCKS_PER_SEC*1000)<<" ms"<<endl;
	 #endif
	 */
	return 0;
}