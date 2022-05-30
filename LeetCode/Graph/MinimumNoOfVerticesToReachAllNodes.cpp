// Created by Nitin kumar singh
// problem link -> https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes/

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



 vector<int>topo;  
void dfs(vector<int>graph[],int src,int par,vector<int>&visited){
       visited[src]=1;
      
       for(auto nbr:graph[src]){
           if(visited[nbr]==0){
               dfs(graph,nbr,src,visited);
           }
       }
      topo.push_back(src);
          
    }




 void dfs2(vector<int>graph[],int src,int par,vector<int>&visited){
       visited[src]=1;
      
       for(auto nbr:graph[src]){
           if(visited[nbr]==0){
               dfs2(graph,nbr,src,visited);
           }
       }
      
      
  }

class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
         vector<int>visited(n+1,0),ans;
        vector<int>graph[n+1];
        for(auto e:edges){
            graph[e[0]].push_back(e[1]);
           
        }
            
        for(int i=0;i<n;i++){
            if(visited[i]==0){
                dfs(graph,i,-1,visited);
            }
        }
         
          reverse(topo.begin(),topo.end());
            fill(visited.begin(),visited.end(),0);
           for(auto i:topo){
               if(visited[i]==0){
                   dfs2(graph,i,-1,visited);
                   ans.push_back(i);
               }
           }
        
        topo.clear();
        
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