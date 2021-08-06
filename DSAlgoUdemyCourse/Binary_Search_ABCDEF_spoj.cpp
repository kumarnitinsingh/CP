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
        ll n;cin>>n;
        vector<ll>A(n),B(n),C(n),D(n),E(n),F(n);
        loop(i,n){
            cin>>A[i];
            B[i]=C[i]=D[i]=E[i]=F[i]=A[i];
        }

        vector<ll>pa,ra;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<n;k++){
                    if(D[k]==0)continue;
                    ll temp=(E[i]+F[j])*D[k];
                     pa.push_back(temp);
                }
               
            }
        }
        
          for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<n;k++){
                    
                        ll temp=(A[i]*B[j]+C[k]);
                        ra.push_back(temp);
                    
                }
            }
        }
         ll ans=0;
         sort(ra.begin(),ra.end());
          for(int i=0;i<pa.size();i++){
              
              ll s=lower_bound(ra.begin(),ra.end(),(pa[i]))-ra.begin();
               ll e=upper_bound(ra.begin(),ra.end(),(pa[i]))-ra.begin();
              

                    ans+=(e-s);

          }

        
          cout<<ans<<endl;




   
    #ifndef  ONLINE_JUDGE
     clock_t end=clock();
    cout<<"\n\n\n\nExecuted in: "<<double(end-start)/(CLOCKS_PER_SEC*1000)<<" ms"<<endl;
    #endif
   return 0;
}