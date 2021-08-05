// Created by Nitin kumar singh
// problem link ->  https://cses.fi/problemset/task/1687/

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
vector<vector<int>>up(200000+1,vector<int>(30));



void dfs(int cur,int par,vector<int>g[]){
          up[cur][0]=par;
            
          for(int i=1;i<20;i++){
            if(up[cur][i-1]!=-1)
            up[cur][i]=up[up[cur][i-1]][i-1];
            else
                up[cur][i]=-1;
          }
          for(auto node:g[cur]){
             if(par!=node){
                dfs(node,cur,g);
             }
          }
}


int lca(int u,int k){
      if(u==-1 || k==0)return u;
       for(int i=19;i>=0;i--){
        if(k>=(1<<i)){return lca(up[u][i],k-(1<<i));}
       }
    
    return 0;
}

int main(int argc, char const *argv[])
{
     clock_t start=clock();
     init_code();
    
     //write your code here
     //input graph
     /*20 18
        1 2
        1 3
        2 4
        2 5
        3 10
        3 11
        5 6
        10 17
        11 12
        6 7
        6 8
        6 9
        17 18
        17 19
        12 13
        12 14
        12 15
        15 16
*/


     int n,q;
     cin>>n>>q;
     vector<int>g[n+2];
     vector<int>v(n);
     v[0]=1;
      for(int i=1;i<n;i++){
        cin>>v[i];
      }
      int j=2;
      vector<pair<int,int>>edges(n);

     for(int i=1;i<n;i++){
          edges.push_back({v[i],j});
          j++;

     }
        
        for(auto ed:edges){
            g[ed.first].push_back(ed.second);
            g[ed.second].push_back(ed.first);
        }

  

     dfs(1,-1,g); 


     while(q--){
        int x,y;
        cin>>x>>y;
      cout<<lca(x,y)<<endl;

}

   
    #ifndef  ONLINE_JUDGE
     clock_t end=clock();
    cout<<"\n\n\n\nExecuted in: "<<double(end-start)/(CLOCKS_PER_SEC*1000)<<" ms"<<endl;
    #endif
   return 0;
}

