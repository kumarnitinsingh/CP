// Created by Nitin kumar singh
// problem link -> https://atcoder.jp/contests/dp/tasks/dp_r

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



vector<vector<ll>> multiply(vector<vector<ll>>& a,vector<vector<ll>>& b){
    ll n=a.size();
    vector<vector<ll>>c(n,vector<ll>(n,0));

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){

            for(int k=0;k<n;k++){
                c[i][j]=(c[i][j]%mod+((a[i][k])*b[k][j])%mod)%mod;
            }
        }
    }
    return c;
}

vector<vector<ll>> MatrixExponentiation(vector<vector<ll>>&grid,ll n,ll k){
    if(k==1){
        return grid;
    }

    if(k&1){
         vector<vector<ll>>temp=MatrixExponentiation(grid,n,k-1);
          return multiply(grid,temp);
    }

    else{
        vector<vector<ll>>temp=MatrixExponentiation(grid,n,k/2);
         return multiply(temp,temp);
    }
}


int main(int argc, char const *argv[])
{
     clock_t start=clock();
     init_code();
    
     //write your code here
   //  memset(dp,-1,sizeof dp);
     ll n,k;cin>>n>>k;
     vector<vector<ll>>grid(n,vector<ll>(n));
      
     for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>grid[i][j];
        }
     } 

     vector<vector<ll>>adj=MatrixExponentiation(grid,n,k);

     ll ans2=0;

     for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){

            ans2=(ans2%mod+(adj[i][j])%mod)%mod;
        }
     }

     cout<<ans2<<endl;



   
    #ifndef  ONLINE_JUDGE
     clock_t end=clock();
    cout<<"\n\n\n\nExecuted in: "<<double(end-start)/(CLOCKS_PER_SEC*1000)<<" ms"<<endl;
    #endif
   return 0;
}