// Created by Nitin kumar singh
#include <bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
//#include<ext/pb_ds/trie_policy.hpp>


//using namespace_-gnu_pbds;
using namespace std;

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



//try to optimie this code to O(NlogN) or possibly O(N);

pair<int,int> subarraySorting(vector<int> a){
    //Expected Optimal Complexity O(n) Time, O(1) Space
    //may be start with O(NLogN) and try to improve
    //complete this function
    int i=0;int j=0;
    pair<int,int>p={INT_MAX,INT_MIN};
    for(j=0;j<a.size();j++){
      i=j-1;
      int x;int y;
      while(i>=0){
        if(a[j]<a[i]){x=i;p.second=max(y,p.second);}
        i--;
        y=j;

      }
      p.first=min(x,p.first);
      

    }

    if(is_sorted(a.begin(),a.end()))return {-1,-1};
    
    return p;
}

int main(int argc, char const *argv[])
{
    clock_t start=clock();
    init_code();
    

    //write your code here
    int n;
    cin>>n;
   // vector<pair<string,int>>v(n+1);
    vector<int>v(n);

    for(int i=0;i<n;i++){
      cin>>v[i];

    }
   
     pair<int,int>p=subarraySorting(v);
     cout<<p.first<<","<<p.second;




   
    #ifndef  ONLINE_JUDGE
     clock_t end=clock();
    cout<<"\n\n\n\nExecuted in: "<<double(end-start)/(CLOCKS_PER_SEC*1000)<<" ms"<<endl;
    #endif
   return 0;
}