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

vector<ll>graph[100005];
vector<int>visited(100005,0);



void dfs(vector<ll>graph[],vector<int>&visited,ll node)
{
    cout<<node<<" ";
    visited[node]=true;
    for(auto nbr:graph[node]){
        if(!visited[nbr])dfs(graph,visited,nbr);
    }

  
}

int bfs(vector<ll>graph[],vector<int>&visited,ll src,ll dest,vector<int>&path){
    queue<int>q;
    q.push(src);
     visited[src]=true;
     vector<int>dist(10000,1e6);
     dist[src]=0;
     path[src]=src;
     while(!q.empty()){
        ll no=q.front();q.pop();

        for(auto nbr:graph[no]){
            if(visited[nbr]!=true){
                dist[nbr]=1+dist[no];
                path[nbr]=no;
                visited[nbr]=true;
                q.push(nbr); 
            }
        }
     }

    return dist[dest]; 
}

int main(int argc, char const *argv[])
{
     clock_t start=clock();
     init_code();
    
     //write your code here
     ll  n,m;cin>>n>>m;

     for(int i=0;i<m;i++){
        ll x,y;
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
     }

        vector<int>path(n+1,-1);
        ll src,dest;
        cin>>src>>dest;

      int distance=bfs(graph,visited,src,dest,path);
       cout<<"The shortest distance between "<<src<<" and "<<dest<<" is "<<distance <<endl;
      vector<int>pathTrace;
        while(path[dest]!=dest){
            pathTrace.push_back(dest);
            dest=path[dest];
        }
        pathTrace.push_back(src);
        reverse(pathTrace.begin(),pathTrace.end());


        cout<<"Path is ";
        for(auto p:pathTrace){
            cout<<p<<"->";
        }

       

     


   
    #ifndef  ONLINE_JUDGE
     clock_t end=clock();
    cout<<"\n\n\n\nExecuted in: "<<double(end-start)/(CLOCKS_PER_SEC*1000)<<" ms"<<endl;
    #endif
   return 0;
}