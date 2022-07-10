// Created by Nitin kumar singh
// problem link -> https://leetcode.com/problems/critical-connections-in-a-network/submissions/

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


vector<int>visited;
vector<int>tin,lo;
int timer;
vector<vector<int>>ans;


void dfs(vector<int>graph[],int src,int par){
    visited[src]=1;
    tin[src]=lo[src]=timer++;
    for(auto nbr:graph[src]){
        if(par==nbr)continue;
        if(visited[nbr])lo[src]=min(lo[src],tin[nbr]);
        else{
            
            dfs(graph,nbr,src);
            lo[src]=min(lo[src],lo[nbr]);
            if(tin[src]<lo[nbr]){
                ans.push_back({src,nbr});
            }
        }
    }
}

class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        ans.clear();
        visited.resize(n+1);
        tin.resize(n+1);
        lo.resize(n+1);
        timer=1;
        fill(visited.begin(),visited.end(),0);
        fill(tin.begin(),tin.end(),0);
        fill(lo.begin(),lo.end(),0);
         vector<int>graph[n+1];
        for(auto v:connections){
            graph[v[0]].push_back(v[1]);
            graph[v[1]].push_back(v[0]);
        }
        dfs(graph,0,-1);
        return ans;
    }
};

int main(int argc, char const *argv[])
{
     //clock_t start=clock();
     init_code();






   /*
    #ifndef  ONLINE_JUDGE
     clock_t end=clock();
    cout<<"\n\n\n\nExecuted in: "<<double(end-start)/(CLOCKS_PER_SEC*1000)<<" ms"<<endl;
    #endif
    */
   return 0;
}