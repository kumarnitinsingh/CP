// Created by Nitin kumar singh
// problem link ->  https://leetcode.com/problems/network-delay-time/submissions/

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





vector<int> dijkstra(vector<pair<int,int>>graph[],int src,int n){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
     vector<int>visited(n+1,0),dist(n+1,9999999);
      pq.push({0,src});
      dist[src]=0;
        while(!pq.empty()){
            int u=pq.top().second;
              pq.pop();
            if(visited[u]==1)continue;
            visited[u]=1;
          
            for(auto nbr:graph[u]){
                
                if(dist[nbr.first]>dist[u]+nbr.second){
                    dist[nbr.first]=dist[u]+nbr.second;
                    pq.push({dist[nbr.first],nbr.first});
                }
                
            }
        }
    
    return dist;
}


class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>>graph[n+1];
        
         for(auto e:times){
             graph[e[0]].push_back({e[1],e[2]});
         }
        
        vector<int>dist=dijkstra(graph,k,n);
        int ans=0;
        for(int i=1;i<=n;i++){
            if(dist[i]==9999999)return -1;
             ans=max(ans,dist[i]);
        }
        
        return ans;
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