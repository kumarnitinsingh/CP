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

  

  //problem statement 

// The first problem we solve is as follows: Given a tree T of N nodes, 
// where each node i has Ci coins attached with it. You have to choose a subset of nodes such that no two a
// djacent nodes(i.e. nodes connected directly by an edge) are chosen
//  and sum of coins attached with nodes in chosen subset is maximum.

ll NodeConsiderd[100],MaxIntsubtree[100];

 void dfs(vector<ll>graph[],ll src,ll par,vector<ll>&C){

      ll sum1=0,sum2=0;
     for(auto nbr:graph[src]){
        if(nbr==par)continue;
        dfs(graph,nbr,src,C);

        sum1+=MaxIntsubtree[nbr];
        sum2+=max(NodeConsiderd[nbr],MaxIntsubtree[nbr]);
     }

      NodeConsiderd[src]=sum1+C[src];
      MaxIntsubtree[src]=sum2;
 }

int main(int argc, char const *argv[])
{
     clock_t start=clock();
     init_code();
    
     //write your code here

     ll n,m;cin>>n>>m;
     vector<ll>graph[n+1];

     for(int i=0;i<m;i++){
        ll x,y;
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
     }
      vector<ll>C(n+1);
      for(int i=1;i<=n;i++){
        cin>>C[i];
      }
      memset(MaxIntsubtree,0,sizeof MaxIntsubtree);
      memset(NodeConsiderd,0,sizeof NodeConsiderd);

      dfs(graph,1,-1,C);

       cout<<max(NodeConsiderd[1],MaxIntsubtree[1])<<endl;







   
    #ifndef  ONLINE_JUDGE
     clock_t end=clock();
    cout<<"\n\n\n\nExecuted in: "<<double(end-start)/(CLOCKS_PER_SEC*1000)<<" ms"<<endl;
    #endif
   return 0;
}