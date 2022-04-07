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


//maximum value at given index K such that -:
//1->  sum of array doesnot exceed maxsum and 
//2->  difference between any two consecutive element of array is atmost 1;
 
 bool possible(long int n,long int maxsum,long int k,long int mid){

      
      
      //optimization;
      long int left=k;
      long int right=n-k-1;
      long int leftsum=0,rightsum=0;
      if(mid>k){
          long int w=(mid*(mid+1)/2);
          long int q=(mid-k-1)*(mid-k)/2;
          leftsum=w-q;
      }
      else {
          long int w=(mid*(mid+1)/2);
         leftsum=w+k-mid+1;
         
      }
      
      if(mid>right){
         long int temp=n-k-1;
          long int w=((mid-1)*mid)/2;
          long int q=((mid-temp-1)*(mid-temp))/2;
          rightsum=w-q;
           
      }
      else {
      long  int temp=n-k-1;
        long int w=((mid-1)*mid)/2;
         rightsum= w+temp-mid+1;
      }
      
      long int total=leftsum+rightsum;
      
      if(total<=maxsum)return true;
      return false;
      
 }
 

long int maxElement(int n, int maxSum, int k) {
      long int low=1;
     long  int high=maxSum;
      long int ans=0;
      while(low<=high){
          long int mid=low+(high-low)/2;
          if(possible(n,maxSum,k,mid)){
              ans=mid;
              low=mid+1;
          }
          else high=mid-1;
      }
      
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