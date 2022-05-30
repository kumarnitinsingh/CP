// Created by Nitin kumar singh
// problem link -> https://cses.fi/problemset/task/1681/

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
    freopen("output3.txt","w",stdout);
    #endif
}

const int maxn=2e5+5;
ll n,m;
vector<ll>graph[maxn];
vector<ll>topo;
vector<ll>vis1(maxn,0);

void dfs(ll src, ll par){
    vis1[src]=1;

    for(auto nbr:graph[src]){
        if(!vis1[nbr]){
            dfs(nbr,src);
        }
    }
    topo.push_back(src);
}
int main(int argc, char const *argv[])
{
     clock_t start=clock();
     init_code();
    
     //write your code here
       
    //  memset(mat,0,sizeof mat);
         cin>>n>>m;
        for(int i=1;i<=m;i++){
            ll x,y;
            cin>>x>>y;
            graph[x].push_back(y);
        }
            
            dfs(1,-1);
           

            reverse(topo.begin(),topo.end());

            vector<ll>dp(n+1,0);
            dp[1]=1;

            for(auto node:topo){

                for(auto nbr:graph[node]){
                    dp[nbr]=(dp[nbr]+dp[node])%mod;
                }
            }
         
            cout<<dp[n]<<endl;      
           

   
    #ifndef  ONLINE_JUDGE
     clock_t end=clock();
    cout<<"\n\n\n\nExecuted in: "<<double(end-start)/(CLOCKS_PER_SEC*1000)<<" ms"<<endl;
    #endif
   return 0;
}