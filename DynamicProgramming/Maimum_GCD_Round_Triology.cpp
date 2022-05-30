// Created by Nitin kumar singh
// problem link -> https://cses.fi/problemset/task/2163/

#include <bits/stdc++.h>

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/trie_policy.hpp>

using namespace std;

using namespace __gnu_pbds;
typedef tree <int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>Set;

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




const long o=(1<<21);
long dp[o][11];

long sol(int n,vector<long>&B,long v,int r){
    
        if(r==n/2 +1){
            return 0;
        }
        if(dp[v][r]!=-1)return dp[v][r];
     int sum=0;
     int maxi=INT_MIN;
      for(long i=0;i<n;i++){
          long s=(1<<i);
          if(v& s)continue;
          v^=s;
        for(long j=0;j<n;j++){
             long k=(1<<j);
            if(v & k)continue;
              v^=k;
            sum=__gcd(B[i],B[j])*r +sol(n,B,v,r+1);
              v^=k;
              maxi=max(maxi,sum);
            
        }  
        v^=s;
        
        
      }
      
      return dp[v][r]=maxi;
}


long f(vector<long>&b,int n){
      multiset<long>st;
     for(auto &a:b)st.insert(a);
      int round=n/2;
    long sum=0;
     while(round>=1){
          long maxi=INT_MIN;
          long a,b;
         for(auto i=st.begin();i!=st.end();i++){
          for(auto j=next(i);j!=st.end();j++){
          
              if(maxi<__gcd(*i,*j)){
                a=*i;
                b=*j;
                maxi=__gcd(a,b);
              }
          }
         }
          st.erase(st.find(a));
          st.erase(st.find(b));
         sum+=maxi*round;
         round--;
     } 
     return sum;
}


int main(int argc, char const *argv[])
{
     clock_t start=clock();
     init_code();
    
     //write your code here

    ll n;
    cin>>n;
   vector<long>B(2*n);
   loop(i,2*n)cin>>B[i];
   memset(dp,-1,sizeof dp);
   long ans=sol(2*n,B,0,1);
   
   cout<<ans<<endl;
          
        
   
    #ifndef  ONLINE_JUDGE
     clock_t end=clock();
    cout<<"\n\n\n\nExecuted in: "<<double(end-start)/(CLOCKS_PER_SEC*1000)<<" ms"<<endl;
    #endif
    
   return 0;


}


