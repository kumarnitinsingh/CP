// Created by Nitin kumar singh
// problem link -> https://cses.fi/problemset/task/1138/
 
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
    freopen("output2.txt","w",stdout);
    #endif
}
 

 const int ma=2e5+5;
int entry[ma],Exit[ma];
 
int timer=0;
int value[2*ma];
int val[ma];
 vector<int>tree[ma];
 
void dfs(ll src,ll par){
     entry[src]=timer;
     value[timer]=val[src];
     timer++;
     for(auto child:tree[src]){
        if(child!=par){
            dfs(child,src);
        }
     }
     Exit[src]=timer;
     value[timer]=-val[src];
     timer++;
}
 
vector<ll>segtree(8*ma);
 
void build(ll idx,ll s,ll e){
    if(s==e){
        segtree[idx]=value[s];
        return;
    }
   
     ll mid=(s+e)/2;
     build(2*idx,s,mid);
     build(2*idx+1,mid+1,e);
 
     segtree[idx]=segtree[2*idx]+segtree[2*idx+1];
 
}

 
 void update(ll idx,ll s,ll e,ll index,ll val){
    if(index<s or index>e)return;
    if(s==e){
        segtree[idx]=val;
        return;
    }
    ll mid=(s+e)/2;
    update(2*idx,s,mid,index,val);
    update(2*idx+1,mid+1,e,index,val);
    segtree[idx]=segtree[2*idx]+segtree[2*idx+1];
   
 }
 
 
 // ll query(ll idx,ll s,ll e,ll start,ll end){
 //    if(end<s or  start>e)return 0;
   
 //    if(s>=start and e<=end)return segtree[idx];
 //    ll mid=(s+e)/2;
 //     ll left=query(2*idx,s,mid,start,end);
 //     ll right=query(2*idx+1,mid+1,e,start,end);
 //     ll ans= left+right;
 //     return ans;
 
 // }

 ll query(int v, int tl, int tr, int l, int r) {
    if (l > r) 
        return 0;
    if (l == tl && r == tr) {
        return segtree[v];
    }
    int tm = (tl + tr) / 2;
    return query(v*2, tl, tm, l, min(r, tm))
           + query(v*2+1, tm+1, tr, max(l, tm+1), r);
}
 
int main(int argc, char const *argv[])
{
     clock_t start=clock();
     init_code();
    
     //write your code here
 
        ll n,q;cin>>n>>q;
       
        for(int i=1;i<=n;i++){ll x;cin>>x;val[i]=x;}
        for(int i=1;i<n;i++){
            ll x,y;
            cin>>x>>y;
            tree[x].push_back(y);
            tree[y].push_back(x);
        }
        
        dfs(1,-1);
        build(1,0,2*n-1);
        
        while(q--){
 
            ll x;cin>>x;
            if(x==1){
                ll s,y;
                cin>>s>>y;
                ll f=entry[s];
                ll l=Exit[s];
                update(1,0,2*n-1,f,y);
                update(1,0,2*n-1,l,-y);
            }
            else{
                ll y;cin>>y;
                ll f=entry[y];
                ll l=Exit[y];
                ll ans=query(1,0,2*n-1,0,f);
                
                cout<<ans<<endl;
            }
        }
 
 
 
 
   
    #ifndef  ONLINE_JUDGE
     clock_t end=clock();
    cout<<"\n\n\n\nExecuted in: "<<double(end-start)/(CLOCKS_PER_SEC*1000)<<" ms"<<endl;
    #endif
   return 0;
}