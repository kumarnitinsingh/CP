// Created by Nitin kumar singh
// problem link ->  https://leetcode.com/problems/is-graph-bipartite/

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

bool istrue(vector<vector<int>>&graph,int src,int par,int color,vector<int>& visited){
       visited[src]=color;
       
       for(auto nbr:graph[src]){
           if(visited[nbr]==0){
               bool temp=istrue(graph,nbr,src,3-color,visited);
               if(temp==false)return false;
           }
           // cycle exist and if cuuent node color and nbr color is equal then graph is not bipartite
           else if(nbr!=par and visited[nbr]==visited[src])return false;
       }
       
       return true;
}

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>visited(n+1,0);
        
        for(int i=0;i<n;i++){
	        if(visited[i]==0){
	         bool temp= istrue(graph,i,-1,1,visited);
	         if(temp==false)return false;
	        }
	     }
	     return true;
        
        
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