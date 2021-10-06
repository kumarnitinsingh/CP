// Created by Nitin kumar singh
// problem link ->https://cses.fi/problemset/task/1648/

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

 void update(vector<ll>&b,ll i,ll inc){
   ll n=b.size();
     while(i<=n){
        b[i]=b[i]+inc;
        i=i+(i&(-i));
     }
 }

 ll sum(vector<ll>&b,ll i){
    ll sum=0;
    while(i>0){
        sum=sum+b[i];
        i=i-(i&(-i));
    }
    return sum;
 }

int main(int argc, char const *argv[])
{
     clock_t start=clock();
     init_code();
    
     //write your code here

     ll n,q;
     cin>>n>>q;
     vec v(n+1);
     loopa(i,1,n)cin>>v[i];

     vec b(n+1,0);
     for(int i=1;i<=n;i++){
     update(b,i,v[i]);
}
     
     while(q--){
        ll type,l,r;cin>>type>>l>>r;
         if(type==1){
            ll x=r-v[l];
            v[l]=r;
            
            update(b,l,x);
         }
         else{

            ll x1=sum(b,r);
            ll x2=sum(b,l-1);
            ll ans=x1-x2;
        cout<<ans<<endl;
     }
     

 }






   
    #ifndef  ONLINE_JUDGE
     clock_t end=clock();
    cout<<"\n\n\n\nExecuted in: "<<double(end-start)/(CLOCKS_PER_SEC*1000)<<" ms"<<endl;
    #endif
   return 0;
}