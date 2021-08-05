// Created by Nitin kumar singh
// problem link ->

#include <bits/stdc++.h>

//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
//#include<ext/pb_ds/trie_policy.hpp>

using namespace std;

//using namespace __gnu_pbds;
//typedef tree <int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>Set;

//find_by_order(k) and order_of_key(k)



#define ll             unsigned long long int
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

vector<ll>V;

bool ispalindrome(ll n){
    string s=to_string(n);
    if(s.size()%2==0)return false;

    int i=0;int j=s.size()-1;
    while(i<=j){
        if(s[i]!=s[j])return false;
        i++;
        j--;
    }

    return true;

}


 ll FastModulo(ll x,ll p,ll m){
   ll ans=1;
  while(p>0){
    if(p&1){
      ans=((ans%m)*(x%m))%m;
    }
    x=((x%m)*(x%m))%m;
    p=p>>1;
  }
  return ans;
 }

void PA(){
    for(ll i=1;i<10000000;i++){
        if(to_string(i).size()%2==0)i=i*10;
        
        if(ispalindrome(i)){
            V.push_back(i);
        }
    }
}


int main(int argc, char const *argv[])
{
     clock_t start=clock();
     init_code();
    
     //write your code here

    //    PA();
        
    //     int t;cin>>t;
    // while(t--){

    //     ll l,r;
    // cin>>l>>r;
    //  ll ans=1;
    //  for(int i=l;i<r;i++){
      
    //     ans=((ans%mod)*(FastModulo(V[l-1],V[i],mod))%mod)%mod;
    //  }
    //  cout<<ans%mod<<endl;
     cout<<"jkkk";



   
    #ifndef  ONLINE_JUDGE
     clock_t end=clock();
    cout<<"\n\n\n\nExecuted in: "<<double(end-start)/(CLOCKS_PER_SEC*1000)<<" ms"<<endl;
    #endif
   return 0;
}