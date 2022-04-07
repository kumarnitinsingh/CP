// Created by Nitin kumar singh
// problem link -> https://cses.fi/problemset/task/1097

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


const int maxN=5e3+1;
int arr[maxN];
    
long int dp[maxN][maxN];

long int solve(int i,int j){
    if(i>j)return 0;

    if(dp[i][j]!=-1)return dp[i][j];
    long int ans=0;

    long int op1=arr[i]+min(solve(i+1,j-1),solve(i+2,j));
    long int op2=arr[j]+min(solve(i+1,j-1),solve(i,j-2));
    ans=max(op1,op2);

    return dp[i][j]=ans;

}

int main(int argc, char const *argv[])
{
     clock_t start=clock();
     init_code();
    
     //write your code here
     
       int n;cin>>n;
       loop(i,n)cin>>arr[i];
       memset(dp,-1,sizeof dp);
       long ans=solve(0,n-1);
       cout<<ans<<endl;
    
 






   
    #ifndef  ONLINE_JUDGE
     clock_t end=clock();
    cout<<"\n\n\n\nExecuted in: "<<double(end-start)/(CLOCKS_PER_SEC*1000)<<" ms"<<endl;
    #endif
   return 0;
}