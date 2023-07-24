// Created by Nitin kumar singh
// problem link -> https://leetcode.com/problems/word-search-ii/description/

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
	string word;
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
			if (temp->mp.count(ch) == 0) {
				node* k = new node(ch);
				temp->mp[ch] = k;
				temp = k;
			}
			else temp = temp->mp[ch];
		}
		temp->isterminal = true;
		temp->word = s;
	}

	bool search(string & s) {
		node* temp = root;

		for (auto ch : s) {
			if (temp->mp.count(ch)) {
				temp = temp->mp[ch];
			}
			else return false;
		}
		return temp->isterminal;
	}

};

void dfs(vector<vector<char>>& board, int i, int j, node* t, vector<vector<int>>&visited, set<string>&st) {
	if (i<0 or j<0 or i >= board.size() or j >= board[0].size())return;

	char ch = board[i][j];
	t = t->mp[ch];
	if (visited[i][j] or !t)return;
	if (t->isterminal)st.insert(t->word);
	visited[i][j] = true;
	dfs(board, i + 1, j, t, visited, st);
	dfs(board, i - 1, j, t, visited, st);
	dfs(board, i, j + 1, t, visited, st);
	dfs(board, i, j - 1, t, visited, st);
	visited[i][j] = false;

	return;

}

class Solution {
public:
	vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
		set<string>st;
		trie * t = new trie();
		for (auto w : words) {
			t->insert(w);
		}
		vector<vector<int>>visited(board.size(), vector<int>(board[0].size(), 0));
		for (int i = 0; i < board.size(); i++) {
			for (int j = 0; j < board[0].size(); j++) {
				dfs(board, i, j, t->root, visited, st);
			}
		}
		vector<string>ans(st.begin(), st.end());
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