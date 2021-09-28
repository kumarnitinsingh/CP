// Created by Nitin kumar singh
// problem link ->https://atcoder.jp/contests/dp/tasks/dp_m

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


// ll dp[101][100001];


// ll solve(vector<ll>&v,ll i,ll n,ll k){
    
//     if(k<0 or i>=n)return 0;
//     if(k==0)return 1;

//      if(dp[i][k]!=-1)return dp[i][k];
//      ll ans=0;
//      for(int j=0;j<=v[i];j++){
//         ans=(ans %mod +solve(v,i+1,n,k-j)%mod)%mod;
//      }
//      return dp[i][k]=ans%mod;
// }

ll solve(vector<ll>&v,ll n,ll k){
    ll dp[n+2][k+2];
    for(int i=0;i<=k;i++){
        dp[1][i]=(i>v[1])?0:1;
    }

    for(int i=2;i<=n;i++){
        for(int j=0;j<=k;j++){
            if(j==0)dp[i][j]=dp[i-1][j];
            else {dp[i][j]=(mod+dp[i-1][j]+dp[i][j-1]-((j-v[i]-1)>=0?dp[i-1][j-v[i]-1]:0))%mod;}
        }

    }
    return dp[n][k]%mod;
}

int main(int argc, char const *argv[])
{
     clock_t start=clock();
     init_code();
    
     //write your code here
            
       ll n,k;
       cin>>n>>k;
       vector<ll>v(n+1);
       for(int i=1;i<=n;i++)cin>>v[i];
        
       
       // memset(dp,-1,sizeof dp);
        
        ll ans=solve(v,n,k);
        cout<<ans<<endl;



   
    #ifndef  ONLINE_JUDGE
     clock_t end=clock();
    cout<<"\n\n\n\nExecuted in: "<<double(end-start)/(CLOCKS_PER_SEC*1000)<<" ms"<<endl;
    #endif
   return 0;
}

