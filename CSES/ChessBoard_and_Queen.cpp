// Created by Nitin kumar singh
// problem link ->  https://cses.fi/problemset/task/1624/

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
#define vecl            vector<long long>
#define vect           vector<vector<long long>>
#define vecb           vector<vector<bool>>
#define pb             push_back
#define all(n)         n.begin(),n.end()
#define loop(i,n)      for(int i=0;i<(n);++i)
#define loopa(i,a,n)    for(int i=a;i<=(n);++i)
#define loopr(i,a,n)   for(int i=a;i>=(n);--i)
#define sq(x)          x*x
#define cube(x)        x*x*x
#define endl           "\n"


void init_code(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output2.txt","w",stdout);
    #endif
}

    
    bool canplace(vector<vector<int>>&v,int i,int j,int n){
    for(int k=0;k<n;k++){
        if(v[i][k]==1) return false;
        if(v[k][j]==1)return false;
    }
    
    int p=i-1,q=j-1;
    while(p>=0 and q>=0){
        if(v[p][q]==1)return false;
        p--;
        q--;
    }
    p=i-1;q=j+1;
    while(p>=0 and q<n){
         if(v[p][q]==1)return false;
        p--;
        q++;
    }
    
    return true;
    
}

    int  cn=0;
    void solve(vector<string>& grid,vector<vector<int>>&visited,int i ){
         if(i==grid.size()){
            cn++;
            return;
         }


         for(int k=0;k<8;k++){
              if(canplace(visited,i,k,grid.size()) and grid[i][k]!='*'){
                visited[i][k]=1;
                 solve(grid,visited,i+1);
                 visited[i][k]=0;
              }
         }
    }


  
int main(int argc, char const *argv[])
{
     clock_t start=clock();
     init_code();
    
     //write your code 
     vector<string>chess(8);

     for(int i=0;i<8;i++){
        string s;
        cin>>s;
        chess[i]=s;
     }

     vector<vector<int>>visited(8,vector<int>(8,0));
     solve(chess,visited,0);
     cout<<cn<<endl;

   
    #ifndef  ONLINE_JUDGE
     clock_t end=clock();
    cout<<"\n\n\n\nExecuted in: "<<double(end-start)/(CLOCKS_PER_SEC*1000)<<" ms"<<endl;
    #endif
   return 0;
        
}