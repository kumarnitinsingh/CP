// Created by Nitin kumar singh
// problem link ->https://www.spoj.com/problems/KQUERYO/

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

struct node{
    vector<ll>arr;
};

void BuildTree(vector<ll>&v,vector<node>&tree,ll s,ll e,ll idx){
    if(s==e){
        tree[idx].arr.push_back(v[s]);
        return;
    }
    ll mid=s+(e-s)/2;
    BuildTree(v,tree,s,mid,2*idx);
    BuildTree(v,tree,mid+1,e,2*idx+1);
    merge(tree[2*idx].arr.begin(),tree[2*idx].arr.end(),tree[2*idx+1].arr.begin(),tree[2*idx+1].arr.end(),back_inserter(tree[idx].arr));
}

ll query(vector<ll>&v,vector<node>&tree,ll s,ll e,ll l,ll r,ll idx,ll k){
    if(r<s or l>e)return 0;

    if(l<=s and e<=r){
        return (tree[idx].arr.size()-(upper_bound(tree[idx].arr.begin(),tree[idx].arr.end(),k)-tree[idx].arr.begin()));
    }

    ll mid=s+(e-s)/2;
    ll left=query(v,tree,s,mid,l,r,2*idx,k);
    ll right=query(v,tree,mid+1,e,l,r,2*idx+1,k);
     return left+right;
}

int main(int argc, char const *argv[])
{
     clock_t start=clock();
     init_code();
    
     //write your code here

     ll  n;cin>>n;
     vector<ll>v(n+1);
     for(int i=1;i<=n;i++){
        cin>>v[i];
     }

     vector<node>tree(4*n+1);
     BuildTree(v,tree,1,n,1);
     ll q;cin>>q;
     ll ans=0;
     while(q--){
        ll i,j,k;
        cin>>i>>j>>k;
        ll l,r;
        l=i^ans;
        r=j^ans;
        k=k^ans;
        ans=query(v,tree,1,n,l,r,1,k);
        cout<<ans<<endl;
     }





   
    #ifndef  ONLINE_JUDGE
     clock_t end=clock();
    cout<<"\n\n\n\nExecuted in: "<<double(end-start)/(CLOCKS_PER_SEC*1000)<<" ms"<<endl;
    #endif
   return 0;
}