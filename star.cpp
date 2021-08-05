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
     
     init_code();
    
     //write your code here

     ll t;cin>>t;
     while(t--){
        ll n;cin>>n;
        vector<ll>v;
        for(int i=0;i<n;i++){
            ll x;cin>>x;
            v.push_back(x);
        }
        ll sum=0;
        for(int i= 0;i<n;i++)sum=sum+v[i];
      // if(sum%n==0)cout<<0<<endl;continue;
        

        ll avg=sum/n;

        ll left=(sum-avg*n);
        cout<<(left*(n-left))<<endl;
      

     }





   
  
   return 0;
}