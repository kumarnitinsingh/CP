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

void f();


int main(int argc, char const *argv[])
{
     clock_t start=clock();
     init_code();
    
       vector<ll>temp;
       for(ll i=0;i<100000;i++){
          ll k=i*i;
          temp.push_back(k);
       }   
      ll t;
      cin>>t;
      while(t--){
          ll n;
          cin>>n;
          vector<ll>v(n);
          loop(i,n)cin>>v[i];


          vector<pair<ll,ll>>ans;
          for(int i=0;i<n;i++){
               ll op2=*upper_bound(temp.begin(),temp.end(),v[i]);
               ll p=sqrt(op2);
               ll op1=(p-1)*(p-1);

               ll temp1=abs(op1-v[i]);
               ll temp2=abs(op2-v[i]);

               ans.push_back({min(temp1,temp2),v[i]});
          }

          sort(ans.begin(),ans.end());

          ll f=0;
          for(ll i=0;i<n/2;i++){
               f+=ans[i].first;
          }

          for(ll i=n/2;i<n;i++){
               if(binary_search(temp.begin(),temp.end(),ans[i].second)){
                    if(ans[i].second==0)f+=2;
                    else f+=1;
               }
          }

          cout<<f<<endl;
      }



   
    #ifndef  ONLINE_JUDGE
     clock_t end=clock();
    cout<<"\n\n\n\nExecuted in: "<<double(end-start)/(CLOCKS_PER_SEC*1000)<<" ms"<<endl;
    #endif
   return 0;
}

void f(){
     cout<<"faltu"<<endl;
}