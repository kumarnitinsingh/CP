// Created by Nitin kumar singh
// problem link -> https://leetcode.com/problems/path-with-maximum-probability/

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




  double bfs(vector<pair<int,double>>graph[],int src,int des,int n){
       
      queue<int>q;
       vector<double>ans(n,-1);
      
      ans[src]=1.00;
      q.push(src);
      while(!q.empty()){
          int u=q.front();
           q.pop();
          for(auto nbr:graph[u]){
              int v=nbr.first;
              double p=nbr.second;
              
              if(ans[v]<ans[u]*p){
                  ans[v]=ans[u]*p;
                  q.push(v);
              }
          }
      }
       
      return ans[des];
  }


class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
       
         vector<pair<int,double>>graph[n];
        int i=0;
        for(auto e:edges){
            graph[e[0]].push_back({e[1],succProb[i]});
            graph[e[1]].push_back({e[0],succProb[i]});
            i++;
        }
        
        double ans=bfs(graph,start,end,n);
        if(ans<0)return 0;
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