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

 vector<string>v;
    void ratInmaze(vector<vector<int>>s,vector<vector<bool>>&visited,int i,int j,int n,string ans){
   if(i==n-1 and j==n-1){
       v.push_back(ans);
       return;
   }
   if(s[i][j]==0)return;
    visited[i][j]=true;
    if(j+1<n and !visited[i][j+1] and s[i][j+1]==1){
      ratInmaze(s,visited,i,j+1,n,ans+"R");
    }
     if(i+1<n and !visited[i+1][j] and s[i+1][j]==1){
      ratInmaze(s,visited,i+1,j,n,ans+"D");
    }
     if(i-1>=0 and !visited[i-1][j] and s[i-1][j]==1){
      ratInmaze(s,visited,i-1,j,n,ans+"U");
    }
     if(j-1>=0 and !visited[i][j-1] and s[i][j-1]==1){
      ratInmaze(s,visited,i,j-1,n,ans+"L");
    }
    visited[i][j]=false;
}

    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<vector<bool>>visited(n,vector<bool>(n,false));
        ratInmaze(m,visited,0,0,n,"");
        if(v.size()==0)return {"-1"};
        sort(v.begin(),v.end());
        return v;
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