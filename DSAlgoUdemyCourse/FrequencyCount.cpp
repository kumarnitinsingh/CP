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

// bool mycom(pair<string,int>p1,pair<string,int>p2){
//     return p1.second<p2.second;
// }
// int badness(vector<pair<string,int> > teams){
//     //Complete this function to return the min badness
//      int ans=0;
//      sort(teams.begin(),teams.end(),mycom);
//     for(int i=1;i<=teams.size();i++){
//       int x=teams[i].second;
//       if(i!=x)ans++;
//      // else ans+=x-i;
//     }
       
//     return ans;
       
    
    
// }



int FrequencyCount(vector<int>v,int k){
  int s=0;int e=v.size()-1;
 
  int x=-1;
  while(s<=e){
     int mid=(s+e)/2;
     if(v[mid]==k)x=mid;
     if(v[mid]<=k)s=mid+1;
     else e=mid-1;
  }
  int y=-1; e=v.size()-1;s=0;
  while(s<=e){
    int mid=(s+e)/2;
    if(v[mid]==k)y=mid;
    if(v[mid]>=k)e=mid-1;
    else s=mid+1;
  }

 if(x==-1 and y==-1)return 0;
  return x-y+1;
}

int main(int argc, char const *argv[])
{
    clock_t start=clock();
    init_code();
    

    //write your code here
    int n,k;
    cin>>n>>k;
   // vector<pair<string,int>>v(n+1);
    vector<int>v(n);

    for(int i=0;i<n;i++){
      cin>>v[i];

    }
   
     cout<<FrequencyCount(v,k);


   
    #ifndef  ONLINE_JUDGE
     clock_t end=clock();
    cout<<"\n\n\n\nExecuted in: "<<double(end-start)/(CLOCKS_PER_SEC*1000)<<" ms"<<endl;
    #endif
   return 0;
}