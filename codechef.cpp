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
            // your code goes here
    int t;
    cin>>t;
    while(t--){
      ll n,p,k;
      cin>>n>>p>>k;
     // if(k>n){cout<<k<<endl;continue;}
      //if(p%k==0){cout<<(p/k)+1<<endl;continue;}

       ll x=((n-1)/k)+1;


       

        ll rows=(p%k)-1;

        ll op=(n-1)-((n-1)/k)*k;

        ll totalrow=k;
        if(op>=rows){
            unsigned ll temp=rows*x;
           unsigned  ll ans=temp+x+(p/k)+1;
            cout<<ans<<endl;
            continue;
        }
        else{
             unsigned temp=op*x;
             unsigned temp2=(rows-op)*(x-1);
       unsigned ll ans=temp+temp2+x+(p/k)+1;
        cout<<ans<<endl;
  }

      
    }



   
    #ifndef  ONLINE_JUDGE
     clock_t end=clock();
    cout<<"\n\n\n\nExecuted in: "<<double(end-start)/(CLOCKS_PER_SEC*1000)<<" ms"<<endl;
    #endif
   return 0;
}