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

const int maxn=1e6+5;
vector<int>primes,isprime(maxn,1);

void sieve(ll n){

     isprime[0]=isprime[1];
     for(ll i=2;i<=n;i++){
          if(isprime[i]==0)continue;

          for(ll j=i*i;j<=n;j+=i){
               isprime[j]=0;
          }
     }

     for(ll i=2;i<=n;i++){
          if(isprime[i])primes.push_back(i);
     }

}

int divisors(int n){
     int temp=n+1;
    
     int ans=1;
     auto it=lower_bound(primes.begin(),primes.end(),temp)-primes.begin();
     for( int i=0;i<it and n;i++){
          if(n!=0 and n%primes[i]==0){
               n=n/primes[i];
               ll cn=1;
               while(n!=0 and n%primes[i]==0){
                    n=n/primes[i];
                    cn++;
               }
               ans=ans*(cn+1);
          }

     }
    
     return ans;
}


int main(int argc, char const *argv[])
{
     //clock_t start=clock();
     init_code();
     int total=1e6+5;
     sieve(total);

     int t;
     cin>>t;
     while(t--){
         int n;
         cin>>n;
         int ans=divisors(n);
         cout<<ans<<endl;
     }




   /*
    #ifndef  ONLINE_JUDGE
     clock_t end=clock();
    cout<<"\n\n\n\nExecuted in: "<<double(end-start)/(CLOCKS_PER_SEC*1000)<<" ms"<<endl;
    #endif
    */
   return 0;
}