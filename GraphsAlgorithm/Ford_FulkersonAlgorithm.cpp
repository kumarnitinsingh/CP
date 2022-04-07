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



int Bfs(vector<int>graph[],vector<vector<int>>&capacity,int N,vector<int>&parent){
    fill(parent.begin(),parent.end(),-1);
    int src=1;
    int sink=N;
    parent[src]=-2;
    queue<pair<int,int>>q;
    q.push({src,INT_MAX-999});
    while(!q.empty()){
        pair<int,int>p=q.front();q.pop();
        int u=p.first;
        int cap=p.second;
        
        for(auto nbr:graph[u]){
            if(nbr!=u and parent[nbr]==-1 and capacity[u][nbr]>0){
                parent[nbr]=u;
                int mflow=min(cap,capacity[u][nbr]);
                if(nbr==sink){
                    return mflow;
                }
                q.push({nbr,mflow});
            }
        }
    }
    
    return 0;
}

int ford_Fulkerson(vector<int>graph[],vector<vector<int>>&capacity,int N){
    
    int src=1;
    int sink=N;
    vector<int>parent(N+1);
    int maxflow=0;
        
        int flow=0;
      while(flow=Bfs(graph,capacity,N,parent)){
            maxflow+=flow;
            int cur=sink;
            while(cur!=src){
                int prev=parent[cur];
                capacity[prev][cur]-=flow;
                capacity[cur][prev]+=flow;
                cur=prev;
            }
      }
      
      return maxflow;
}




class Solution
{
public:
    int solve(int N,int M,vector<vector<int>> Edges)
    {
        // code here
        vector<int>graph[N+1];
        vector<vector<int>>capacity(N+1,vector<int>(N+1,0));
        for(auto e:Edges){
            int u=e[0];
            int v=e[1];
            int wt=e[2];
            graph[u].push_back(v);
            graph[v].push_back(u);
            capacity[u][v]=wt;
            capacity[v][u]=wt;
        }
        
        int ans=ford_Fulkerson(graph,capacity,N);
        return ans;
    }
};

int main(int argc, char const *argv[])
{
     clock_t start=clock();
     init_code();
    
     //write your code here





   
    #ifndef  ONLINE_JUDGE
     clock_t end=clock();
    cout<<"\n\n\n\nExecuted in: "<<double(end-start)/(CLOCKS_PER_SEC*1000)<<" ms"<<endl;
    #endif
   return 0;
}