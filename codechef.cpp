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

ll lis(vector<ll>&v,ll n){
   vector<ll>dp(n+1,INT_MAX);

   ll ans=1;
   dp[0]=INT_MIN;

   for(int i=0;i<n;i++){

       
      // for(int j=0;j<n;j++){

      //    if(dp[j]<v[i] and v[i]<dp[j+1]){
      //       dp[j+1]=v[i];
      //    }}

      //instead of above commented for loop we can use binary search to reduce complexity from O(n^2) to O(nlogn)

         auto it=upper_bound(dp.begin(),dp.end(),v[i])-dp.begin();
         if(dp[it-1]<v[i] and v[i]<dp[it]){
      //       dp[j+1]=v[i];
              dp[it]=v[i];
          }
       
      
   
      }

      for(int i=1;i<=n;i++){
         if(dp[i]!=INT_MAX)ans=i;
      }


   return ans;
}



int main(int argc, char const *argv[])
{
     clock_t start=clock();
     init_code();
    
     //write your code here

     ll n;cin>>n;
     vector<ll>v(n);
     loop(i,n)cin>>v[i];

     ll ans=lis(v,n);
      cout<<ans<<endl;





   
    #ifndef  ONLINE_JUDGE
     clock_t end=clock();
    cout<<"\n\n\n\nExecuted in: "<<double(end-start)/(CLOCKS_PER_SEC*1000)<<" ms"<<endl;
    #endif
   return 0;
}