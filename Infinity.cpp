// Created by Nitin kumar singh
// problem link ->

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

const int maxn = 2e5 + 1;

int dp[maxn][2];

void dfs(vector<int>tree[], int src, int par) {
	int f = 0;
	for (auto child : tree[src]) {
		if (child != par) {
			f = 1;
			dfs(tree, child, src);
		}
	}
	if (f == 0)return;
	vector<int>prefix, suffix;
	for (auto child : tree[src]) {
		if (child != par) {
			prefix.push_back(max(dp[child][0], dp[child][1]));
			suffix.push_back(max(dp[child][0], dp[child][1]));
		}
	}

	for (int i = 1; i < prefix.size(); i++)prefix[i] += prefix[i - 1];
	for (int i = suffix.size() - 2; i >= 0; i--)suffix[i] += suffix[i + 1];
	dp[src][0] = suffix[0];
	int child_no = 0;

	for (auto child : tree[src]) {
		if (child == par) continue;
		int left = child_no == 0 ? 0 : prefix[child_no - 1];
		int right = child_no == suffix.size() - 1 ? 0 : suffix[child_no + 1];
		dp[src][1] = max(dp[src][1], 1 + left + right + dp[child][0]);
		child_no++;

	}

}



int main(int argc, char const *argv[])
{
	//clock_t start=clock();
	init_code();
	memset(dp, 0, sizeof dp);
	int n;
	cin >> n;
	vector<int>tree[n + 1];
	for (int i = 1; i < n ; i++) {
		int x, y; cin >> x >> y;
		tree[x].push_back(y);
		//tree[y].push_back(x);
	}


	dfs(tree, 1, -1);

	cout << max(dp[1][0], dp[1][1]);






	/*
	 #ifndef  ONLINE_JUDGE
	  clock_t end=clock();
	 cout<<"\n\n\n\nExecuted in: "<<double(end-start)/(CLOCKS_PER_SEC*1000)<<" ms"<<endl;
	 #endif
	 */
	return 0;
}