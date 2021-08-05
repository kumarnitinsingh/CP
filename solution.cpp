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

          struct node{
              int u;int v;int wt;
          };
          
          class mycom{
              public:
               bool operator()(node x,node y){
                   return x.wt>y.wt;
               }
          };
          
       int find(int x,vector<int>parent){
           if(parent[x]==x)return x;
           return parent[x]=find(parent[x],parent);
       }
       
       void unite(int x,int y,vector<int>&rank,vector<int>&parent){
           x=find(x,parent);
           y=find(y,parent);
           if(x==y)return;
           if(rank[x]>rank[y])parent[y]=x;
           else{
               parent[x]=y;
               rank[y]++;
           }
       }
       
       
    ll spanningTree(int V, vector<vector<int>> adj)
    {
        // code here  
        vector<int>parent(V+1);
        vector<int>rank(V+1);
        for(int i=1;i<=V;i++){
            parent[i]=i;
            rank[i]=1;
        }
        priority_queue<node,vector<node>,mycom>q;
        
        for(int i=0;i<adj.size();i++){

           
          
            node a;
            a.u=adj[i][0];
            a.v=adj[i][1];
            a.wt=adj[i][2];
            q.push(a);
           
        }
        ll ans=0;
        
         while(!q.empty()){
             node temp=q.top();q.pop();
             int u=temp.u;
             int v=temp.v;
             int wt=temp.wt;
             
             if(find(u,parent)!=find(v,parent)){
                 ans+=wt;
                 unite(u,v,rank,parent);
             }
         }
        
        return ans;
        
    }


int main(int argc, char const *argv[])
{
     clock_t start=clock();
     init_code();
    
     //write your code here
       
       int n,m;cin>>n>>m;
       vector<vector<int>>g;
       for(int i=0;i<m;i++){
        int u,v,wt;
        cin>>u>>v>>wt;
        g.push_back({u,v,wt});
       }


      cout<<spanningTree(n,g)<<endl;


   
    #ifndef  ONLINE_JUDGE
     clock_t end=clock();
    cout<<"\n\n\n\nExecuted in: "<<double(end-start)/(CLOCKS_PER_SEC*1000)<<" ms"<<endl;
    #endif
   return 0;
}