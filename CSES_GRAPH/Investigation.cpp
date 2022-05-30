// Created by Nitin kumar singh
// problem link -> https://cses.fi/problemset/task/1202/

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
vector<pair<ll,ll>>graph[maxN];
vector<ll>dist(maxN,1e18),rou(maxN,0),min_f(maxN,INT_MAX),max_f(maxN,INT_MAX);




void dijkstra(){
    vector<ll>visited(n+1,0);
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>pq;

    pq.push({0,1});
  
    dist[1]=0;
    rou[1]=1;
    min_f[1]=0;
    max_f[1]=0;

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
                    rou[v]=rou[u];
                    min_f[v]=min_f[u]+1;
                    max_f[v]=max_f[u]+1;
             }

              else if(dist[v]==dist[u]+wt){
                   rou[v]=(rou[v]+rou[u])%mod;
                   min_f[v]=min(min_f[v],min_f[u]+1);
                   max_f[v]=max(max_f[v],max_f[u]+1);
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
     for(int i=1;i<=m;i++){
        ll x,y,z;
        cin>>x>>y>>z;
        graph[x].push_back({y,z});
        //graph[y].push_back({x,z});
     }

      dijkstra();


        cout<<dist[n]<<" "<<rou[n]<<" "<<min_f[n]<<" "<<max_f[n]<<endl;




   /*
    #ifndef  ONLINE_JUDGE
     clock_t end=clock();
    cout<<"\n\n\n\nExecuted in: "<<double(end-start)/(CLOCKS_PER_SEC*1000)<<" ms"<<endl;
    #endif
    */
   return 0;
}