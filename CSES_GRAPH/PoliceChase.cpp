// Created by Nitin kumar singh
// problem link ->  https://cses.fi/problemset/task/1695/

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


const ll maxn =501;
ll n,m;
ll graph[maxn][maxn];
ll capacity[maxn][maxn];
vector<ll>parent(maxn,-1);

ll bfs(){

    fill(parent.begin(),parent.end(),-1);

    vector<ll>visited(maxn,0);

    queue<ll>q;
    q.push(1);
    visited[1]=1;


    while(!q.empty()){
        ll u=q.front();
         q.pop();
        for(ll i=1;i<=n;i++){
            if(visited[i]==0 and graph[u][i]){
                parent[i]=u;
                visited[i]=1;
                q.push(i);
            }

        }
    }
 
    return visited[n];
}


ll maxflow(){
    ll flow;
    ll ans=0;
    
    
     while(bfs()!=0){ 

        ll flow=inf;
        ll cur=n;
        while(cur!=1){
           
            flow=min(flow,graph[parent[cur]][cur]);
            cur=parent[cur];
        }

        ans+=flow;
       
          cur=n;
         while(cur!=1){
            graph[parent[cur]][cur]-=flow;
            graph[cur][parent[cur]]+=flow;
            cur=parent[cur];
         }

     }

     return ans;
}

void dfs(ll src,vector<ll>&vis){
       vis[src]=1;
       for(ll i=1;i<=n;i++){
          if(vis[i]==0 and graph[src][i]){
             dfs(i,vis);
          }
       }
}

int main(int argc, char const *argv[])
{
     //clock_t start=clock();
     init_code();
     memset(capacity,0,sizeof capacity);
     memset(graph,0,sizeof graph);
     cin>>n>>m;
     for(int i=0;i<m;i++){
        ll x,y,z;
        cin>>x>>y;
        graph[x][y]+=1;
        graph[y][x]+=1;
        capacity[x][y]+=1;
        capacity[y][x]+=1;
     }

     ll ans1=maxflow();
     cout<<ans1<<endl;

     vector<ll>vis(maxn,0);
     dfs(1,vis);
     vector<pair<ll,ll>>ans;
     for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(vis[i] and !vis[j] and capacity[i][j])ans.push_back({i,j});
        }
     }

     for(auto e:ans)cout<<e.first<<" "<<e.second<<endl;



   /*
    #ifndef  ONLINE_JUDGE
     clock_t end=clock();
    cout<<"\n\n\n\nExecuted in: "<<double(end-start)/(CLOCKS_PER_SEC*1000)<<" ms"<<endl;
    #endif
    */
   return 0;
}

