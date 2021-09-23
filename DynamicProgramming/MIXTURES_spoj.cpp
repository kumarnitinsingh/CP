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


ll sum(vector<ll>&v,int i,int j){
    ll sum=0;
    for(int k=i;k<=j;k++){
        sum=(sum%100+v[k]%100)%100;
    }
    return sum;
}

ll solve(vector<ll>v,ll n,int i,int j,vector<vector<ll>>&dp){
    if(i>=j)return 0;

    if(dp[i][j]!=-1)return dp[i][j];
    ll ans=INT_MAX;

    for(int k=i;k<j;k++){
      
        ll left=solve(v,n,i,k,dp);
        ll right=solve(v,n,k+1,j,dp);
      

        ll temp2=left+right+(sum(v,i,k) * sum(v,k+1,j));
      
        ans=min(temp2,ans);
    }
    
    return dp[i][j]=ans;
}



int main(int argc, char const *argv[])
{
     clock_t start=clock();
     init_code();
    
     //write your code here
     ll n;
     while(cin>>n){
     
     vector<ll>v(n);loop(i,n)cin>>v[i];
     
    
        vector<vector<ll>>dp(n+1,vector<ll>(n+1,-1));

     ll ans=solve(v,n,0,n-1,dp);
     cout<<ans<<endl;

}



   
    #ifndef  ONLINE_JUDGE
     clock_t end=clock();
    cout<<"\n\n\n\nExecuted in: "<<double(end-start)/(CLOCKS_PER_SEC*1000)<<" ms"<<endl;
    #endif
   return 0;
}