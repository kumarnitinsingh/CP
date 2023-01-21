// Created by Nitin kumar singh
// problem link -> https://leetcode.com/problems/search-suggestions-system/description/

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


class node {
public:
	char data;
	unordered_map<char, node*>mp;
	bool isterminal;
	node(char data) {
		this->data = data;
		isterminal = false;
	}
};

class trie {
public:
	node* root;
	trie() {
		root = new node('\0');
	}

	void insert(string& s) {
		node* temp = root;

		for (auto ch : s) {
			if (temp->mp.count(ch)) {
				temp = temp->mp[ch];
			}
			else {
				node *k = new node(ch);
				temp->mp[ch] = k;
				temp = k;
			}
		}
		temp->isterminal = true;
	}
	bool isMatching(string &s, int n) {
		node* temp = root;
		int f = 0;
		for (auto ch : s) {
			if (temp->mp.count(ch)) {
				f++;
				temp = temp->mp[ch];
			}
			else break;

		}
		return f == n;
	}
};



class Solution {
public:
	vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
		vector<vector<string>>ans;
		trie *t = new trie();
		int n = searchWord.size();
		for (int i = 0; i < n; i++) {
			string str = searchWord.substr(0, i + 1);
			t->insert(str);
			vector<string>temp;
			for (auto w : products) {

				if (t->isMatching(w, i + 1)) {
					temp.push_back(w);
				}
			}
			sort(temp.begin(), temp.end());
			int sz = temp.size();
			vector<string>p;
			for (int k = 0; k < min(sz, 3); k++) {
				p.push_back(temp[k]);
			}
			ans.push_back(p);

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