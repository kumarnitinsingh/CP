// Created by Nitin kumar singh
// problem link -> https://cses.fi/problemset/task/1132

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


ll depth[300000];
void dep(vector<ll>graph[],ll src,ll par){

ll ma=0;

    for(auto nbr:graph[src]){
         if(nbr!=par){
            dep(graph,nbr,src);
            ma=max(ma,1+depth[nbr]);
         }
    }

    depth[src]=ma;
}


ll  ans[300000];
void dfs(vector<ll>graph[],ll src,ll par,ll par_ans){
    vector<ll>prefix,suffix;

    for(auto nbr:graph[src]){
        if(nbr!=par){
            prefix.push_back(depth[nbr]);
            suffix.push_back(depth[nbr]);
        }
    }

    for(int i=1;i<prefix.size();i++){
        prefix[i]=max(prefix[i],prefix[i-1]);
    }
    for(int i=suffix.size()-2;i>=0;i--){
        suffix[i]=max(suffix[i],suffix[i+1]);
    }

    int cn_no=0;
     for(auto nbr:graph[src]){
        if(nbr==par)continue;
        ll left=cn_no==0?INT_MIN:prefix[cn_no-1];
        ll right=cn_no==suffix.size()-1?INT_MIN:suffix[cn_no+1];

         ll partial_ans=1+max(par_ans,max(left,right));
         dfs(graph,nbr,src,partial_ans);
         cn_no++;
     }

      ans[src]=1+max(par_ans,(prefix.size()>0?prefix.back():-1));

       
}



int main(int argc, char const *argv[])
{
     clock_t start=clock();
     init_code();
    
     //write your code here

       
     ll n;cin>>n;
     vector<ll>graph[n+1];

     for(int i=2;i<=n;i++){
         ll x,y;cin>>x>>y;
          graph[x].push_back(y);
          graph[y].push_back(x);
     }
    
       
       
      dep(graph,1,-1);
      dfs(graph,1,-1,-1);
     
      
      
      
     for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
        cout<<endl;


    

     







   
    #ifndef  ONLINE_JUDGE
     clock_t end=clock();
    cout<<"\n\n\n\nExecuted in: "<<double(end-start)/(CLOCKS_PER_SEC*1000)<<" ms"<<endl;
    #endif
   return 0;
}