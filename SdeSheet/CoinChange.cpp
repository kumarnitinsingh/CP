// Created by Nitin kumar singh
// problem link ->  https://practice.geeksforgeeks.org/problems/number-of-coins1824/1#

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


 int minCoins(int coins[], int M, int V) 
	{ 
	    // Your code goes here
	       int dp[M+1][V+1];
	      for(int i=0;i<=M;i++)dp[i][0]=0;
	      for(int j=0;j<=V;j++)dp[0][j]=INT_MAX-1;
	      
	      for(int i=1;i<=M;i++){
	          for(int j=1;j<=V;j++){
	              
	              if(coins[i-1]<=j){
	                  dp[i][j]=min(1+dp[i][j-coins[i-1]],dp[i-1][j]);
	              }
	              else dp[i][j]=dp[i-1][j];
	          }
	      }
	      
	      if(dp[M][V]==INT_MAX or dp[M][V]==INT_MAX-1)return-1;
	      return dp[M][V];
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