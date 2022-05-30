// Created by Nitin kumar singh
// problem link -> https://cses.fi/problemset/task/1195

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

const int maxN=2e5+5;
ll n, m;
vector<pair<ll,ll>>graph[maxN],graph1[maxN];
vector<ll>dist(maxN,1e18),dist2(maxN,1e18);




void dijkstra(){
    vector<ll>visited(n+1,0);
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>pq;

    pq.push({0,1});
  
    dist[1]=0;

     while(!pq.empty()){
        pair<ll,ll>p1=pq.top();pq.pop();
        ll u=p1.second;
        if(visited[u])continue;
        visited[u]=1;

        for(auto nbr:graph[u]){
            ll v=nbr.first;
            ll wt=nbr.second;
        
                if(dist[v]>(dist[u]+wt)){
                    dist[v]=dist[u]+wt;
                    pq.push({dist[v],v});
             }
 
        }
     }
}

void dijkstra2(){
    vector<ll>visited(n+1,0);
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>pq;

    pq.push({0,n});
  
    dist2[n]=0;

     while(!pq.empty()){
        pair<ll,ll>p1=pq.top();pq.pop();
        ll u=p1.second;
        if(visited[u])continue;
        visited[u]=1;

        for(auto nbr:graph1[u]){
            ll v=nbr.first;
            ll wt=nbr.second;
        
                if(dist2[v]>(dist2[u]+wt)){
                    dist2[v]=dist2[u]+wt;
                    pq.push({dist2[v],v});
             }
 
        }
     }
}



int main(int argc, char const *argv[])
{
     //clock_t start=clock();
     init_code();
    
     //write your code here

     cin>>n>>m;
     vector<vector<ll>>edges(m+1);
     for(ll i=1;i<=m;i++){
        ll x,y,z;
        cin>>x>>y>>z;
        graph[x].push_back({y,z});
        graph1[y].push_back({x,z});
        edges[i]={x,y,z};
     }

      dijkstra();
      dijkstra2();
      ll ans=1e18;

      for(ll i=1;i<=m;i++){
         vector<ll>edge=edges[i];
         ll a=edge[0];
         ll b=edge[1];
         ll wt=edge[2];

          ll temp=dist[a]+dist2[b]+(wt/2);
          ans =min(ans,temp);
      }

      cout<<ans<<endl;


     




   /*
    #ifndef  ONLINE_JUDGE
     clock_t end=clock();
    cout<<"\n\n\n\nExecuted in: "<<double(end-start)/(CLOCKS_PER_SEC*1000)<<" ms"<<endl;
    #endif
    */
   return 0;
}