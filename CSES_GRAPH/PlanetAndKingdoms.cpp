// Created by Nitin kumar singh
// problem link -> https://cses.fi/problemset/task/1683/
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

void dfs(vector<int>graph[],int src,vector<int>&visited,vector<int>&ans){
    visited[src]=1;
    
    for(auto nbr:graph[src]){
        if(!visited[nbr]){
            dfs(graph,nbr,visited,ans);
        }
    }
     ans.push_back(src);
    return;
}

;


void dfs2(vector<int>graph[],int node,vector<int>&visited,vector<int>&ans,int cn){
      visited[node]=1;
      ans[node]=cn;
    for(auto nbr:graph[node])
        if(!visited[nbr] )dfs2(graph,nbr,visited,ans,cn);
    }

    //Function to find number of strongly connected components in the graph.
    int cn=0;
    vector<int> kosaraju(int V, vector<int> adj[])
    {
        //code here
        vector<int>graph[V+1];
        
        for(int i=1;i<=V;i++){
            for(auto nbr:adj[i]){
                graph[nbr].push_back(i);
            }
        }
        
        vector<int>visited(V+1,0),ans,visited2(V+1,0),ans2(V+1);
         for(int i=1;i<=V;i++){
         if(!visited[i])dfs(adj,i,visited,ans);
         }
        reverse(ans.begin(),ans.end());
        
       

        for(auto nbr: ans){
            if(!visited2[nbr]){
                cn++;
                
              
                
                dfs2(graph,nbr,visited2,ans2,cn);
            }
        }
        return ans2;
    }

int main(int argc, char const *argv[])
{
     clock_t start=clock();
     init_code();
    
     //write your code here
      int n,m;
      cin>>n>>m;
      vector<int>adj[n+3];
      for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
         adj[x].push_back(y);
      }

   

       vector<int>temp=kosaraju(n,adj);
       cout<<cn<<endl;
       for(int i=1;i<=n ;i++)cout<<temp[i]<<" ";


   
    #ifndef  ONLINE_JUDGE
     clock_t end=clock();
    cout<<"\n\n\n\nExecuted in: "<<double(end-start)/(CLOCKS_PER_SEC*1000)<<" ms"<<endl;
    #endif
   return 0;
}