// Created by Nitin kumar singh
// problem link -> squareroot decomposition (range sum query);

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


void buildBlockArray(vector<ll>&v,ll n,vec &b,ll bs){
     int block_idx=-1;
     for(int i=0;i<n;i++){
          if(i%bs==0)block_idx++;
          b[block_idx]+=v[i];
     }
}

ll query(vec &v,vec &b,ll rn,ll l,ll r){
     ll ans=0;

     //left part
     while(l<r and l!=0 and l%rn!=0){
          ans+=v[l];
          l++;
     }
     //middle part
       while(l+rn<=r){
           ll block_idx=l/rn;
            ans+=b[block_idx];
            l+=rn;
       }

       // right part
       while(l<=r){
          ans+=v[l];
          l++;
       }


       return ans;
}

void update(vec& v,vec &b,ll rn,ll i,ll val){
        
          b[i/rn]+=(val-v[i]);
            v[i]=val;

}

int main(int argc, char const *argv[])
{
     clock_t start=clock();
     init_code();
    
     //write your code here
     ll t;cin>>t;
          while(t--){
               ll n;cin>>n;
               vector<ll>v(n);
               loop(i,n)cin>>v[i];
               ll bs=sqrt(n);
               vector<ll>b(bs+1,0);
               buildBlockArray(v,n,b,bs);

               cout<<query(v,b,bs,2,4)<<endl;

               update(v,b,bs,3,10);

               cout<<query(v,b,bs,2,4)<<endl;

          }





   
    #ifndef  ONLINE_JUDGE
     clock_t end=clock();
    cout<<"\n\n\n\nExecuted in: "<<double(end-start)/(CLOCKS_PER_SEC*1000)<<" ms"<<endl;
    #endif
   return 0;
}