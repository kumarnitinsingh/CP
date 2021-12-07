// Created by Nitin kumar singh
// problem link ->

#include <bits/stdc++.h>

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/trie_policy.hpp>

using namespace std;

using namespace __gnu_pbds;
typedef tree <int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>Set;

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

 void merge(vec& arr,long long  left,long long mid,long long right,long long int& ans){
        //   long long temp[h-l+1];
        //   long long i=l,k=0,j=mid+1;

        //    for(ll p=mid+1;p<=h;p++){
        //        ll q=l;ll cn=0;
        //     while(q<=mid and arr[q] < 2LL*arr[p]){
        //         q++;
                
        //     }
        //     ans += mid-q+1;
        // }
          
        //       // int p,cn=0;
        //       //  for( p=i;p<=mid;p++){
        //       //     if(arr[p]>2*arr[j])cn++;
        //       // }
        //       // ans+=cn;
        //   for(;i<=mid and j<=h;){
           
        //       if(arr[i]<=arr[j]){
        //           temp[k++]=arr[i++];
        //       }

        //       else {
        //           temp[k++]=arr[j++];
                 
        //       }
        //   }
        //   for(;i<=mid;)temp[k++]=arr[i++];
        //   for(;j<=h;)temp[k++]=arr[j++];
          
        //   k=0;
        //   for(long long i=l;i<=h;i++){
        //       arr[i]=temp[k++];
        //   }


           vector<ll>temp(right-left+1);    
      
        ll i = left;
        ll j = mid;
        ll k = left;
        for(i=left;i<=mid;i++){
            while(j<=right and arr[i] > 2LL*arr[j]){
                j++;
            }
            ans += (j - mid);
        }
        i = left,j=mid;
        while((i <= mid-1) && (j <= right)){
            if(arr[i] <= arr[j]){
                temp[k++]=arr[i++];
            }
            else
            {
                temp[k++] = arr[j++];
            }
        }

        while(i <= mid - 1)
            temp[k++]=arr[i++];

        while(j <= right)
            temp[k++]=arr[j++];

        for(i = left ; i <= right ; i++)
            arr[i] = temp[i];

        
          
      }
        
          
      
      void mergeSort(vec &arr,long long  l,long long h,long long int& ans){
         // long long int l=0,h=n-1;
          if(l<h){
              long long int mid=l+(h-l)/2;
              mergeSort(arr,l,mid,ans);
              mergeSort(arr,mid+1,h,ans);
              merge(arr,l,mid,h,ans);
          }
      }
    long long int inversionCount(vec& arr, long long n)
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

     int n;cin>>n;
      vector<ll>v(n);
      loop(i,n)cin>>v[i];

         
        long long ans=0;
        mergeSort(v,0,n-1,ans);
        cout<<ans<<endl;         
      
          








   
    #ifndef  ONLINE_JUDGE
     clock_t end=clock();
    cout<<"\n\n\n\nExecuted in: "<<double(end-start)/(CLOCKS_PER_SEC*1000)<<" ms"<<endl;
    #endif
   return 0;
}



