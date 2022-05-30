// Created by Nitin kumar singh
// problem link -> https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/

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


const int mod=1e9+7;
long long dijkstra(int n,vector<pair<long,long>>graph[]){
    
    vector<int>visited(n+1,0);
    priority_queue<pair<long,long>,vector<pair<long,long>>,greater<pair<long,long>>>pq;
    vector<long long>dist(n+1,1e16),rou(n+1,1e16);
    pq.push({0,0});
    dist[0]=0;
    rou[0]=1;
    
    while(!pq.empty()){
        long u=pq.top().second;
        pq.pop();
        if(visited[u]==1)continue;
         
        visited[u]=1;
        
        for(auto e:graph[u]){
           
             
            long v=e.first;
            long wt=e.second;
            if(dist[v]> dist[u]+wt){
                dist[v]=dist[u]+wt;
                pq.push({dist[v],v});
                rou[v]=rou[u];
                
            }
            else if(dist[v]==dist[u]+wt){
                
                rou[v]=(rou[v]+rou[u])%mod;
                 
            }
        }
    }

    return  rou[n-1];
    
}

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<long,long>>graph[n+1];
        for(auto r:roads){
            graph[r[0]].push_back({r[1],r[2]});
            graph[r[1]].push_back({r[0],r[2]});
        }
         long long ans=dijkstra(n,graph);
        int p=ans%mod;
        return p;
    }
};







int main(int argc, char const *argv[])
{
     //clock_t start=clock();
     init_code();
    
     //write your code here





   /*
    #ifndef  ONLINE_JUDGE
     clock_t end=clock();
    cout<<"\n\n\n\nExecuted in: "<<double(end-start)/(CLOCKS_PER_SEC*1000)<<" ms"<<endl;
    #endif
    */
   return 0;
}