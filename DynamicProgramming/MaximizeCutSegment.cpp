// Created by Nitin kumar singh
// problem link ->  https://practice.geeksforgeeks.org/problems/cutted-segments1642/1#

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

int dp[10001];
int solve(int n,int x,int y,int z){
    if(n<0)return INT_MIN;
    if(n==0)return 0;
    if(dp[n]!=-1)return dp[n];
    int op1=INT_MIN,op2=INT_MIN,op3=INT_MIN;
    op1=solve(n-x,x,y,z)
     op2=solve(n-y,x,y,z);
     op3=solve(n-z,x,y,z);
    
    return dp[n]=1+max({op1,op2,op3});
}

    int maximizeTheCuts(int n, int x, int y, int z)
    {
        memset(dp,-1,sizeof dp);
        int ans= solve(n,x,y,z);
        if(ans<0)return 0;
        return ans;
    }


      int maximizeTheCuts(int n, int x, int y, int z)
    {
        //Your code here
        vector<int>dp(n+1,-1);
        dp[0]=0;
        for(int i=0;i<=n;i++){
            if(dp[i]!=-1){
            if(i+x<=n){dp[i+x]=max(dp[i]+1,dp[i+x]);}
            if(i+y<=n){dp[i+y]=max(dp[i]+1,dp[i+y]);}
            if(i+z<=n){dp[i+z]=max(dp[i]+1,dp[i+z]);}
        }
    }
        if(dp[n]==-1)return 0;
        return dp[n];
       
    }

int main(int argc, char const *argv[])
{
     clock_t start=clock();
     init_code();
    
     //write your code here





   
    #ifndef  ONLINE_JUDGE
     clock_t end=clock();
    cout<<"\n\n\n\nExecuted in: "<<double(end-start)/(CLOCKS_PER_SEC*1000)<<" ms"<<endl;
    #endif
   return 0;
}