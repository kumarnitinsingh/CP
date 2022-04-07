// Created by Nitin kumar singh
// problem link -> https://atcoder.jp/contests/dp/tasks/dp_l

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

ll dp[3001][3001];

ll solve(vector<ll>&v,ll n,ll i,ll j){
        if(i>j)return 0;
        if(i==j)return v[i];
        if(dp[i][j]!=-1)return dp[i][j];

        ll op1=v[i]+min(solve(v,n,i+2,j),solve(v,n,i+1,j-1));
        ll op2=v[j]+min(solve(v,n,i+1,j-1),solve(v,n,i,j-2));

       return dp[i][j]=max(op1,op2);
}
  



int main(int argc, char const *argv[])
{
     clock_t start=clock();
     init_code();
    
     //write your code here
     memset(dp,-1,sizeof dp);
     ll n;cin>>n;
     vector<ll>v(n);loop(i,n)cin>>v[i];

     ll ans=solve(v,n,0,n-1);
     ll sum=0;
     loop(i,n)sum=sum+v[i];
     ll finalAns=ans-(sum-ans);
     cout<<finalAns<<endl;    

     


   
    #ifndef  ONLINE_JUDGE
     clock_t end=clock();
    cout<<"\n\n\n\nExecuted in: "<<double(end-start)/(CLOCKS_PER_SEC*1000)<<" ms"<<endl;
    #endif
   return 0;
}