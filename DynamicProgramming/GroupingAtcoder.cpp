// Created by Nitin kumar singh
// problem link ->https://atcoder.jp/contests/dp/tasks/dp_u

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

ll dp[(1<<16)];
ll sum[(1<<16)];


ll calculate(vector<vector<ll>>&v,ll mask,ll n){
     ll sum=0;

     for(ll i=0;i<=16;i++){
          for(ll j=i+1;j<=16;j++){
               if((mask & (1<<i))!=0  and (mask&(1<<j))!=0)sum+=v[i][j];
          }
     }

     return sum;
}

void calculateSum(vector<vector<ll>>&v,ll n){

           for(ll i=1;i<(1<<n);i++){
         dp[i]=INT_MAX;
     }   
     for(ll i=1;i<(1<<n);i++){
          sum[i]=calculate(v,i,n);
     }

}

ll solve(vector<vector<ll>>&v,ll mask){
     if(mask==0)return 0;
     if(dp[mask]!=INT_MAX)return dp[mask];

     ll ans=0;
     for(ll submask=mask;submask!=0;submask=(submask-1) & mask){
          ans=max(ans,sum[submask]+solve(v,mask^submask));
     }

     return dp[mask]=ans;
}


int main(int argc, char const *argv[])
{
     clock_t start=clock();
     init_code();
    
     //write your code here

     //divisble subarray;

     ll n;
     cin>>n;
     vector<vector<ll>>v(n,vector<ll>(n));

     for(int i=0;i<n;i++){
          for(int j=0;j<n;j++)
               cin>>v[i][j];
     }
     calculateSum(v,n);
     ll g=(1<<n)-1;
     ll ans=solve(v,g);
     cout<<ans<<endl;




   
    #ifndef  ONLINE_JUDGE
     clock_t end=clock();
    cout<<"\n\n\n\nExecuted in: "<<double(end-start)/(CLOCKS_PER_SEC*1000)<<" ms"<<endl;
    #endif
   return 0;
}

