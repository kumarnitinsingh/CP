// Created by Nitin kumar singh
// problem link -> https://cses.fi/problemset/task/1642

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
    
     //write your code here

     ll n,k;
     cin>>n>>k;
     vector<pair<ll,ll>>v(n);
     loop(i,n){ll x;cin>>x;
        v[i]={x,i+1};}
     map<pair<ll,ll>,ll>mp;
     for(int i=1;i<=n;i++)mp[v[i-1]]=i;



     sort(v.begin(),v.end());
     int f=0;

     for(int i=0;i<n-3;i++){
        for(int j=i+1;j<n-2;j++){
           
        int l=j+1;
        int h=n-1;
        ll sum=v[i].first+v[j].first;
         ll left=k-sum;
         while(l<h){
            ll temp=v[l].first+v[h].first;
            if(temp==left){
                cout<<mp[v[i]]<<" "<<mp[v[j]]<<" "<<mp[v[l]]<<" "<<mp[v[h]]<<endl;
                f=1;
                break;

            }
            else if(temp>left){
                h--;
            }
            else{
                l++;
            }
         }

         if(f)break;
     } 

     if(f)break;

 }

     
     if(f==0)cout<<"IMPOSSIBLE"<<endl;



   /*
    #ifndef  ONLINE_JUDGE
     clock_t end=clock();
    cout<<"\n\n\n\nExecuted in: "<<double(end-start)/(CLOCKS_PER_SEC*1000)<<" ms"<<endl;
    #endif
    */
   return 0;
}