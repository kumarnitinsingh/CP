// Created by Nitin kumar singh
// problem link -> https://leetcode.com/problems/maximum-sum-circular-subarray/

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

class Solution {
public:
	int maxSubarraySumCircular(vector<int>& nums) {

		int n = nums.size();
		vector<int>temp(2 * n + 1, 0);

		int ans = nums[0];

		for (int i = 0; i < 2 * n; i++)temp[i + 1] = temp[i] + nums[i % n];
		int left = 0;
		int right = 1;
		deque<int>dq;
		dq.push_back(0);
		while (right <= 2 * n) {
			if (dq.front() < right - n)dq.pop_front();
			ans = max(ans, temp[right] - temp[dq.front()]);
			while (!dq.empty() and temp[right] <= temp[dq.back()])dq.pop_back();
			dq.push_back(right);
			right++;
		}
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