// Created by Nitin kumar singh
// problem link -> https://codeforces.com/problemset/problem/161/D

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

vector<int> tree[50001];
int dp1[50001][501], dp2[50001][501];
 
void dfs(int src, int par, int& k)
{
    for(int child : tree[src]){
        if(child != par)
            dfs(child, src, k);
    }


 
    dp1[src][0] = 1;
    for(int distance = 1; distance <= k; distance++)
    {
        dp1[src][distance] = 0;
        for(int child : tree[src])
            if(child != par)
                dp1[src][distance] += dp1[child][distance-1];
    }
}
 
void solve(int src, int par, int& k)
{
    for(int dis = 0; dis <= k; dis++)
        dp2[src][dis] = dp1[src][dis];
 
    if(par != 0)
    {
       dp2[src][1] += dp2[par][0];
       for(int dis = 2; dis <= k; dis++)
       {
           dp2[src][dis] += dp2[par][dis - 1];
           dp2[src][dis] -= dp1[src][dis - 2];
       }
    }
 
    for(int child : tree[src])
        if(child != par)
            solve(child, src, k);
}




int main(int argc, char const *argv[])
{
     clock_t start=clock();
     init_code();
    
     //write your code here

     
     int n,k;cin>>n>>k;
     

     for(int i=2;i<=n;i++){
         int x,y;cin>>x>>y;
          tree[x].push_back(y);
          tree[y].push_back(x);
     }
    
       
       
       dfs(1,0,k);
      solve(1,0,k);
     
      
      ll ans=0;
      
     for(int i=1;i<=n;i++)ans+=dp2[i][k];

        ans=ans/2;

        cout<<ans<<endl;


    

     







   
    #ifndef  ONLINE_JUDGE
     clock_t end=clock();
    cout<<"\n\n\n\nExecuted in: "<<double(end-start)/(CLOCKS_PER_SEC*1000)<<" ms"<<endl;
    #endif
   return 0;
}