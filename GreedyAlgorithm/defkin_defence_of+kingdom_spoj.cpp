// Created by Nitin kumar singh
// problem link ->https://www.spoj.com/problems/DEFKIN/

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

bool mycom(pair<string,ll> p1,pair<string,ll>p2){
      return p1.second<p2.second;
}

int main(int argc, char const *argv[])
{
     clock_t start=clock();
     init_code();
    
     //write your code here

           
         
         ll t;
         cin>>t;
        
          while(t--){
                
               ll w,h,n;
               cin>>w>>h>>n;
               if(n!=0){
               vector<ll>width(n),height(n);
               loop(i,n){cin>>width[i]>>height[i];};
               sort(width.begin(),width.end());
               sort(height.begin(),height.end());

               vector<ll>fiwi,fihi;
               fihi.push_back(height[0]-1);
               fiwi.push_back(width[0]-1);
               for(int i=1;i<n;i++){
                    ll x=width[i]-width[i-1]-1;
                    ll y=height[i]-height[i-1]-1;
                    fiwi.push_back(x);
                    fihi.push_back(y);
               }
               fiwi.push_back(w-width[n-1]);
               fihi.push_back(h-height[n-1]);
              

               ll mx=*max_element(fiwi.begin(),fiwi.end());
               ll my=*max_element(fihi.begin(),fihi.end());

               ll ans=mx*my;
               cout<<ans<<endl;
          }
          else cout<<(w)*(h)<<endl;

}


   
    #ifndef  ONLINE_JUDGE
     clock_t end=clock();
    cout<<"\n\n\n\nExecuted in: "<<double(end-start)/(CLOCKS_PER_SEC*1000)<<" ms"<<endl;
    #endif
   return 0;
}