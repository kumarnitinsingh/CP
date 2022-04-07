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

 //Given a tree T of N nodes, calculate longest path between any two nodes(also known as diameter of tree).

ll F[100],G[100];

void dfs(vector<ll>graph[], ll src,ll par,ll& diameter){

    vector<ll>temp;
    for(auto nbr:graph[src]){
        if(nbr==par)continue;
        dfs(graph,nbr,src,diameter);
        temp.push_back(F[nbr]);
    }

    sort(temp.begin(),temp.end());
     if(temp.size()!=0){
        F[src]=1+temp.back();
     }
      if(temp.size()>1){
        G[src]=2+temp.back()+temp[temp.size()-2];
      }

      diameter=max(diameter,max(F[src],G[src]));

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
     
      memset(F,0,sizeof F);
      memset(G,0,sizeof G);
      ll diameter=0;
      dfs(graph,1,-1,diameter);

       cout<<diameter<<endl;







   
    #ifndef  ONLINE_JUDGE
     clock_t end=clock();
    cout<<"\n\n\n\nExecuted in: "<<double(end-start)/(CLOCKS_PER_SEC*1000)<<" ms"<<endl;
    #endif
   return 0;
}