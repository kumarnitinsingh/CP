// Created by Nitin kumar singh
// problem link -> https://cses.fi/problemset/task/2064/
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


const int maxn=2e6+5;
vector<ll>fact(maxn),invfact(maxn);


ll binaryExponentiation(ll x,ll p,ll m){
    ll ans=1;
    while(p){
        if(p&1){
            ans=(ans*x)%mod;
        }
        x=(x*x)%mod;
        p=p>>1;
    }
    return ans;
}

void factorial(){
    invfact[0]=fact[0]=(1);
    for(ll i=1;i<maxn;i++){
        fact[i]=(fact[i-1]*i)%mod;
       
    }

    for(int i=1;i<maxn;i++){
        invfact[i]=binaryExponentiation(fact[i],mod-2,mod);
    }
}



int main(int argc, char const *argv[])
{
     //clock_t start=clock();
     init_code();
     factorial();

        ll t=1;
        //cin>>t;
        while(t--){
            ll n;cin>>n;
            string s;cin>>s;
            if(n%2==1){
                cout<<0<<endl;
                continue;
            }
             
             int x=0,y=0;
             for(auto e:s){
                if(e=='('){x++;y++;}
                else {y--;x++;}
             }  

             //cout<<x<<" "<<y<<endl;
             if(y<0){
                cout<<0<<endl;
                continue;
             }

              ll xcor=abs(n-x);
              ll ycor=abs(0-y);

              ll temp=(xcor+ycor)/2;

              ll nx=x,ny=-2-y;
              ll nxcor=n-nx;
              ll nycor=0-ny;
              ll temp2=(nxcor+nycor)/2;
              ll ans2=(fact[nxcor]*invfact[temp2])%mod;

          //  cout<<xcor<<" "<<temp<<endl;
             ll ans=((fact[xcor]*invfact[temp])%mod);
           //  ans=(ans*binaryExponentiation(n+1,mod-2,mod))%mod;
             cout<<ans-ans2<<endl;

        }




   /*
    #ifndef  ONLINE_JUDGE
     clock_t end=clock();
    cout<<"\n\n\n\nExecuted in: "<<double(end-start)/(CLOCKS_PER_SEC*1000)<<" ms"<<endl;
    #endif
    */
   return 0;
}