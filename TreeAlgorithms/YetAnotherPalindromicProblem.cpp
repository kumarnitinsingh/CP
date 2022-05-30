// Created by Nitin kumar singh
// problem link -> https://www.codechef.com/START39B/problems/ANOTHER_PP

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


ll dp[200005][21];
ll lvl[200005];
string s;

vector<vector<ll>>cn(200001,vector<ll>(26,0));

void level(vector<ll>tree[],ll src,ll par,ll l){
     lvl[src]=l;
     for(auto nbr:tree[src]){
         if(nbr!=par){
            level(tree,nbr,src,l+1);
         }
     }
}

void dfs(vector<ll>tree[],ll src,ll par){
     dp[src][0]=par;
     cn[src]=cn[par];
     cn[src][(int)s[src-1]-'a']++;
     for(int i=1;i<=20;i++){
        if(dp[src][i-1]!=-1){
            dp[src][i]=dp[dp[src][i-1]][i-1];
        }
        else dp[src][i]=-1;
     }
     for(auto nbr:tree[src]){

        if(nbr!=par){
            dfs(tree,nbr,src);
        }
     }
}


ll  uplift(ll u,ll k){
  
    for(ll i=20;i>=0;i--){
         if( k==0 or u==-1)break;
        if(k>=(1<<i)){
             u=(dp[u][i]);
             k-=((1<<i));
        }
    }
    return u;
}

ll lca(ll u,ll v){
    if(lvl[u]<lvl[v])swap(u,v);
  u=  uplift(u,lvl[u]-lvl[v]);

    if(u==v)return u;

    for(int i=20;i>=0;i--){

        if(dp[u][i]!=dp[v][i]){
            u=dp[u][i];
            v=dp[v][i];
        }
    }
    
   return uplift(u,1);
}

int main(int argc, char const *argv[])
{
     clock_t start=clock();
     init_code();
    
     //write your code here

     ll t;cin>>t;
     while(t--){

      ll n;
      cin>>n;
      cin>>s;
      vector<ll>tree[n+1];

      for(int i=2;i<=n;i++){
        ll x,y;cin>>x>>y;
        tree[x].push_back(y);
        tree[y].push_back(x);
      }


      level(tree,1,0,1);
      dfs(tree,1,0);
      ll q;
      cin>>q;


      while(q--){
        ll x,y;cin>>x>>y;
        ll anc=lca(x,y);
        int f=0;

        for(int i=0;i<26;i++){
            if(cn[x][i]-cn[anc][i]>0 and cn[y][i]-cn[anc][i]>0){
                f=1;
            }

        }
        if(f)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
      }


}

   
    #ifndef  ONLINE_JUDGE
     clock_t end=clock();
    cout<<"\n\n\n\nExecuted in: "<<double(end-start)/(CLOCKS_PER_SEC*1000)<<" ms"<<endl;
    #endif
   return 0;
}

