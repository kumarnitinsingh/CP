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

bool IsDivideAmong_K(vector<ll>v,ll n,ll k, ll limit){
  ll cn=0;ll current_sum=0;
  for(int i=0;i<n;i++){
    if(current_sum+v[i]>=limit){
        cn++;
        current_sum=0;
    }
    else current_sum+=v[i];

  }
  return cn>=k;
}

ll k_Partition(vector<ll>v,ll n,ll k){
    ll s=0;ll val=0;ll ans=0;

    for(ll i=0;i<n;i++)val+=v[i];
        ll e=val;

    while(s<=e){
        ll mid=(s+e)/2;
        if(IsDivideAmong_K(v,n,k,mid)){
            ans=mid;
            s=mid+1;
        }
        else e=mid-1;
    }
    return ans;
}
int main(int argc, char const *argv[])
{
    clock_t start=clock();
    init_code();
    

    //write your code here

    ll n,k;
    cin>>n>>k;
    vector<ll>v(n);
    loop(i,n)cin>>v[i];

    sort(v.begin(),v.end());

    cout<<k_Partition(v,n,k)<<endl;





   
    #ifndef  ONLINE_JUDGE
     clock_t end=clock();
    cout<<"\n\n\n\nExecuted in: "<<double(end-start)/(CLOCKS_PER_SEC*1000)<<" ms"<<endl;
    #endif
   return 0;
}