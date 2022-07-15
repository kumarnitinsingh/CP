// Created by Nitin kumar singh
// problem link -> https://www.hackerrank.com/challenges/zero-move-nim/problem?isFullScreen=true

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

int grundy(int n,int zero){
    if(n==0)return 0;
    set<int>st;
    if(zero){
        st.insert(grundy(n,0));
    }
    for(int i=0;i<n;i++){
        st.insert(grundy(i,zero));
    }
    int mex=0;
    while(true){
        if(st.find(mex)!=st.end())mex++;
        else break;
    }
    return mex;
}






int main(int argc, char const *argv[])
{
     //clock_t start=clock();
     init_code();

      int t;
     cin>>t;
     while(t--){
         int n;
         cin>>n;
         vector<int>v(n);
         for(auto &x:v)cin>>x;
         
         int xo=0;
         for(int i=0;i<n;i++){
             xo^=v[i]%2!=0?v[i]+1:v[i]-1;
         }
         if(xo)cout<<"W"<<endl;
         else cout<<"L"<<endl;
     }
      




   /*
    #ifndef  ONLINE_JUDGE
     clock_t end=clock();
    cout<<"\n\n\n\nExecuted in: "<<double(end-start)/(CLOCKS_PER_SEC*1000)<<" ms"<<endl;
    #endif
    */
   return 0;
}