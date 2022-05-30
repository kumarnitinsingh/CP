// Created by Nitin kumar singh
// problem link ->https://cses.fi/problemset/task/1675/

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
    freopen("output3.txt","w",stdout);
    #endif
}


class DSU{
  private:vector<ll>parent,rank;
   public:
    DSU(ll n){
        parent.resize(n);
        rank.resize(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
            rank[i]=1;
        }
    }

    ll Find(ll x){

         if(parent[x]!=x){
             parent[x]=Find(parent[x]);
         }
         return parent[x];
    }

     void Union(ll x,ll y){
        x=Find(x);
        y=Find(y);
         if(x==y)return;

         if(rank[x]>rank[y]){
            parent[y]=x;
         }
         else{
            parent[x]=y;
            if(rank[x]==rank[y])rank[y]++;
         }
         return;

     }

};


class edges{
public:
     ll u, v, wt;
     edges(ll u,ll v,ll wt){
        this->u=u;
        this->v=v;
        this->wt=wt;
     }
};

bool mycom(edges e1,edges e2){
    return e1.wt<e2.wt;
}

ll cn=0;

ll MST(vector<edges>&graph,ll n){
    DSU d(n+1);
    sort(graph.begin(),graph.end(),mycom);

    ll ans=0;

    for(auto edge:graph){
        ll u=edge.u;
        ll v=edge.v;
        ll wt=edge.wt;

        if(d.Find(u)!=d.Find(v)){
            cn++;
            ans=ans+wt;
            d.Union(u,v);
        }

    }
    return ans;

}
int main(int argc, char const *argv[])
{
     clock_t start=clock();
     init_code();
    
     //write your code here

     ll n,m;
     cin>>n>>m;
      vector<edges>graph;  

      for(int i=0;i<m;i++){
        ll u,v,wt;
        cin>>u>>v>>wt;
        edges e(u,v,wt);
        graph.push_back(e);
      }

      ll ans=MST(graph,n+1);

      if(cn!=n-1){cout<<"IMPOSSIBLE"<<endl;return 0;}
      cout<<ans<<endl;




   
    #ifndef  ONLINE_JUDGE
     clock_t end=clock();
    cout<<"\n\n\n\nExecuted in: "<<double(end-start)/(CLOCKS_PER_SEC*1000)<<" ms"<<endl;
    #endif
   return 0;
}