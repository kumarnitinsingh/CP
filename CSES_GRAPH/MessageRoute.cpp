// Created by Nitin kumar singh
// problem link -> https://cses.fi/problemset/task/1667

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







vector<ll> bfs(vector<ll>graph[],ll n){

    vector<ll>dist(n+1,-1);
     vector<ll>visited(n+1,0),par(n+1,-1);

     queue<ll>q;
     q.push(1);
     visited[1]=1;
     dist[1]=0;
     par[1]=1;

     while(!q.empty()){
         ll node=q.front();q.pop();

         for(auto nbr :graph[node]){
              if(visited[nbr]==0){
                  visited[nbr]=1;
                  par[nbr]=node;
                  dist[nbr]=1+dist[node];
                  q.push(nbr);
              }
         }
     }

     vector<ll>ans;
     ans.push_back(dist[n]);
     while(par[n]!=n and par[n]!=-1){
        ans.push_back(n);
        n=par[n];
        
     }
     ans.push_back(n);
     reverse(ans.begin()+1,ans.end());

     return ans;



}



int main(int argc, char const *argv[])
{
     //clock_t start=clock();
     init_code();
    
     //write your code here
     ll n,m;
     cin>>n>>m;
     vector<ll>graph[n+1];
     for(int i=0;i<m;i++){
         ll x,y;
         cin>>x>>y;
         graph[x].push_back(y);
         graph[y].push_back(x);
     }

     vector<ll>ans=bfs(graph,n);
     if(ans[0]==-1){
        cout<<"IMPOSSIBLE"<<endl;
     }
     else {
        cout<<ans.size()-1<<endl;
        for(int i=1;i<ans.size();i++)cout<<ans[i]<<" ";
            cout<<endl;
     }
   


   /*
    #ifndef  ONLINE_JUDGE
     clock_t end=clock();
    cout<<"\n\n\n\nExecuted in: "<<double(end-start)/(CLOCKS_PER_SEC*1000)<<" ms"<<endl;
    #endif
    */
   return 0;
}