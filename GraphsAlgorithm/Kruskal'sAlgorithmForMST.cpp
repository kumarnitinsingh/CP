// Created by Nitin kumar singh
// problem link ->https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1

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


class DSU{
  private:vector<int>parent,rank;
   public:
    DSU(int n){
        parent.resize(n);
        rank.resize(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
            rank[i]=1;
        }
    }

    int Find(int x){

         if(parent[x]!=x){
             parent[x]=Find(parent[x]);
         }
         return parent[x];
    }

     void Union(int x,int y){
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
     int u, v, wt;
     edges(int u,int v,int wt){
        this->u=u;
        this->v=v;
        this->wt=wt;
     }
};

bool mycom(edges e1,edges e2){
    return e1.wt<e2.wt;
}

int MST(vector<edges>&graph,int n){
    DSU d(n);
    sort(graph.begin(),graph.end(),mycom);

    int ans=0;

    for(auto edge:graph){
        int u=edge.u;
        int v=edge.v;
        int wt=edge.wt;

        if(d.Find(u)!=d.Find(v)){
            ans+=wt;
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

     int n,m;
     cin>>n>>m;
      vector<edges>graph;  

      for(int i=0;i<m;i++){
        int u,v,wt;
        cin>>u>>v>>wt;
        edges e(u,v,wt);
        graph.push_back(e);
      }

      int ans=MST(graph,n+1);
      cout<<ans<<endl;




   
    #ifndef  ONLINE_JUDGE
     clock_t end=clock();
    cout<<"\n\n\n\nExecuted in: "<<double(end-start)/(CLOCKS_PER_SEC*1000)<<" ms"<<endl;
    #endif
   return 0;
}