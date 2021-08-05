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



int main(int argc, char const *argv[])
{
     clock_t start=clock();
     init_code();
    
     //write your code here
     int t;
     cin>>t;
     while(t--){
       ll n,q;
       cin>>n>>q;
          vector<ll>v(n+1);
          for(int i=1;i<=n;i++)cin>>v[i];
          vector<int>p(n+1);
          int x=0;
          for(int i=1;i<=n;i++){
               if(v[i]&1)v[i]=v[i-1];
                else v[i]=v[i-1]+1;  
          }
 


          while(q--){
               ll l,r;
               cin>>l>>r;
               l=l;
               r=r;
               ll ans=0;
               ll even=v[r]-v[l-1];
               ll odd =r-l+1-even;
               ans+=(even*(even-1)*(even-2)/6)+(odd*(odd-1)*even)/2;

               cout<<ans<<endl;
           
          }

     }





   
    #ifndef  ONLINE_JUDGE
     clock_t end=clock();
    cout<<"\n\n\n\nExecuted in: "<<double(end-start)/(CLOCKS_PER_SEC*1000)<<" ms"<<endl;
    #endif
   return 0;
}