// Created by Nitin kumar singh
// problem link -> https://cses.fi/problemset/task/1680/

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
       
      
        cin>>n>>m;
        for(int i=1;i<=m;i++){
            ll x,y;
            cin>>x>>y;
            graph[x].push_back(y);
        }
            
            dfs(1,-1);
            if(vis1[n]==0){
                cout<<"IMPOSSIBLE"<<endl;
                return 0;
            }

            reverse(topo.begin(),topo.end());

            vector<ll>dp(n+1,0);
            vector<ll>par(n+1,-1);

            dp[1]=1;
            par[1]=1;


            for(auto node:topo){

                if(dp[node]){
                 for(auto nbr:graph[node]){
                   // cout<<node<<"--> "<<nbr<<endl;
                     if(dp[nbr]<(dp[node]+1)){
                        dp[nbr]=1+dp[node];
                        par[nbr]=node;
                     }
                 }
             }
            }
        
            vector<ll>ans;

            ll temp=n;
            while(par[temp]!=temp){
                ans.push_back(temp);
                temp=par[temp];
            }
            ans.push_back(1);
            reverse(ans.begin(),ans.end());

            cout<<dp[n]<<endl;
            for(auto e:ans)cout<<e<<" ";


   
    #ifndef  ONLINE_JUDGE
     clock_t end=clock();
    cout<<"\n\n\n\nExecuted in: "<<double(end-start)/(CLOCKS_PER_SEC*1000)<<" ms"<<endl;
    #endif
   return 0;
}