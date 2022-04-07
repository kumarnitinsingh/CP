// Created by Nitin kumar singh
// problem link -> https://cses.fi/problemset/task/1640/

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
     clock_t start=clock();
     init_code();
    
     //write your code here
        ll n,x;
        cin>>n>>x;
      vector<ll>v(n);
      loop(i,n)cin>>v[i];

       map<ll,int>mp;
      int ans1,ans2;
      int f=0;
      for(int i=0;i<n;i++){
        int k=mp[x-v[i]];

          if( k!=0){
            ans1=i+1;
            ans2=k;
            f=1;
            break;
          }
        
          mp[v[i]]=i+1;;

      }
      if(f==0){cout<<"IMPOSSIBLE"<<endl;}

      else cout<<ans1<<" "<<ans2<<endl;
      

   
    #ifndef  ONLINE_JUDGE
     clock_t end=clock();
    cout<<"\n\n\n\nExecuted in: "<<double(end-start)/(CLOCKS_PER_SEC*1000)<<" ms"<<endl;
    #endif
   return 0;
}