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


double dp[301][301][301];
double solve(ll x,ll y, ll z,ll n){
    if(x<0 or y<0 or z<0 )return 0.0;
    if(x==0 and y==0 and z==0 )return 0.0;
     if(dp[x][y][z]>-0.9)return dp[x][y][z];   
    double exp =n+x*solve(x-1,y,z,n)+y*solve(x+1,y-1,z,n)+z*solve(x,y+1,z-1,n);

    return dp[x][y][z]=exp/(x+y+z);

        
}



int main(int argc, char const *argv[])
{
     clock_t start=clock();
     init_code();
    
     //write your code here
     memset(dp,-1,sizeof dp);
     ll n;
     cin>>n;
     vector<ll>v(n);
     loop(i,n)cin>>v[i];
     ll x=0,y=0,z=0;
     loop(i,n){
        if(v[i]==1)x++;
        else if(v[i]==2)y++;
        else z++;
     }

     double ans=solve(x,y,z,n);

     cout<<fixed<<setprecision(12)<<ans<<endl;





   
    #ifndef  ONLINE_JUDGE
     clock_t end=clock();
    cout<<"\n\n\n\nExecuted in: "<<double(end-start)/(CLOCKS_PER_SEC*1000)<<" ms"<<endl;
    #endif
   return 0;
}