// Created by Nitin kumar singh
// problem link ->https://cses.fi/problemset/task/1639/

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

int dp[1001][100001];

int solve(vector<int>&price,vector<int>&pages,int n,int i,int x){
        if(x==0)return 0;
        if(i==n)return 0;
        if(x<0)return INT_MIN;

        if(dp[i][x]!=-1)return dp[i][x];
        int op1=INT_MIN;
        if(x-price[i]>=0){
         op1=pages[i]+solve(price,pages,n,i+1,x-price[i]);
    }
        int op2=solve(price,pages,n,i+1,x);

        int ans=max(op1,op2);
        return dp[i][x]=ans;
}


int solve(vector<int>&prices,vector<int>&pages,int n,int x){
       vector<int>dp(x+1,0);

       for(int i=0;i<n;i++){
        for(int j=x;j>=0;j--){
            if(j-prices[i] >=0){
                dp[j]=max(dp[j],pages[i]+dp[j-prices[i]]);
            }
        }
       }
       return dp[x];
}

int main(int argc, char const *argv[])
{
     clock_t start=clock();
     init_code();
    
     //write your code here

     int n,x;
     cin>>n>>x;
     vector<int>price(n),pages(n);
     loop(i,n)cin>>price[i];
     loop(i,n)cin>>pages[i];
     memset(dp,-1,sizeof dp);

     int ans=solve(price,pages,n,x);

     cout<<ans<<endl;
     




   
    #ifndef  ONLINE_JUDGE
     clock_t end=clock();
    cout<<"\n\n\n\nExecuted in: "<<double(end-start)/(CLOCKS_PER_SEC*1000)<<" ms"<<endl;
    #endif
   return 0;
}