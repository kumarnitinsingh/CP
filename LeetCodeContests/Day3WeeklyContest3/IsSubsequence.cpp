// Created by Nitin kumar singh
// problem link -> https://leetcode.com/problems/is-subsequence/

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



void init_code(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
}

int solve(string s,string t,int i,int j,vector<vector<int>>&dp){
    if(i==s.size() or j==t.size())return dp[i][j]=0;
    
    if(dp[i][j]!=-1)return dp[i][j];
    if(s[i]==s[j]){
        return dp[i][j]=1+solve(s,t,i+1,j+1,dp);
    }
    return  dp[i][j]=max(solve(s,t,i+1,j,dp) ,solve(s,t,i,j+1,dp));
}


    bool isSubsequence(string s, string t) {
        int n=s.size(),m=t.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        solve(s,t,0,0,dp);
        string str="";
        
        int i=n,j=m;
        while(i>0 and j>0){
            if(s[i-1]==t[j-1]){
                str=str+s[i-1];
                i--;j--;
                continue;
            }
            else if(dp[i-1][j]>dp[i][j-1]){
                i--;
            }
            else j--;
        }
        reverse(str.begin(),str.end());
        return str==s;
    }


int main(int argc, char const *argv[])
{
     clock_t start=clock();
     init_code();
    
     //write your code here





   
    #ifndef  ONLINE_JUDGE
     clock_t end=clock();
    cout<<"\n\n\n\nExecuted in: "<<double(end-start)/(CLOCKS_PER_SEC*1000)<<" ms"<<endl;
    #endif
   return 0;
}