// Created by Nitin kumar singh
// problem link -> https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1

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

 void merge(long long arr[],long long  l,long long mid,long long h,long long int& ans){
          long long temp[h-l+1];
          long long i=l,k=0,j=mid+1;
          
          for(;i<=mid and j<=h;){
              if(arr[i]<=arr[j]){
                  temp[k++]=arr[i++];
              }
              else {
                  temp[k++]=arr[j++];
                  ans+=mid-i+1;
              }
          }
          for(;i<=mid;)temp[k++]=arr[i++];
          for(;j<=h;)temp[k++]=arr[j++];
          
          k=0;
          for(long long i=l;i<=h;i++){
              arr[i]=temp[k++];
          }
          
      }
        
          
      
      void mergeSort(long long arr[],long long  l,long long h,long long int& ans){
         // long long int l=0,h=n-1;
          if(l<h){
              long long int mid=l+(h-l)/2;
              mergeSort(arr,l,mid,ans);
              mergeSort(arr,mid+1,h,ans);
              merge(arr,l,mid,h,ans);
          }
      }
    long long int inversionCount(long long arr[], long long n)
    {
        // Your Code Here
        long long int ans=0;
        mergeSort(arr,0,n-1,ans);
        return ans;
    }

int main(int argc, char const *argv[])
{
     clock_t start=clock();
     init_code();
    
     //write your code here





   
    #ifndef  ONLINE_JUDGE
     clock_t end=clock();
    cout<<"\n\n\n\nExecuted in: "<<double(end-start)/(CLOCKS_PER_SEC*1000)<<" ms"<<endl;
    #endif
   return 0;
}