// Created by Nitin kumar singh
// problem link -> https://www.codechef.com/problems/TSHIRTS

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

ll  dp[101][(1<<11)];


ll solve(vector<vector<int>>&v,int i,int n,int mask){
     if(mask==((1<<(n))-1)){
        
        return 1;
     }
    if(i==101){return 0;}

    if(dp[i][mask]!=-1)return dp[i][mask];

     ll ans=0;
     for(auto submask:v[i]){
         if(mask & (1<<(submask-1)))continue;
         ans=(ans+solve(v,i+1,n,mask ^ (1<<(submask-1))))%mod;
     }

       ans=(ans+solve(v,i+1,n,mask))%mod;
     return dp[i][mask]= ans;
}


int main(int argc, char const *argv[])  
{
     clock_t start=clock();
     init_code();
    
     //write your code here

      int t;
      cin>>t;
      while(t--){
        ll n;cin>>n;
        vector<vector<int>>v(101);
        memset(dp,-1,sizeof dp);

        for(int i=0;i<=n;i++){
           string s;
            getline(cin, s);
    
             int data;
            istringstream iss(s);
              while(iss>>data)
                v[data].push_back(i);
        }
        ll ans=solve(v,1,n,0);
        cout<<ans<<endl;

      }

   
    #ifndef  ONLINE_JUDGE
     clock_t end=clock();
    cout<<"\n\n\n\nExecuted in: "<<double(end-start)/(CLOCKS_PER_SEC*1000)<<" ms"<<endl;
    #endif
   return 0;
}