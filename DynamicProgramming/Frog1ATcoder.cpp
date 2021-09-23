// Created by Nitin kumar singh
// problem link -> https://atcoder.jp/contests/dp/tasks/dp_a

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

ll solve(vector<ll>v,ll n, vector<ll>dp){
    if(n==0)return 0;
    if(n==1)return 0;
    if(n==2)return abs(v[2]-v[1]);
   
    //if(n==3)return min(abs(v[n]-v[n-1]),abs(v[n]-v[n-2]));

    if(dp[n]!=-1)return dp[n];
     
     ll op1=abs(v[n]-v[n-1])+solve(v,n-1,dp);
     ll op2=abs(v[n]-v[n-2])+solve(v,n-2,dp);

     return dp[n]=min(op1,op2);
}


ll DP(vector<ll>v,ll n){
    vector<ll>dp(n+1,0);

        dp[1]=0;
        dp[2]=abs(v[2]-v[1]);
    for(int i=3;i<=n;i++){
        dp[i]=min(abs(v[i]-v[i-1])+dp[i-1],abs(v[i]-v[i-2])+dp[i-2]);
    } 
    return dp[n];
}


int main()
{
     clock_t start=clock();
     init_code();
    
     //write your code here

     ll n;cin>>n;
     vector<ll>v(n+1);
     for(int i=1;i<=n;i++)cin>>v[i];
     vector<ll>dp(n+1,-1);

     //ll ans=solve(v,n,dp);

       ll ans=DP(v,n);
     cout<<ans<<endl;





   
    #ifndef  ONLINE_JUDGE
     clock_t end=clock();
    cout<<"\n\n\n\nExecuted in: "<<double(end-start)/(CLOCKS_PER_SEC*1000)<<" ms"<<endl;
    #endif
   return 0;
}