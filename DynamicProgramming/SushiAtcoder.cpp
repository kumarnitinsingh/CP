// Created by Nitin kumar singh
// problem link ->https://atcoder.jp/contests/dp/tasks/dp_j

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

double solve(ll x,ll y,ll z,ll &n,vector<vector<vector<double>>>&dp){
    if(x<0 || y<0 || z<0)return 0;
    if(x==0 and y==0 and z==0)return 0;

    if(dp[x][y][z]>-0.9)return dp[x][y][z];

    double exp=n+x*solve(x-1,y,z,n,dp)+y*solve(x+1,y-1,z,n,dp)+z*solve(x,y+1,z-1,n,dp);

    return dp[x][y][z]=exp/(x+y+z);
}

int main(int argc, char const *argv[])
{
     clock_t start=clock();
     init_code();
    
     //write your code here

      ll n;cin>>n;
      ll x=0,y=0,z=0;
      for(int i=0;i<n;i++){
          ll k;cin>>k;
          if(k==1)x++;
          else if(k==2)y++;
          else z++;
      }
       vector<vector<vector<double>>>dp(301,vector<vector<double>>(301,vector<double>(301,-1.0)));
      double ans=solve(x,y,z,n,dp);
      cout<<fixed<<setprecision(10)<<ans<<endl;


   
    #ifndef  ONLINE_JUDGE
     clock_t end=clock();
    cout<<"\n\n\n\nExecuted in: "<<double(end-start)/(CLOCKS_PER_SEC*1000)<<" ms"<<endl;
    #endif
   return 0;
}