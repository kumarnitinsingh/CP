// Created by Nitin kumar singh
#include <bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
//#include<ext/pb_ds/trie_policy.hpp>


//using namespace_-gnu_pbds;
using namespace std;

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
pair<ll,ll>Minimum_Difference_Pair(vector<ll>a,vector<ll>b){
    pair<ll,ll>p;
    ll diff=INT_MAX;
    for(auto x:a){
        auto idx=lower_bound(b.begin(),b.end(),x)-b.begin();
        if(idx>=1 and x-b[idx-1]<diff){diff=x-b[idx-1];p.first=b[idx-1];p.second=x;}
        if(idx!=b.size() and b[idx]-x<diff){diff=b[idx]-x;p.first=x;p.second=b[idx];}
    }
    return p;
}

int main(int argc, char const *argv[])
{
    clock_t start=clock();
    init_code();
    

    //write your code here
  ll n,m;
  cin>>n>>m;
  vector<ll>a(n);
  vector<ll>b(m);
   loop(i,n)cin>>a[i];
   loop(i,m)cin>>b[i];
   sort(b.begin(),b.end());
   pair<ll,ll>p=Minimum_Difference_Pair(a,b);
   cout<<p.first<<","<<p.second;




   
    #ifndef  ONLINE_JUDGE
     clock_t end=clock();
    cout<<"\n\n\n\nExecuted in: "<<double(end-start)/(CLOCKS_PER_SEC*1000)<<" ms"<<endl;
    #endif
   return 0;
}