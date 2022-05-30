// Created by Nitin kumar singh
// problem link -> https://cses.fi/problemset/task/1666/

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







void dfs(vector<ll>graph[],ll src,ll par,vector<ll>&visited){
    visited[src]=1;
     for(auto nbr:graph[src]){
        if(nbr!=par ){
            if(visited[nbr]==0){
                dfs(graph,nbr,src,visited);
            }
        }
     }

     return;
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


     vector<ll>visited(n+1,0);
     vector<pair<ll,ll>>ans;

      ll last=-1;
      ll cn=0;

     for(int i=1;i<=n;i++){
        if(visited[i]==0){
              if(last!=-1){
                ans.push_back({last,i});

              }
            last=i;
            cn++;
            dfs(graph,i,-1,visited);

        }
     }

     cout<<cn-1<<endl;
     for(auto e:ans){
        cout<<e.first<<" "<<e.second<<endl;
     }


   /*
    #ifndef  ONLINE_JUDGE
     clock_t end=clock();
    cout<<"\n\n\n\nExecuted in: "<<double(end-start)/(CLOCKS_PER_SEC*1000)<<" ms"<<endl;
    #endif
    */
   return 0;
}