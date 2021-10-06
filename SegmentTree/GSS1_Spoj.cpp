// Created by Nitin kumar singh
// problem link ->https://www.spoj.com/problems/GSS1/

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
  
  class node{
  public:
    ll presum;
    ll suffixsum;
    ll totalSum;
    ll maxsum; 

    node(){
        presum=INT_MIN;
        suffixsum=INT_MIN;
        totalSum=INT_MIN;
        maxsum=INT_MIN;
    }
  };


  void BuildTree(vector<ll>&v,vector<node>&tree,ll s,ll e,ll idx){
      if(s==e){
        tree[idx].presum=v[s];
        tree[idx].suffixsum=v[s];
        tree[idx].totalSum=v[s];
        tree[idx].maxsum=v[s];
        return;
      }

      ll mid=s+ (e-s)/2;
      BuildTree(v,tree,s,mid,2*idx);
      BuildTree(v,tree,mid+1,e,2*idx+1);

      tree[idx].presum=max(tree[2*idx].totalSum+tree[2*idx+1].presum,tree[2*idx].presum);
      tree[idx].suffixsum=max(tree[2*idx+1].totalSum+tree[2*idx].suffixsum,tree[2*idx+1].suffixsum);
      tree[idx].totalSum=tree[2*idx].totalSum+tree[2*idx+1].totalSum;
      tree[idx].maxsum=max(tree[2*idx].maxsum,max(tree[2*idx+1].maxsum,tree[2*idx].suffixsum+tree[2*idx+1].presum));
      return;
  }

  node query(vector<ll>&v,vector<node>&tree,ll s,ll e,ll l,ll r,ll idx){
       if(r<s or l>e)return  node();
       //complete overlap
       if(l<=s and e<=r){
           return tree[idx];
       }
       ll mid=s+ (e-s)/2;
       node left=query(v,tree,s,mid,l,r,2*idx);
       node right=query(v,tree,mid+1,e,l,r,2*idx+1);
       node temp;
       temp.presum=max(left.totalSum+right.presum,left.presum);
       temp.suffixsum=max(right.totalSum+left.suffixsum,right.suffixsum);
       temp.totalSum=left.totalSum+right.totalSum;
       temp.maxsum=max(left.maxsum,max(right.maxsum,left.suffixsum+right.presum));
       return temp;
  }


int main(int argc, char const *argv[])
{
     clock_t start=clock();
     init_code();
    
     //write your code here

     ll n;cin>>n;
     vector<ll>v(n+1);
     for(int i=1;i<=n;i++)cin>>v[i];

        vector<node>tree(4*n+1);

      BuildTree(v,tree,1,n,1);  
      
      ll m;cin>>m;
      while(m--){
        ll l,r;cin>>l>>r;

        node ans=query(v,tree,1,n,l,r,1);
        cout<<ans.maxsum<<endl;

      }  





   
    #ifndef  ONLINE_JUDGE
     clock_t end=clock();
    cout<<"\n\n\n\nExecuted in: "<<double(end-start)/(CLOCKS_PER_SEC*1000)<<" ms"<<endl;
    #endif
   return 0;
}