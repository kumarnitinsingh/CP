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


class mycom{
public:
// bool operator()(pair<ll,ll>p1,pair<ll,ll>p2){
//      if(p1.second>p2.second)return true;
//      else return p1.first>p2.first;
// }

     template <typename T>
  
    // Comparator function
    bool operator()(const T& l,
                    const T& r) const
    {
        if (l.second > r.second) {
            return true;
        }
        return l.first < r.first;
    }
};

int main(int argc, char const *argv[])
{
     clock_t start=clock();
     init_code();
    
     //write your code here

     int t;cin>>t;
     while(t--){
        ll n,m;
        cin>>n>>m;
         map<ll,ll>mp;
       // vector<pair<ll,ll>>mp(m+1);
        for(int i=1;i<=m;i++){
            ll x,y;
            cin>>x>>y;
           // mp.push_back({x,y});
            mp[y]=max(mp[y],x);
        }
         //sort(mp.begin(),mp.end(),mycom);
          set<pair<ll, ll>, mycom> S(mp.begin(),
                                   mp.end());
          // for(auto x:S){
          //   cout<<x.second<<" "<<x.first<<endl;
          
  
         ll ans=0;
            unordered_map<ll,ll>v;
            auto f=S.begin();
              ll t1=f->second;
              ll t2=f->first;
              ans+=(n-n/t2)*t1;
              f++;
              ll last =t2;
         for(auto it=f;it!=S.end();it++){
            vector<ll>temp;
            ll x=it->second;
            ll y=it->first;
            n=n/last;
              ans+=(abs(n-n/y))*x;
             
             // ans-=(n/last)+;
         
               // for(int i=last;i<=n;i+=last){
               //    // if(i%t2!=0)continue;
               //    if(i%y==0 ||  v[i]!=0)continue;
               //     else{
               //      ans+=x;
               //      v[i]=x;

               //  }
               // }
               last=y; 
         }
          cout<<ans<<endl;

     }





   
    #ifndef  ONLINE_JUDGE
     clock_t end=clock();
    cout<<"\n\n\n\nExecuted in: "<<double(end-start)/(CLOCKS_PER_SEC*1000)<<" ms"<<endl;
    #endif
   return 0;
}