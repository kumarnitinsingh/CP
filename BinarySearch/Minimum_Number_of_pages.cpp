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

bool ispossible(vector<int>books,int m,int limit){
    int cn=1;
    int currentsum=0;
    for(int i=0;i<books.size();i++){
        if(books[i]>limit)return false;
        if(currentsum+books[i]>limit){
            cn++;
            currentsum=books[i];
            if(cn>m)return false;
        }
        else currentsum+=books[i];
    }
    
    return true;
}

int minPages(vector<int> books, int m){
    int ans=INT_MAX;
    //sort(books.begin(),books.end());
    int s=0;int e=accumulate(books.begin(),books.end(),0);
    while(s<=e){
        int mid=(s+e)/2;
        if(ispossible(books,m,mid)){
            ans=min(mid,ans);
            e=mid-1;
        }
        else s=mid+1;
    }
  return ans;
}
int main(int argc, char const *argv[])
{
    clock_t start=clock();
    init_code();
    

    //write your code here

    int n,m;
    cin>>n>>m;
    vector<int>v(n);
    loop(i,n)cin>>v[i];

   
    cout<<minPages(v,m)<<endl;





   
    #ifndef  ONLINE_JUDGE
     clock_t end=clock();
    cout<<"\n\n\n\nExecuted in: "<<double(end-start)/(CLOCKS_PER_SEC*1000)<<" ms"<<endl;
    #endif
   return 0;
}