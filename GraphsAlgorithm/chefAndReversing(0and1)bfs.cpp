// Created by Nitin kumar singh
// problem link -> https://www.codechef.com/problems/REVERSE

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
vector<pair<ll,ll>>graph[maxN];
ll n,m;



ll bfs(){
    vector<ll>visited(n+1,0),dist(n+1,1e9);
    deque<ll>q;

    q.push_back(1);
    dist[1]=0;

    while(!q.empty()){
        ll u=q.front();q.pop_front();

         for(auto nbr:graph[u]){
             if(dist[nbr.first]>(dist[u]+nbr.second)){
                dist[nbr.first]=dist[u]+nbr.second;
                if(nbr.second==0)q.push_front(nbr.first);
                else q.push_back(nbr.first);
                
             }
         }
    }
    return dist[n]==1e9?-1:dist[n];
}

int main(int argc, char const *argv[])
{
     //clock_t start=clock();
     init_code();
    
     //write your code here

     cin>>n>>m;
     for(int i=0;i<m;i++){
        ll x,y;
        cin>>x>>y;
         graph[x].push_back({y,0});
         graph[y].push_back({x,1});
     }


        cout<<bfs()<<endl;


     




   /*
    #ifndef  ONLINE_JUDGE
     clock_t end=clock();
    cout<<"\n\n\n\nExecuted in: "<<double(end-start)/(CLOCKS_PER_SEC*1000)<<" ms"<<endl;
    #endif
    */
   return 0;
}