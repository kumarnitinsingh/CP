// Created by Nitin kumar singh
// problem link -> https://cses.fi/problemset/task/1636/
 
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
 
 
int dp[100][1000000];


int solve(vector<int>& v,int i,int x,int sum){
     if(sum>x)return 0;

    if(sum==x)return 1;
    if(i==v.size())return 0;
   
    if(dp[i][sum]!=-1)return dp[i][sum];
    int ans=0;

    int op1=solve(v,i,x,sum+v[i]);
    int op2=solve(v,i+1,x,sum);

    ans=(op1+op2)%mod;

    return dp[i][sum]=ans;

}
 
int solution(vector<int>&v,int x){
    int n=v.size();
    vector<vector<int>>dp(n+1,vector<int>(x+1,0));

    dp[0][0]=1;

    for(int i=1;i<=n;i++){
        for(int j=0;j<=x;j++){
            dp[i][j]=dp[i-1][j];
            if(j-v[i-1]>=0){
                dp[i][j]=(dp[i][j]+dp[i][j-v[i-1]])%mod;
            }
        }
    }
    return dp[n][x];
}

int main(int argc, char const *argv[])
{
     clock_t start=clock();
     init_code();

  //int mod = 1e9+7;
  int n, target;
  cin >> n >> target;
  vector<int> x(n);
  for (int&v : x) cin >> v;

    int ans=solution(x,target);
    cout<<ans<<endl;
 
 
 
 
   
    #ifndef  ONLINE_JUDGE
     clock_t end=clock();
    cout<<"\n\n\n\nExecuted in: "<<double(end-start)/(CLOCKS_PER_SEC*1000)<<" ms"<<endl;
    #endif
   return 0;
}