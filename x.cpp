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
     int t;
     cin>>t;
     while(t--){
        ll n,d;
        cin>>n>>d;
        vector<pair<ll,ll>>p(n);
        vector<ll>s(n);
        loop(i,n){cin>>p[i].first;p[i].second=i;}
        loop(i,n)cin>>s[i];
        ll ans=0;
        sort(p.begin(),p.end());
         ll tt=upper_bound(p.begin(),p.end(),d)-p.begin();
        for(int i=0;i<tt;i++){
             if(p[i].first>d)continue;
             ans=max(ans,s[p[i].second]);
              ll wq=upper_bound(p.begin()+i,p.end(),d-p[i].first)-p.begin();
            for(int j=i+1;j<wq;j++){
                     if(p[j].first>d){continue;}
                    if((p[i].first+p[j].first)>d){ans=max(ans,max(s[p[i].second],s[p[j].second]));continue;}
                    ans=max(ans,s[p[i].second]+s[p[j].second]);
            }
        }
        cout<<ans<<endl;
     }





   
    #ifndef  ONLINE_JUDGE
     clock_t end=clock();
    cout<<"\n\n\n\nExecuted in: "<<double(end-start)/(CLOCKS_PER_SEC*1000)<<" ms"<<endl;
    #endif
   return 0;
}