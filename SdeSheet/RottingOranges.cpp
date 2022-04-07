// Created by Nitin kumar singh
// problem link -> https://leetcode.com/problems/rotting-oranges/

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

 int orangesRotting(vector<vector<int>>& grid) {
        
        int m=grid.size();
        int n=grid[0].size();
        int g=0;
        vector<pair<int,int>>v;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){v.push_back({i,j});}
                if(grid[i][j]==1)g++;
            }
        }
        
        int cn=0;
        if(g==0)return 0;

        int k=1000;
        while(g and k--){
        bool f=0;
            vector<pair<int,int>>v1;
        for(int l=0;l<v.size();l++){
             
            int i=v[l].first;
            int j=v[l].second;
              
             if(i-1>=0 and grid[i-1][j]==1){
                
                 grid[i-1][j]=2;
                 v1.push_back({i-1,j});
                 g--;
                 f=1;
             }
              if(i+1<m and grid[i+1][j]==1){
               
                 grid[i+1][j]=2;
                 v1.push_back({i+1,j});
                  g--;
                  f=1;
             }
              if(j-1>=0 and grid[i][j-1]==1){
             
                 grid[i][j-1]=2;
                 v1.push_back({i,j-1});
                  g--;
                  f=1;
             }
              if(j+1<n and grid[i][j+1]==1){
                 
                 grid[i][j+1]=2;
                 v1.push_back({i,j+1});
                  g--;
                  f=1;
             }
            
        }
            if(f==1)cn++;
            v=v1;
            }
        
        if(g!=0)return -1;
        return cn;
        
    }


 int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,pair<int,int>>>q;
        int m=grid.size();
        int n=grid[0].size();
        int g=0;
        vector<pair<int,int>>v;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){q.push({i,{j,0}});}
                if(grid[i][j]==1)g++;
            }
        }
        
        int cn=0;
        if(g==0)return 0;

        int k=1000;
        while(!q.empty()){  
            int i=q.front().first;
            int j=q.front().second.first;
             cn=q.front().second.second;
            q.pop();
              
             if(i-1>=0 and grid[i-1][j]==1){
                
                 grid[i-1][j]=2;
                 q.push({i-1,{j,cn+1}});
                 g--;
                 
             }
              if(i+1<m and grid[i+1][j]==1){
               
                 grid[i+1][j]=2;
                 q.push({i+1,{j,cn+1}});
                  g--;
                
             }
              if(j-1>=0 and grid[i][j-1]==1){
             
                 grid[i][j-1]=2;
                 q.push({i,{j-1,cn+1}});
                  g--;
                 
             }
              if(j+1<n and grid[i][j+1]==1){
                 
                 grid[i][j+1]=2;
                 q.push({i,{j+1,cn+1}});
                  g--;
                 
             }
            
        }
               
        if(g!=0)return -1;
        return cn;
        
    }2

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