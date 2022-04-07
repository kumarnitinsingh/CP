// Created by Nitin kumar singh
// problem link -> https://www.codechef.com/LTIME104B/problems/PREZ

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

 ll ispossible(ll n,string s){
    ll add=0;
    for(int i=n;i>=0;i--){
        int v=((s[i]-'0')+add)%10;
        if(v==0)continue;
        add+=10-v;
    }
    return add;
 }

 ll binarySearch(ll n,string s,ll k){
    ll l=0,h=n-1;

    while(l<=h){
        ll mid=l+(h-l)/2;

        if(ispossible(mid,s)>k){
            h=mid-1;
        }
        else l=mid+1;
    }
    return l;
 }

int main(int argc, char const *argv[])
{
     clock_t start=clock();
     init_code();
    
     //write your code here

     ll t;
     cin>>t;
     while(t--){
        ll n,k;
        cin>>n>>k;
        string s;
        cin>>s;
         ll ans=binarySearch(n,s,k);
       
           cout<<ans<<endl;

       }





   
    #ifndef  ONLINE_JUDGE
     clock_t end=clock();
    cout<<"\n\n\n\nExecuted in: "<<double(end-start)/(CLOCKS_PER_SEC*1000)<<" ms"<<endl;
    #endif
   return 0;
}