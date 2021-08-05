// Created by Nitin kumar singh
// problem link ->

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

void dfs(vector<int>g[],int src,vector<bool>&visited,int n,int &ans){
        visited[src]=true;
        ans++;

          for(int i=1;i<=n;i++){

                if(find(g[src].begin(),g[src].end(),i)==g[src].end() and visited[i]==false)dfs(g,i,visited,n,ans);
            
         }
         return;
}


int main(int argc, char const *argv[])
{
     clock_t start=clock();
     init_code();
    
     //write your code here

     ll n,m;
     cin>>n>>m;

     vector<int>g[n+1];
     while(m--){
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
     }
     
     //for(int i=1;i<=n;i++)g[i][i]=false;


     // vector<int>Graph[n+1];
     // for(int i=1;i<=n;i++){
     //    for(int j=1;j<=n;j++){
     //       if(g[i][j]==true)Graph[i].push_back(j);
     //    }
        
     // }

     ll cn=0;
     vector<bool>visited(n+1,false);
     vector<int>temp;
     for(int i=1;i<=n;i++){
        if(visited[i]==false){
            cn++;
            int ans=0;
            dfs(g,i,visited,n,ans);
            temp.push_back(ans);
        }
     }

     sort(temp.begin(),temp.end());
    cout<<cn<<endl;
    for(auto x:temp)cout<<x<<" ";



   
    #ifndef  ONLINE_JUDGE
     clock_t end=clock();
    cout<<"\n\n\n\nExecuted in: "<<double(end-start)/(CLOCKS_PER_SEC*1000)<<" ms"<<endl;
    #endif
   return 0;
}