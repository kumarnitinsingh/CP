// Created by Nitin kumar singh
// problem link -> https://cses.fi/problemset/task/1673/

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
#define vecl            vector<long long>
#define vect           vector<vector<long long>>
#define vecb           vector<vector<bool>>
#define pb             push_back
#define all(n)         n.begin(),n.end()
#define loop(i,n)      for(int i=0;i<(n);++i)
#define loopa(i,a,n)    for(int i=a;i<=(n);++i)
#define loopr(i,a,n)   for(int i=a;i>=(n);--i)
#define sq(x)          x*x
#define cube(x)        x*x*x
#define endl           "\n"


void init_code(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output3.txt","w",stdout);
    #endif
}

const int maxn=2e4;
vector<ll>a[maxn];
vector<ll>b[maxn];
vector<ll>visited1(maxn,0);
vector<ll>visited2(maxn,0);

void dfs1(ll src){
    visited1[src]=1;
    for(auto nbr:a[src]){
        if(visited1[nbr])continue;
         dfs1(nbr);
    }
}

void dfs2(ll src){
    visited2[src]=1;
    for(auto nbr:b[src]){
        if(visited2[nbr])continue;
         dfs2(nbr);
    }
}

ll bellmanford(vector<vector<ll>>&edges,ll n){
   dfs1(1);
   dfs2(n);
    vector<ll>dist(n+1,-1e16);
    dist[1]=0;
    bool f=0;
    for(int i=1;i<=n;i++){
          f=0;
         for(auto e:edges){
             ll u=e[0];
             ll v=e[1];
             ll wt=e[2];
             if(visited1[u] and visited2[v] and dist[v]<(dist[u]+wt)){
                f=1;
                dist[v]=dist[u]+wt;
             }
         }
    }
  
     if(f)return -1;
         return dist[n];
}








int main(int argc, char const *argv[])
{
     //clock_t start=clock();
     init_code();
    
     //write your code here


        ll n,m;
        cin>>n>>m;
        vector<vector<ll>>edges;

        for(int i=0;i<m;i++){
            ll x,y,wt;
            cin>>x>>y>>wt;
            vector<ll>temp={x,y,wt};
            edges.push_back(temp);
            a[x].push_back(y);
            b[y].push_back(x);
        }


        ll  ans=bellmanford(edges,n);
        cout<<ans<<endl;





   /*
    #ifndef  ONLINE_JUDGE
     clock_t end=clock();
    cout<<"\n\n\n\nExecuted in: "<<double(end-start)/(CLOCKS_PER_SEC*1000)<<" ms"<<endl;
    #endif
    */
   return 0;
}