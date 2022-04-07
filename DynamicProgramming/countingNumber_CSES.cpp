// Created by Nitin kumar singh
// problem link -> https://cses.fi/problemset/task/2220/

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
    freopen("output2.txt","w",stdout);
    #endif
}


ll dp[101][101][2][2];


ll solve(string & num,ll n,ll last ,ll leading,ll tight,string osf){
    if(n==0){
        //cout<<osf<<endl;
        return 1;

    }

    if(dp[n][last][leading][tight]!=-1)return  dp[n][last][leading][tight];

    ll ub=tight?(num[num.size()-n]-'0'):9;
    ll ans=0;
    for(ll dig=0;dig<=ub;dig++){
        if(dig==last and leading==0)continue;

        ans+=solve(num, n-1,dig,leading and (dig==0),(tight) and (dig==ub),osf+to_string(dig));
    }

    return  dp[n][last][leading][tight]=ans;
   
}

int main(int argc, char const *argv[])
{
     clock_t start=clock();
     init_code();
    
     //write your code here


     ll  x,y;
     cin>>x>>y;
     x--;
     string s=to_string(y);
     string r=to_string(x);
     memset(dp,-1,sizeof dp);
     ll ans=solve(s,s.size(),-1,1,1,"")-1;

     //cout<<endl;
    
     memset(dp,-1,sizeof dp);
      ll ans2=solve(r,r.size(),-1,1,1,"")-1;
    
      cout<<ans-ans2<<endl;






   
    #ifndef  ONLINE_JUDGE
     clock_t end=clock();
    cout<<"\n\n\n\nExecuted in: "<<double(end-start)/(CLOCKS_PER_SEC*1000)<<" ms"<<endl;
    #endif
   return 0;
}