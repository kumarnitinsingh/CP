// Created by Nitin kumar singh
// problem link -> https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/

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
	freopen("output3.txt", "w", stdout);
#endif
}


class Solution {
public:
	int longestSubarray(vector<int>& nums, int limit) {
		int ans = 0;
		int n = nums.size();
		int i = 0; int j = 0;
		map<int, int>mp;

		while (j < n) {
			mp[nums[j]]++;
			int mini = mp.begin()->first;
			int maxi = mp.rbegin()->first;
			while (i < n and abs(maxi - mini) > limit) {
				mp[nums[i]]--;
				if (mp[nums[i]] == 0) {
					mp.erase(nums[i]);
				}
				mini = mp.begin()->first;
				maxi = mp.rbegin()->first;
				i++;
			}

			ans = max(ans, j - i + 1);
			j++;
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