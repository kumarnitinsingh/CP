// Created by Nitin kumar singh
// problem link -> https://cses.fi/problemset/task/1712/

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
#define vecl            vector<long long>
#define vect           vector<vector<long long>>
#define vecb           vector<vector<bool>>
#define pb             push_back
#define all(n)         n.begin(),n.end()
#define loop(i,n)      for(int i=0;i<(n);++i)
#define loopa(i,a,n)    for(int i=a;i<=(n);++i)
#define loopr(i,a,n)   for(int i=a;i>=(n);--i)
#define sq(x)          x*x
#define cube(x)        x*x*x
#define endl           "\n"


void init_code(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output3.txt","w",stdout);
    #endif
}

ll binaryExponentiation(ll n,ll p,ll mod1){
     ll ans=1;

     while(p){
          if(p&1){
               ans=(ans*(n))%mod1;
          }
           n=(n*n)%mod1;

          p=p>>1;
     }
     return ans;
}



int main(int argc, char const *argv[])
{
     //clock_t start=clock();
     init_code();

     int t;
     cin>>t;
     while(t--){
          ll a,b,c;
          cin>>a>>b>>c;

          //fermat little theorem
          // a^(p-1) % p=1; where p is prime
          
         ll ans=binaryExponentiation(b,c,mod-1);
         ll ans2=binaryExponentiation(a,ans,mod);
         cout<<ans2<<endl;
          
     }




   /*
    #ifndef  ONLINE_JUDGE
     clock_t end=clock();
    cout<<"\n\n\n\nExecuted in: "<<double(end-start)/(CLOCKS_PER_SEC*1000)<<" ms"<<endl;
    #endif
    */
   return 0;
}