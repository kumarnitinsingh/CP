// Created by Nitin kumar singh
// problem link -> https://www.codechef.com/START49B/problems/MONKS

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

bool ispossible(vector<ll>&v,ll n,ll mid,vector<ll>&prefix){
    
    ll temp=v[n-mid]*(n-mid);

    ll total=prefix[n-mid];

    ll req=temp-total;

    ll left=prefix[n]-prefix[n-mid];
   
    if(req>left)return false;
    return true;
}

ll solve(vector<ll>&v,ll n,vector<ll>&prefix){
    ll low=0;
    ll high=n;
    ll ans=INT_MAX;
    while(low<=high){
       ll mid=low+(high-low)/2;

       if(ispossible(v,n,mid,prefix)){
        ans=min(ans,mid);
        high=mid-1;
       }
       else low=mid+1;
    }

    return ans;
}



int main(int argc, char const *argv[])
{
     //clock_t start=clock();
     init_code();


     int t;
     cin>>t;
     while(t--){
       
        ll n;
        cin>>n;
        vector<ll>v(n+1);
        for(int i=1;i<=n;i++)cin>>v[i];
        sort(v.begin(),v.end());
        vector<ll>prefix(v);
        for(int i=1;i<=n;i++)prefix[i]+=prefix[i-1];

        ll ans=solve(v,n,prefix);
        cout<<ans<<endl;

     }



   /*
    #ifndef  ONLINE_JUDGE
     clock_t end=clock();
    cout<<"\n\n\n\nExecuted in: "<<double(end-start)/(CLOCKS_PER_SEC*1000)<<" ms"<<endl;
    #endif
    */
   return 0;
}