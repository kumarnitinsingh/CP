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


// O(N*N)
void merge( vector<ll>ar1,vector<ll>ar2,ll m,ll n){
     for(ll i=n-1;i>=0;i--){

          ll j;ll last=ar1[m-1];

          for(j=m-2;j>=0 and ar1[j]>ar2[i] ;j--){
               ar1[j+1]=ar1[j];
          }

          if(last>ar2[i] || m-2!=j){
               ar1[j+1]=ar2[i];
               ar2[i]=last;
          }
     }
}

//optimised way (n+m)*log(m+n);

void merge2( vector<ll>& ar1,vector<ll>& ar2,ll m,ll n){
  ll k=m+n;
  ll gap=ceil((m+n)/2);

   while(gap>=1){
      ll i=0;
      ll j=gap;

      while(j<n+m){
          if(i<m and j<m and ar1[i]>ar1[j]){
              

               swap(ar1[i],ar1[j]);
          } 
          else if(i<m and j>=m and j<m+n and ar1[i]>ar2[j-m]){
            
              swap(ar1[i],ar2[j-m]);
          }
          else if(i>=m and j>=m and j<m+n and ar2[i-m]>ar2[j-m]){
             
              swap(ar2[i-m],ar2[j-m]);
          }
          i++;j++;
          
      } 
      gap=ceil(gap/2);
   }
}

//insertionsort Type approach
void merge3(int arr1[], int arr2[], int n, int m)
{
 for (int i = 0; i < n; i++)
 {
  bool flag = 0;
  if (arr1[i] > arr2[0])
  {
   flag = 1;
   swap(arr1[i], arr2[0]);
  }
  if (flag)
  {
   sort(arr2, arr2 + m);
  }
 }
}

//My method;O(NlogN)+O(MlogM)

    void merge4(int arr1[], int arr2[], int n, int m) {
        // code here
        

           int i=n-1,j=0;
          while(i>=0 && j<m) {
            if(arr1[i]>arr2[j]){
             swap(arr1[i],arr2[j]);}
               i--;
               j++;
            }

sort(arr1,arr1+n);
sort(arr2,arr2+m);
    
    }

int main(int argc, char const *argv[])
{
     clock_t start=clock();
     init_code();
    
     //write your code here
   ll m,n;cin>>m>>n;
     vector<ll>v1(m);loop(i,m)cin>>v1[i];
     vector<ll>v2(n);loop(i,n)cin>>v2[i];
     merge2(v1,v2,m,n);

     for(int i=0;i<m;i++)cout<<v1[i]<<" ";
     for(int i=0;i<n;i++)cout<<v2[i]<<" ";     

       





   
    #ifndef  ONLINE_JUDGE
     clock_t end=clock();
    cout<<"\n\n\n\nExecuted in: "<<double(end-start)/(CLOCKS_PER_SEC*1000)<<" ms"<<endl;
    #endif
   return 0;
}