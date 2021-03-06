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

ll dp[1001][1001][11][2];
ll solve(string s,string t,ll sidx,ll tidx,ll rem,ll con){
    if(sidx==s.size() or tidx==t.size()){
        if(rem==0)return 0;
        else return INT_MIN;
    }
    if(rem==0)return 0;

    if(dp[sidx][tidx][rem][con]!=-1)return dp[sidx][tidx][rem][con];
    ll ans=INT_MIN;

     ans=max(ans,solve(s,t,sidx+1,tidx,rem-con,0));
     ans=max(ans,solve(s,t,sidx,tidx+1,rem-con,0));

    if(s[sidx]==t[tidx]){
        ans=max(ans,1+solve(s,t,sidx+1,tidx+1,rem,1));
        ans=max(ans,1+solve(s,t,sidx+1,tidx+1,rem-1,0));
    }
   
       
    
    return dp[sidx][tidx][rem][con]=ans;

}


int main(int argc, char const *argv[])
{
     clock_t start=clock();
     init_code();
    
     //write your code here
       memset(dp,-1,sizeof dp);
       ll n,m,k;
       cin>>n>>m>>k;
       string s,t;
       cin>>s>>t;
       ll ans=solve(s,t,0,0,k,0);
        cout<<ans<<endl;


   
    #ifndef  ONLINE_JUDGE
     clock_t end=clock();
    cout<<"\n\n\n\nExecuted in: "<<double(end-start)/(CLOCKS_PER_SEC*1000)<<" ms"<<endl;
    #endif
   return 0;
}