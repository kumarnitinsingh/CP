// Created by Nitin kumar singh
// problem link -> https://cses.fi/problemset/task/1196/

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
ll n, m,k;
vector<pair<ll,ll>>graph[maxN];
vector<vector<ll>>dist(maxN);




void dijkstra(){
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>pq;

    pq.push({0,1});
  

     while(!pq.empty()){
        pair<ll,ll>p1=pq.top();pq.pop();
        ll u=p1.second;
        if(dist[u].size()>k)continue;
       
        dist[u].push_back(p1.first);
        for(auto nbr:graph[u]){
            ll v=nbr.first;
            ll wt=nbr.second;
        
                
                    ll dis=p1.first+wt;
                    pq.push({dis,v});
             
 
        }
     }
}



int main(int argc, char const *argv[])
{
     //clock_t start=clock();
     init_code();
    
     //write your code here
     
     cin>>n>>m>>k;
     for(int i=1;i<=m;i++){
        ll x,y,z;
        cin>>x>>y>>z;
        graph[x].push_back({y,z});
        //graph[y].push_back({x,z});
     }

      dijkstra();

      sort(dist[n].begin(),dist[n].end());
       for(auto e:dist[n]){
          if(k)cout<<e<<" ";
          k--;
       }




   /*
    #ifndef  ONLINE_JUDGE
     clock_t end=clock();
    cout<<"\n\n\n\nExecuted in: "<<double(end-start)/(CLOCKS_PER_SEC*1000)<<" ms"<<endl;
    #endif
    */
   return 0;
}