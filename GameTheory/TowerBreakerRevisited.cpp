// Created by Nitin kumar singh
// problem link -> https://www.hackerrank.com/challenges/tower-breakers-revisited-1/problem?isFullScreen=true

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


const int n=1e6+1;
 int pr_sum[n];
 void sieve(){
     vector<int>primes(n,1);
     primes[0]=primes[1]=0;
     
     for(ll i=2;i<n;i++){
         if(primes[i]==0)continue;
          pr_sum[i]=1;
         for(ll j=i*2;j<n;j+=i){
             ll jj=j;
            
             while(jj%i==0){
                 jj/=i;
                 pr_sum[j]++;
                 
             }
             primes[j]=0;
         }
     }
 }



int main(int argc, char const *argv[])
{
     //clock_t start=clock();
     init_code();


     sieve();
    
    int t;
    cin>>t;
    while(t--){
        int sz;
        cin>>sz;
        vector<int>v(sz);
        for(auto &x:v)cin>>x;
        
        int xo=0;
        
        for(int i=0;i<sz;i++){
            xo^=pr_sum[v[i]];
        }
        if(xo)cout<<1<<endl;
        else cout<<2<<endl;
    }



   /*
    #ifndef  ONLINE_JUDGE
     clock_t end=clock();
    cout<<"\n\n\n\nExecuted in: "<<double(end-start)/(CLOCKS_PER_SEC*1000)<<" ms"<<endl;
    #endif
    */
   return 0;
}