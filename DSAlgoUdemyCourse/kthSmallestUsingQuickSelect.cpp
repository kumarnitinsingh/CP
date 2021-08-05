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
int Partition(vector<int>&v,int low,int high){
  int i=low-1;int j=low;
  int x=v[high];
  while(j<high){
    if(v[j]<x){i++;swap(v[i],v[j]);}
    j++;
  }
  swap(v[i+1],v[high]);

  return i+1;
}

int  kthSmallest(vector<int>&v,int low,int high,int k){
  
  int pivot=Partition(v,low,high);
  if(pivot==k)return v[k];
  else if(pivot>k)return kthSmallest(v,low,pivot-1,k);
  
  else{
        return kthSmallest(v,pivot+1,high,k);}
}

int main(int argc, char const *argv[])
{
    clock_t start=clock();
    init_code();
    

    //write your code here
    

     int n,k;
    cin>>n>>k;
   
    vector<int>v(n);
    loop(i,n)cin>>v[i];
    

   cout<<kthSmallest(v,0,n-1,k);
   
    #ifndef  ONLINE_JUDGE
     clock_t end=clock();
    cout<<"\n\n\n\nExecuted in: "<<double(end-start)/(CLOCKS_PER_SEC*1000)<<" ms"<<endl;
    #endif
   return 0;
}