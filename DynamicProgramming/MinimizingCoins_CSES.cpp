// Created by Nitin kumar singh
// problem link -> https://cses.fi/problemset/task/1634
 
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
    freopen("output2.txt","w",stdout);
    #endif
}
 
 
 ll dp[100][100000];



ll solve(vector<ll>& v,ll i,ll x,ll sum){
     if(sum>x)return INT_MAX;

    if(sum==x)return 0;
    if(i==v.size())return INT_MAX;
   
    if(dp[i][sum]!=-1)return dp[i][sum];
    ll ans=INT_MAX;

    ll op1=1+solve(v,i,x,sum+v[i]);
    ll op2=solve(v,i+1,x,sum);

    ans=min(op1,op2);

    return dp[i][sum]=ans;

}

//space optimized
 
ll solution(vector<ll>&v,ll x){
    ll n=v.size();

    vector<ll>dp(x+1,INT_MAX);
    dp[0]=0;
    for(int j=1;j<=x;j++){
       for(int i=0;i<n;i++){
        if(j>=v[i]){
        dp[j]=min(1+dp[j-v[i]],dp[j]);
       } 
       
    }
}

return dp[x];
}

int main(int argc, char const *argv[])
{
     clock_t start=clock();
     init_code();
    
     //write your code here
 
     ll n,x;
     cin>>n>>x;
     vector<ll>v(n);
     loop(i,n)cin>>v[i];
     memset(dp,-1,sizeof dp);
     
     //ll ans=solve(v,0,x,0);
     ll ans=solution(v,x);
     if(ans>=INT_MAX)cout<<-1<<endl;
     else cout<<ans<<endl;
    
 
    #ifndef  ONLINE_JUDGE
     clock_t end=clock();
    cout<<"\n\n\n\nExecuted in: "<<double(end-start)/(CLOCKS_PER_SEC*1000)<<" ms"<<endl;
    #endif
   return 0;
}