// Created by Nitin kumar singh
// problem link -> https://www.spoj.com/problems/RMQSQ/

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




int main(int argc, char const *argv[])
{
     clock_t start=clock();
     init_code();
    
     //write your code here
     ll n;cin>>n;
     vector<ll>arr(n);
     loop(i,n)cin>>arr[i];
     vector<ll>logtbl(n+1,0);
     
     for(int i=2;i<=n;i++){
        logtbl[i]=logtbl[i/2]+1;
     }
      
     ll p=(log(n)/log(2));

     vector<vector<ll>>dp(p+1,vector<ll>(n));

     for(int i=0;i<n;i++) {
            dp[0][i]=arr[i];
     }


     for(int i=1;i<=p;i++){
        for(int j=0;j+(1<<i)<=n;j++){
            ll left=dp[i-1][j];
            ll right=dp[i-1][j+(1<<(i-1))];
            dp[i][j]=min(left,right);
        }
     }

     for(int i=0;i<=p;i++){
        for(int j=0;j<n;j++)cout<<dp[i][j]<<" ";
            cout<<endl;
     }

     ll q;cin>>q;
     while(q--){
        ll l,r;
        cin>>l>>r;
        ll length=r-l+1;
        ll p=logtbl[length];
        ll left=dp[p][l];
        ll right=dp[p][r-(1<<p)+1];
        cout<<min(left,right)<<endl;
     }




   
    #ifndef  ONLINE_JUDGE
     clock_t end=clock();
    cout<<"\n\n\n\nExecuted in: "<<double(end-start)/(CLOCKS_PER_SEC*1000)<<" ms"<<endl;
    #endif
   return 0;
}