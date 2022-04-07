// Created by Nitin kumar singh
// problem link -> https://cses.fi/problemset/task/1093/

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


const int maxN=101,maxM=100001;
int arr[maxN];
int n;
    

int main(int argc, char const *argv[])
{
     clock_t start=clock();
     init_code();
    
     //write your code here
     
       cin>>n;
        int sum=(n*(n+1)/2);
       if(sum%2!=0){cout<<0<<endl;return 0;}
     
      vector<vector<int>>dp(n+1,vector<int>(sum/2 + 1,0));

      dp[0][0]=1;
      for(int i=1;i<=n;i++){
        for(int j=0;j<sum/2 +1;j++){
            dp[i][j]=dp[i-1][j];
            int left=j-i;
            if(left>=0 ){
                dp[i][j]=(dp[i][j]+dp[i-1][left])%mod;
            }
        }
      }
             

      cout<<dp[n-1][sum/2]<<endl;

    #ifndef  ONLINE_JUDGE
     clock_t end=clock();
    cout<<"\n\n\n\nExecuted in: "<<double(end-start)/(CLOCKS_PER_SEC*1000)<<" ms"<<endl;
    #endif
   return 0;
}