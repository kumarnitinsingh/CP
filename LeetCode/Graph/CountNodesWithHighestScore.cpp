// Created by Nitin kumar singh
// problem link -> https://leetcode.com/problems/count-nodes-with-the-highest-score/description/

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

const int maxn = 1e5 + 1;
long subtree[maxn];
long ans[maxn];
void dfs(vector<int>Tree[], int src, int par) {
	subtree[src] = 1;
	for (auto child : Tree[src]) {
		if (child != par) {
			dfs(Tree, child, src);
			subtree[src] += subtree[child];
		}
	}
}

void dfs2(vector<int>Tree[], int src, int par, int total) {
	if (src == 0)ans[src] = 1;
	else  ans[src] = total - subtree[src];
	for (auto child : Tree[src]) {
		if (child != par) {
			ans[src] *= subtree[child];
			dfs2(Tree, child, src, total);
		}
	}
}

class Solution {
public:
	int countHighestScoreNodes(vector<int>& parents) {
		int n = parents.size();
		vector<int>Tree[n];
		for (int i = 1; i < n; i++)Tree[parents[i]].push_back(i);
		dfs(Tree, 0, -1);
		dfs2(Tree, 0, -1, n);
		long ans1 = 0;
		int fi = 0;
		for (int i = 0; i < n; i++) {
			if (ans1 < ans[i]) {
				ans1 = ans[i];

			}
		}
		for (int i = 0; i < n; i++) {
			if (ans1 == ans[i]) {
				fi++;

			}
		}
		return fi;

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