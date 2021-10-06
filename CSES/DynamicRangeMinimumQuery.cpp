// Created by Nitin kumar singh
// problem link ->https://cses.fi/problemset/task/1649

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

void build(vector<ll>&tree,vector<ll>&v,ll s,ll e,ll idx){
    if(s==e){
        tree[idx]=v[s];
        return;}

    ll mid=(s+e)/2;

    build(tree,v,s,mid,2*idx);
    build(tree,v,mid+1,e,2*idx+1);

    tree[idx]=min(tree[2*idx],tree[2*idx+1]);
    return;

}

ll query(vector<ll>&tree,ll s,ll e,ll l,ll r ,ll idx){
    
     if(l<=s and e<=r)return tree[idx];
      if(l>e or r<s)return INT_MAX;
    

     ll mid=(e+s)/2;
     ll left=query(tree,s,mid,l,r,2*idx);
     ll right=query(tree,mid+1,e,l,r,2*idx+1);

     return min(left,right);
}



void update(vector<ll>&tree,ll s,ll e,ll i,ll up,ll idx){
     if(i<s or i>e) return;
    if(s==e){
        tree[idx]=up;return;
    }
   

    ll mid=(s+e)/2;
    update(tree,s,mid,i,up,2*idx);
    update(tree,mid+1,e,i,up,2*idx+1);

    tree[idx]=min(tree[2*idx],tree[2*idx+1]);
    return;
}


int main(int argc, char const *argv[])
{
     clock_t start=clock();
     init_code();
    
     //write your code here

     ll n,q;cin>>n>>q;
     vec v(n+1);
     loopa(i,1,n)cin>>v[i];
     vector<ll>tree(4*n+1);

     build(tree,v,1,n,1);

     while(q--){
        ll type,l,r;cin>>type>>l>>r;

        if(type==1){

            update(tree,1,n,l,r,1);
        }
        else{
        ll ans=query(tree,1,n,l,r,1);
        cout<<ans<<endl;
    }
     }





   
    #ifndef  ONLINE_JUDGE
     clock_t end=clock();
    cout<<"\n\n\n\nExecuted in: "<<double(end-start)/(CLOCKS_PER_SEC*1000)<<" ms"<<endl;
    #endif
   return 0;
}