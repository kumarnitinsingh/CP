// Created by Nitin kumar singh
// problem link -> https://www.spoj.com/problems/PR003004/

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


ll dp1[100][2];
ll dp2[100][2];


ll cnt(string &num,ll n,ll tight){

    if(tight==0){
        return pow(10,n)+0.1;
    }
    if(n==0) return 1;

    if(dp1[n][tight]!=-1)return dp1[n][tight];

     ll ub=tight?(num[num.size()-n]-'0'):9;

     ll total=0;

     for(int dig=0;dig<=ub;dig++){
        total+=cnt(num,n-1,tight and (dig==ub));
     }
     return dp1[n][tight]=total;

}

ll  solve(string & num,ll n,ll tight){
    if(n==0)return 0;
     if(dp2[n][tight]!=-1)return dp2[n][tight];

    ll ub=tight?(num[num.size()-n]-'0'):9;
    ll ans=0;

    for(int dig=0;dig<=ub;dig++){
        memset(dp1,-1,sizeof dp1);
        ans+=dig*cnt(num,n-1,tight and (dig==ub));
        ans+=solve(num,n-1,tight and (dig==ub));
    }

    return  dp2[n][tight]=ans;

}

int main(int argc, char const *argv[])
{
     clock_t start=clock();
     init_code();
    
     //write your code here

    ll t;
    cin>>t;
    while(t--){

     ll  x,y;
     cin>>x>>y;
    if(x!=0) x--;
     string s=to_string(y);
     string r=to_string(x);
     memset(dp2,-1,sizeof dp2);
     ll ans=solve(s,s.size(),1);

     //cout<<endl;
    
     memset(dp2,-1,sizeof dp2);
      ll ans2=solve(r,r.size(),1);
    
      cout<<ans-ans2<<endl;

  }






   
    #ifndef  ONLINE_JUDGE
     clock_t end=clock();
    cout<<"\n\n\n\nExecuted in: "<<double(end-start)/(CLOCKS_PER_SEC*1000)<<" ms"<<endl;
    #endif
   return 0;
}