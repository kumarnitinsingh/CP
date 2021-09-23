// Created by Nitin kumar singh
// problem link -> https://atcoder.jp/contests/dp/tasks/dp_e

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


ll solve(vector<ll>v,vector<ll>wt,ll W,ll n){
    //unordered_map<ll,ll>dp;
    vector<vector<ll>>dp(n+1,vector<ll>(100001,0));

    for(int i=1;i<=100000;i++){
        dp[1][i]=INT_MAX;
    }

     dp[1][0]=0;
     dp[1][v[0]]=wt[0];
     for(int i=2;i<=n;i++){
        for(int j=0;j<=100000;j++){
           dp[i][j]=dp[i-1][j];
           if(v[i-1]<=j){
            dp[i][j]=min(dp[i][j],dp[i-1][j-v[i-1]]+wt[i-1]);
           }
           
        }
     }
     ll ans=0;
     for(ll i=0;i<=100000;i++){
        if(dp[n][i]<=W)
          {ans=max(ans,i);}
     }
     return ans;
}


int main(int argc, char const *argv[])
{
     clock_t start=clock();
     init_code();
    
     //write your code here

     ll n,w;cin>>n>>w;
     vector<ll>v(n),wt(n);
     loop(i,n)cin>>wt[i]>>v[i];

     ll ans=solve(v,wt,w,n);
     cout<<ans<<endl;





   
    #ifndef  ONLINE_JUDGE
     clock_t end=clock();
    cout<<"\n\n\n\nExecuted in: "<<double(end-start)/(CLOCKS_PER_SEC*1000)<<" ms"<<endl;
    #endif
   return 0;
}