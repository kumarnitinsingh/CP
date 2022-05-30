// Created by Nitin kumar singh
// problem link -> https://cses.fi/problemset/task/1690/

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



ll n,m;
ll mat[21][21];

ll visited;
ll dp[1<<21][21];

ll solve(ll mask,ll pos){
    if(pos==n-1){
        if(mask==visited)return 1;
        return 0;
    }
   

    if(dp[mask][pos]!=-1)return dp[mask][pos];

 ll ans=0;
    for(ll i=0;i<n;i++){
      
          if((mask&(1<<i))==0 and mat[pos][i]){
            ans=(ans+solve(mask^(1<<i),i))%mod;
            ans=(mat[pos][i]*ans)%mod;
          }
    }


    return dp[mask][pos]=ans;
}




int main(int argc, char const *argv[])
{
     //clock_t start=clock();
     init_code();
    
     //write your code here
     memset(mat,0,sizeof mat);

     cin>>n>>m;
     for(int i=1;i<=m;i++){
        ll x,y;
       
        cin>>x>>y;
         x--;
         y--;
        mat[x][y]+=1;
     }

     memset(dp,-1,sizeof dp);

     visited=(1<<n)-1;

     ll ans=solve(1,0);
     cout<<ans<<endl;





   /*
    #ifndef  ONLINE_JUDGE
     clock_t end=clock();
    cout<<"\n\n\n\nExecuted in: "<<double(end-start)/(CLOCKS_PER_SEC*1000)<<" ms"<<endl;
    #endif
    */
   return 0;
}