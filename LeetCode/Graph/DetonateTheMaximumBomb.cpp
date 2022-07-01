// Created by Nitin kumar singh
// problem link -> https://leetcode.com/problems/detonate-the-maximum-bombs/

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




int cn;
void dfs(vector<int>graph[],int src,vector<int>&visited){
    visited[src]=1;
    cn++;
     for(auto e:graph[src]){
         if(visited[e]==0)dfs(graph,e,visited);
     }
}
class Solution {
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n=bombs.size();
        vector<int>graph[n];
        
         for(int i=0;i<n;i++){
             int x=bombs[i][0],y=bombs[i][1],r=bombs[i][2];
             for(int  j=i+1;j<n;j++){
                  int x1=bombs[j][0],y1=bombs[j][1],r1=bombs[j][2];
                 
                  if(pow(x-x1,2)+pow(y-y1,2)-pow(r,2)<=0){
                      graph[i].push_back(j);
                  }
                 if(pow(x-x1,2)+pow(y-y1,2)-pow(r1,2)<=0){
                      graph[j].push_back(i);
                  }
                  
             }
         }
   
        
       vector<int> visited(n, 0);
        int ans = 0;
        for(int i = 0 ; i < n ; i++)
        {
            visited.assign(n, 0);
            cn = 0;
            dfs(graph,i,visited);
            ans = max(ans, cn);
            if(ans == n)
                break;
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