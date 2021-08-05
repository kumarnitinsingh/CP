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

void dfs(int cur,int par,vector<int>&depth,vector<int>&parent,vector<int>g[]){
          parent[cur]=par;
          for(auto node:g[cur]){
             if(par!=node){
                depth[node]=depth[cur]+1;
                dfs(node,cur,depth,parent,g);
             }
          }
}


int lca(int u,int v,vector<int>&depth,vector<int>&parent ){
    if(depth[u]<depth[v]) swap(u,v);
    if(u==v)return u;

    while(depth[u]>depth[v]){
        u=parent[u];
    }

    while(u!=v){
        u=parent[u];
        v=parent[v];
    }
   
   return u;

}

int main(int argc, char const *argv[])
{
     clock_t start=clock();
     init_code();
    
     //write your code here
     int n,m;
     cin>>n>>m;
     vector<int>g[n];
     for(int i=0;i<m;i++){
           int x,y;
           cin>>x>>y;
           g[x].push_back(y);
           g[y].push_back(x);

     }
      
     vector<int>depth(n);
     vector<int>parent(n);

     dfs(1,-1,depth,parent,g); 

      cout<<lca(13 ,16,depth,parent);



   
    #ifndef  ONLINE_JUDGE
     clock_t end=clock();
    cout<<"\n\n\n\nExecuted in: "<<double(end-start)/(CLOCKS_PER_SEC*1000)<<" ms"<<endl;
    #endif
   return 0;
}