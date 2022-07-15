// Created by Nitin kumar singh
// problem link -> https://www.hackerrank.com/challenges/alice-and-bobs-silly-game/problem?isFullScreen=true

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





int main(int argc, char const *argv[])
{
     //clock_t start=clock();
     init_code();

        int n=1e5+1;
     
     int prime[n];
     memset(prime,1,sizeof prime);
     prime[0]=prime[1]=0;
     
     for(int i=2;i<n;i++){
         if(!prime[i])continue;
         for(int j=i*i;j<n;j+=i){
             prime[j]=0;
         }
     }
     for(int i=2;i<n;i++)prime[i]+=prime[i-1];
     
      int t;
      cin>>t;
      while(t--){
          int sz;
          cin>>sz;
          if(prime[sz]%2==0){
              cout<< "Bob"<<endl;
          }
          else cout<< "Alice" <<endl;
      }





   /*
    #ifndef  ONLINE_JUDGE
     clock_t end=clock();
    cout<<"\n\n\n\nExecuted in: "<<double(end-start)/(CLOCKS_PER_SEC*1000)<<" ms"<<endl;
    #endif
    */
   return 0;
}