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

  void BuildTree(vector<ll>&v,ll s,ll e ,vector<ll>&tree,ll idx){
    // base case
       if(s==e){
        tree[idx]=v[s];
        return;
       }

        ll mid=(s+e)/2;
       BuildTree(v,s,mid,tree,2*idx);
       BuildTree(v,mid+1,e,tree,2*idx+1);

       tree[idx]=min(tree[2*idx],tree[2*idx+1]);

       return ;
  }

  

     void LazyUpdate(vector<ll>&tree,ll s,ll e,ll l,ll r,ll inc,ll idx,vector<ll>&lazy){
        //resolving lazy value
        if(lazy[idx]!=0){
            tree[idx]+=lazy[idx];
            if(s!=e){
                lazy[2*idx]+=lazy[idx];
                lazy[2*idx+1]+=lazy[idx];
            }
            lazy[idx]=0;
        }

        //no overlap
        if(r<s or e<l)return;
         
         //complete overlap
        if(s>=l and e<=r){
            tree[idx]+=inc;
            if(s!=e){
            lazy[2*idx]+=inc;
            lazy[2*idx+1]+=inc;
        }
            return;
        }

            ll mid=(s+e)/2;
            LazyUpdate(tree,s,mid,l,r,inc,2*idx,lazy);
            LazyUpdate(tree,mid+1,e,l,r,inc,2*idx+1,lazy);

            tree[idx]=min(tree[2*idx],tree[2*idx+1]);
            return;

     }

ll lazyQuery(vector<ll>&tree,ll s,ll e,ll l,ll r,ll idx,vector<ll>&lazy){
     if(lazy[idx]!=0){
            tree[idx]+=lazy[idx];
            if(s!=e){
                lazy[2*idx]+=lazy[idx];
                lazy[2*idx+1]+=lazy[idx];
            }
            lazy[idx]=0;
        }

        //no overlap
        if(r<s or e<l)INT_MAX;
        if(s>=l and e<=r)return tree[idx];

        ll mid=(s+e)/2;
        ll left=lazyQuery(tree,s,mid,l,r,2*idx,lazy);
        ll right=lazyQuery(tree,mid+1,e,l,r,2*idx+1,lazy);
          return min(left,right);
        
}


int main(int argc, char const *argv[])
{
     clock_t start=clock();
     init_code();
    
     //write your code here
     ll n;cin>>n;
     vector<ll>v(n);
     loop(i,n)cin>>v[i];
     vector<ll>tree(4*n+1);

     BuildTree(v,0,n-1,tree,1);
     cout<<query(tree,0,n-1,2,3,1);







   
    #ifndef  ONLINE_JUDGE
     clock_t end=clock();
    cout<<"\n\n\n\nExecuted in: "<<double(end-start)/(CLOCKS_PER_SEC*1000)<<" ms"<<endl;
    #endif
   return 0;
}