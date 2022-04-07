// Created by Nitin kumar singh
// problem link -> https://cses.fi/problemset/task/1746/

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

const int maxN=1e5,maxM=105;
int dp[maxN][maxM];
int n,m;
int v[maxN];

int solve(int i,int prev){
    if(i==n)return 1;
    int &ans=dp[i][prev];
    if(ans==-1){
        ans=0;

        if(v[i]==0){
            ans=(ans+solve(i+1,prev))%mod;
            if(prev-1>=1){
                 ans=(ans+solve(i+1,prev-1))%mod;
            }
            if(prev+1<=m){
                 ans=(ans+solve(i+1,prev+1))%mod;
            }
        
        }
        else{

            if(abs(v[i]-prev)>1)ans=0;
            else {
                ans=(ans+solve(i+1,v[i]))%mod;
            }

        }

    }
    return dp[i][prev]=ans;
}

int main(int argc, char const *argv[])
{
     clock_t start=clock();
     init_code();
    
     //write your code here

        cin>>n>>m;
        loop(i,n)cin>>v[i];

        int ans=0;
        memset(dp,-1,sizeof dp);
        if(v[0]==0){
            for(int i=1;i<=m;i++)
            ans=(ans+solve(1,i))%mod;
        }
        else{
            ans=ans+solve(1,v[0]);

        }

        cout<<ans<<endl;




   
    #ifndef  ONLINE_JUDGE
     clock_t end=clock();
    cout<<"\n\n\n\nExecuted in: "<<double(end-start)/(CLOCKS_PER_SEC*1000)<<" ms"<<endl;
    #endif
   return 0;
}