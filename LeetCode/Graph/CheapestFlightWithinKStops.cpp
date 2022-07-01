// Created by Nitin kumar singh
// problem link -> https://leetcode.com/problems/cheapest-flights-within-k-stops/

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




int dijkstra(int n,vector<pair<int,int>>graph[],int src,int des,int k){
    vector<int>visited(n+1,0);
    vector<int>dist(n,1e9);
    queue<pair<int,pair<int,int>>>pq;
    pq.push({0,{src,0}});
  
    dist[src]=0;

     while(!pq.empty()){
       pair<int, pair<int,int>>p1=pq.front();pq.pop();
         int udist=p1.first;
        int u=p1.second.first;
         int step=p1.second.second;
        for(auto nbr:graph[u]){
            int v=nbr.first;
            int wt=nbr.second;
                if( dist[v]>(udist+wt) and step<=k){
                    dist[v]=udist+wt;
                    pq.push({dist[v],{v,step+1}});
             }
            
 
        }
     }
    
    if(dist[des]==1e9)return -1;
    else return dist[des];
}

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
       
        vector<pair<int,int>>graph[n];
        for(auto e:flights){
            graph[e[0]].push_back({e[1],e[2]});
        }
        
        int ans=dijkstra(n,graph,src,dst,k);
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