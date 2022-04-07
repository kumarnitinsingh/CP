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
    freopen("output2.txt","w",stdout);
    #endif
}


ll dp[200001][21];
ll lvl[200001];

void level(vector<set<int>>&tree,ll src,ll par,ll l){
     lvl[src]=l;
     for(auto nbr:tree[src]){
         if(nbr!=par){
            level(tree,nbr,src,l+1);
         }
     }
}

void dfs1(vector<set<int>>&tree,ll src,ll par){
     dp[src][0]=par;
     for(int i=1;i<=20;i++){
        if(dp[src][i-1]!=-1){
            dp[src][i]=dp[dp[src][i-1]][i-1];
        }
        else dp[src][i]=-1;
     }
     for(auto nbr:tree[src]){

        if(nbr!=par){
            dfs1(tree,nbr,src);
        }
     }
}


int  uplift(ll u,ll k){
  
    for(ll i=20;i>=0;i--){
         if( k==0 or u==-1)break;
        if(k>=(1<<i)){
             u=(dp[u][i]);
             k-=((1<<i));
        }
    }
    return u;
}

int lca(ll u,ll v){
    if(lvl[u]<lvl[v])swap(u,v);
  u=  uplift(u,lvl[u]-lvl[v]);

    if(u==v)return u;

    for(int i=20;i>=0;i--){

        if(dp[u][i]!=dp[v][i]){
            u=dp[u][i];
            v=dp[v][i];
        }
    }
    
   return uplift(u,1);
}

   int dist(int x,int y){
         int lc=lca(x,y);

         int dis=lvl[x]+lvl[y]-2*lvl[lc];
          return dis;
      }



struct CentroidDecomposition {
    vector<set<int>> tree; // it's not vector<vector<int>>!
    vector<int> dad;
    vector<int> sub;
    vector<int>depth;
    vector<int>res;

    CentroidDecomposition(vector<set<int>> &tree) : tree(tree) {
        int n = tree.size();
        dad.resize(n);
        sub.resize(n);
        depth.resize(n);
        res.resize(n);
        res={99999999};
        build(1, -1);
       
    }

    void build(int u, int p) {
        int n = dfs(u, p); // find the size of each subtree
        int centroid = dfs(u, p, n); // find the centroid
      //  if (p == -1) p = centroid; // dad of root is the root itself
        dad[centroid] = p;

        if(p==-1)depth[u]=0;
         depth[u]=1+depth[p];
        // for each tree resulting from the removal of the centroid
        for (auto v : tree[centroid])
            tree[centroid].erase(v), // remove the edge to disconnect
            tree[v].erase(centroid), // the component from the tree
            build(v, centroid);
    }

    int dfs(int u, int p) {
        sub[u] = 1;

        for (auto v : tree[u])
            if (v != p) sub[u] += dfs(v, u);

        return sub[u];
    }

    int dfs(int u, int p, int n) {
        for (auto v : tree[u])
            if (v != p and sub[v] > n/2) return dfs(v, u, n);

        return u;
    }

    int operator[](int i) {
        return dad[i];
    }
    // int lca(int u,int v){
    //      if(depth[u]<depth[v])swap(u,v);
    //         while(depth[u]>depth[v]){
    //             u=dad[u];
    //         }    
    //         while(dad[u]!=dad[v]){
    //               u=dad[u];
    //               v=dad[v];
    //         }
        
    //     return dad[u];
    // }

 

    void update(int node)
{
    int curr = node;
    while(curr != -1)
    {
        res[curr] = min(res[curr] , dist(curr , node));
 
        curr = dad[curr];
    }
}
 
int query(int node)
{
    int curr = node;
    int ans = 99999999;
    while(curr != -1)
    {
        ans = min(ans , res[curr] + dist(node , curr));
        curr = dad[curr];
    }
 
    return ans;
}
    
    
};


int main(int argc, char const *argv[])
{
     clock_t start=clock();
     init_code();
    
     //write your code here
        int n,m;cin>>n>>m;
        vector<set<int>>tree(n+1);
        for(int i=1;i<n;i++){
            int x,y;
            cin>>x>>y;
            tree[x].insert(y);
            tree[y].insert(x);
        }


        level(tree,1,-1,1);
        dfs1(tree,1,-1);
        CentroidDecomposition c(tree);
      

      while(m--){
        int x;cin>>x;
        if(x==1){
            int y;cin>>y;
            y;
            c.update(y);
        }
        else{
            int y;
            cin>>y;
            y;
            cout<<c.query(y)<<endl;
        }
      }






   
    #ifndef  ONLINE_JUDGE
     clock_t end=clock();
    cout<<"\n\n\n\nExecuted in: "<<double(end-start)/(CLOCKS_PER_SEC*1000)<<" ms"<<endl;
    #endif
   return 0;
}