// Created by Nitin kumar singh
// problem link -> https://cses.fi/problemset/task/2413/

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
    freopen("output2.txt","w",stdout);
    #endif
}

const int maxN=1e6+5, maxM=2;
 unsigned int dp[maxN][maxM];



int main(int argc, char const *argv[])
{
     clock_t start=clock();
     init_code();
    
     //write your code here
     

     memset(dp,0,sizeof dp);

     dp[1][0]=dp[1][1]=1;

     for(int i=2;i<maxN;i++){

        dp[i][0]=((4*dp[i-1][0])%mod +dp[i-1][1])%mod;
        dp[i][1]=((2*dp[i-1][1])%mod + dp[i-1][0])%mod;
     }

        int t;cin>>t;
        while(t--){
     int n;
     cin>>n;

     cout<<(dp[n][0]+dp[n][1])%mod<<endl;
    ;

 }






   
    #ifndef  ONLINE_JUDGE
     clock_t end=clock();
    cout<<"\n\n\n\nExecuted in: "<<double(end-start)/(CLOCKS_PER_SEC*1000)<<" ms"<<endl;
    #endif
   return 0;
}