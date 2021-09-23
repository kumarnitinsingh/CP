// Created by Nitin kumar singh
// problem link -> https://atcoder.jp/contests/dp/tasks/dp_c

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

ll solve( vector<ll>swim, vector<ll>cat, vector<ll>homework,ll n,ll last,vector<ll>dp){
      if(n==0)return 0;
      ll ans=0;
      if(dp[n]!=-1)return dp[n];
       ll op1=last==1?INT_MIN:swim[n-1]+solve(swim,cat,homework,n-1,1,dp);
       ll op2=last==2?INT_MIN:cat[n-1]+solve(swim,cat,homework,n-1,2,dp);
       ll op3=last==3?INT_MIN:homework[n-1]+solve(swim,cat,homework,n-1,3,dp);

        ans=max({op1,op2,op3});
        return dp[n]=ans;
}

ll solve( vector<ll>swim, vector<ll>cat, vector<ll>homework,ll n){
    vector<vector<ll>>dp(n+1,vector<ll>(3,0));
     
  
      for(int i=1;i<=n;i++){
         for(int j=0;j<3;j++){
            if(j==0){
                ll temp=swim[i-1]+max(dp[i-1][1],dp[i-1][2]);
                dp[i][j]=temp;
            }
            if(j==1){
                ll temp=cat[i-1]+max(dp[i-1][0],dp[i-1][2]);
                dp[i][j]=temp;

            }
            if(j==2){
                 ll temp=homework[i-1]+max(dp[i-1][0],dp[i-1][1]);
                dp[i][j]=temp;
            }
         }
      }
    
     return max({dp[n][0],dp[n][1],dp[n][2]});
}




int main(int argc, char const *argv[])
{
     clock_t start=clock();
     init_code();
    
     //write your code here

     ll n;cin>>n;
     vector<ll>swim(n),cat(n),homework(n);

     loop(i,n)cin>>swim[i]>>cat[i]>>homework[i];
       //    vector<ll>dp(n+1,-1);
      
       //  ll last=1;
       //  ll ans1=solve(swim,cat,homework,n,last,dp);
       //   dp.clear();   

       //    vector<ll>dp1(n+1,-1);
       
       //  last=2;
       // ll ans2=solve(swim,cat,homework,n,last,dp1);

       // dp1.clear();
       //   vector<ll>dp3(n+1,-1);
       // last=3;
       // ll ans3=solve(swim,cat,homework,n,last,dp3);
       // dp3.clear();
       //  cout<<max({ans1,ans2,ans3})<<endl;

     ll ans=INT_MIN;
    
        ans=max(ans,solve(swim,cat,homework,n));
     

     cout<<ans<<endl;




   
    #ifndef  ONLINE_JUDGE
     clock_t end=clock();
    cout<<"\n\n\n\nExecuted in: "<<double(end-start)/(CLOCKS_PER_SEC*1000)<<" ms"<<endl;
    #endif
   return 0;
}