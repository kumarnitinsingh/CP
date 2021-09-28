// Created by Nitin kumar singh
// problem link ->https://atcoder.jp/contests/dp/tasks/dp_i

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


 double solve(vector<double>&v,ll i,ll x, vector<vector<double>>&dp){
       if(x==0)return 1;
       if(i==0)return 0;

       if(dp[i][x]>-0.90)return dp[i][x];

 

       return dp[i][x]=v[i]*solve(v,i-1,x-1,dp)+(1-v[i])*solve(v,i-1,x,dp);
 }


int main(int argc, char const *argv[])
{
     clock_t start=clock();
     init_code();
    
     //write your code here

     ll n;cin>>n;
     vector<double>v(n+1);
     for(int i=1;i<=n;i++)cin>>v[i];



     vector<vector<double>>dp(3001,vector<double>(3001,-1.00));
    
     double ans= solve(v,n,(n+1)/2,dp);

     cout<<fixed<<setprecision(10)<<ans<<endl;





   
    #ifndef  ONLINE_JUDGE
     clock_t end=clock();
    cout<<"\n\n\n\nExecuted in: "<<double(end-start)/(CLOCKS_PER_SEC*1000)<<" ms"<<endl;
    #endif
   return 0;
}