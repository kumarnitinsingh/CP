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

//T=O(N^2)
vector<pair<int,int>>solve(vector<int>v,int n,int k){
    int i=0;int j=i;
   int ans=0;
   vector<pair<int,int>>result;
    for( ;i<n;i++){
        j=i;
        ans=0;
       while(ans<=k){
        ans+=v[j];
        j;
        if(ans==k){result.push_back(pair<int,int>(i,j));}
        j++;
            if(ans>k)break;
       }
    }

    return result;
}


//using sliding window concept T=O(N);
vector<pair<int,int>>slidingWindow(vector<int>v,int n,int k){
    int i=0;int j=0;
   int ans=0;
   vector<pair<int,int>>result;
    for( ;i<n and j<n;){
        
          if(ans<k){ ans+=v[j];j++;}      

         if(ans==k){result.push_back(pair<int,int>(i,j-1)); ans-=v[i];i++;}
      
         if(ans>k){ans-=v[i];i++;}
       
      
       
        
           
       
    }

    return result;
}
bool mycom(pair<int,int>p1,pair<int,int>p2){
    return (p1.second-p1.first)<(p2.second-p2.first);
}

int main(int argc, char const *argv[])
{
    clock_t start=clock();
    init_code();
    

    //write your code here

    int n,k;
    cin>>n>>k;
    vector<int>v(n);
    for(int i=0;i<n;i++){cin>>v[i];}

        vector<pair<int,int>> ans=solve(v,n,k);

    for(int i=0;i<ans.size();i++){
        cout<<ans[i].first<<", "<<ans[i].second<<endl;
    }


    sort(ans.begin(),ans.end(),mycom);

   cout<<endl<<ans[0].first<<", "<<ans[0].second<<endl;

   
    #ifndef  ONLINE_JUDGE
     clock_t end=clock();
    cout<<"\n\n\n\nExecuted in: "<<double(end-start)/(CLOCKS_PER_SEC*1000)<<" ms"<<endl;
    #endif
   return 0;
}