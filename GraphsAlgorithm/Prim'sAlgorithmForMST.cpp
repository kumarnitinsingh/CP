// Created by Nitin kumar singh
// problem link ->https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1

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



int MST(vector<pair<int,int>>graph[],int n){
     priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
     int ans=0;
     vector<int>visited(n+1,0);
      pq.push({0,1});

      while(!pq.empty()){
           pair<int,int>node=pq.top();
          pq.pop();
          if(visited[node.second])continue;
          visited[node.second]=true;
          ans+=node.first;

          for(auto nbr:graph[node.second]){
             if(!visited[nbr.first]){
                pq.push({nbr.second,nbr.first});
             }
          }
      }
  return ans;
}
int main(int argc, char const *argv[])
{
     clock_t start=clock();
     init_code();
    
     //write your code here

     int n,m;
     cin>>n>>m;
      vector<pair<int,int>>graph[n+1];  

      for(int i=0;i<m;i++){
        int u,v,wt;
        cin>>u>>v>>wt;
       
        graph[u].push_back({v,wt});
        graph[v].push_back({u,wt});
      }

      int ans=MST(graph,n+1);
      cout<<ans<<endl;




   
    #ifndef  ONLINE_JUDGE
     clock_t end=clock();
    cout<<"\n\n\n\nExecuted in: "<<double(end-start)/(CLOCKS_PER_SEC*1000)<<" ms"<<endl;
    #endif
   return 0;
}