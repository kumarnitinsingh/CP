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

// int no_of_edges(int start,int end,vector<int>g[],int n,int d){
//     vector<int>dist(n+1,0);
//     vector<bool>visited(n+1,false);
//     queue<int>q;
//     q.push(start);
//     int edges=0;
//     dist[start]=0;
//     while(!q.empty()){
//         int u=q.front();q.pop();
            
        
//         for(auto v:g[u]){
//             if(visited[v]==false){
//                 dist[v]=dist[u]+1;
//                 q.push(v);
                
//             }
//             //if(v==end)return dist[v];
//         }

//     }
//     return dist[end];
// }

// int ShortestPathInUndirectedGraph(int source,int dest){
//     vector<int>dist(V,0);
//     vector<int>parent(V,-1);
//     vector<bool>visited(V,false);
//     queue<int>q;
//       dist[source]=0;
//       q.push(source);
//       parent[source]=0;
//       while(!q.empty()){
//         int v=q.front();q.pop();
//         for(auto nbr:l[v]){
//             if(!visited[nbr]){
//                 dist[nbr]=dist[v]+1;
//                 visited[nbr]=true;
//                 q.push(nbr);
//             }
//         }
//       }
 
//  return dist[dest];
// }

class graph{
public:
int V;
list<int> *l;
public:
    graph(int v){
        V=v;
        l=new list<int>[V];
    }

    void addEdge(int u,int v,bool undir=true){
        l[u].push_back(v);
        if(undir)l[v].push_back(u);
    }



vector<int> ShortestPathInUndirectedGraph(int source){
    vector<int>dist(V,0);
    vector<int>parent(V,-1);
    vector<bool>visited(V,false);
    queue<int>q;
      dist[source]=0;
      q.push(source);
      parent[source]=0;
      while(!q.empty()){
        int v=q.front();q.pop();
        for(auto nbr:l[v]){
            if(!visited[nbr]){
                dist[nbr]=dist[v]+1;
                visited[nbr]=true;
                q.push(nbr);
            }
        }
      }
 
 return dist;
}
};


int main(int argc, char const *argv[])
{
     clock_t start=clock();
     init_code();
    
     //write your code here
     ll t;cin>>t;
     while(t--){
        ll n,q;
        cin>>n>>q;

        graph g(n+1);
       
         for(int i=1;i<n;i++){
            int u,v;
            cin>>u>>v;
            g.addEdge(u,v);
            g.addEdge(v,u);
           
         }
     


     while(q--){
        int k,d;
        cin>>k>>d;
        vector<int>v;
       for(int i=0;i<k;i++){
        int x;cin>>x;
        v.push_back(x);
       }
       

     ll cn=0;
     sort(v.begin(),v.end());
       for(int i=0;i<k;i++){
        vector<int>temp=g.ShortestPathInUndirectedGraph(v[i]);

        for(int j=i+1;j<k;j++){
              
            if(temp[j]==d)cn++;

        }
       
       }
       cout<<cn<<endl;
     }

    
}


   
    #ifndef  ONLINE_JUDGE
     clock_t end=clock();
    cout<<"\n\n\n\nExecuted in: "<<double(end-start)/(CLOCKS_PER_SEC*1000)<<" ms"<<endl;
    #endif
   return 0;
}