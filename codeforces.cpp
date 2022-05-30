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


void subsetSum(vector<ll>&v,ll i,ll n,ll sum,vector<ll>&temp){
    if(i==n){
        temp.push_back(sum);
        return ;

    }

    subsetSum(v,i+1,n,sum,temp);
    subsetSum(v,i+1,n,sum+v[i],temp);
}







int main(int argc, char const *argv[])
{
     //clock_t start=clock();
     init_code();
    
     //write your code here


      ll n,x;
      cin>>n>>x;
       ll k=n-n/2;
      vector<ll>v1(n/2),v2(k);
     
      loop(i,n/2)cin>>v1[i];
      loop(i,k)cin>>v2[i];

      ll sum=0;
      vector<ll>left;
      subsetSum(v1,0,n/2,sum,left);
      sum=0;
      vector<ll>right;
      subsetSum(v2,0,k,sum,right);


      sort(right.begin(),right.end());
      ll ans=0;

      for(auto e:left){

          ans+=upper_bound(right.begin(),right.end(),x-e)-lower_bound(right.begin(),right.end(),x-e);
      }

      cout<<ans<<endl;



   /*
    #ifndef  ONLINE_JUDGE
     clock_t end=clock();
    cout<<"\n\n\n\nExecuted in: "<<double(end-start)/(CLOCKS_PER_SEC*1000)<<" ms"<<endl;
    #endif
    */
   return 0;
}