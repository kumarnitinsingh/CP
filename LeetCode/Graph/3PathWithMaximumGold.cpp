// Created by Nitin kumar singh
// problem link -> https://leetcode.com/problems/path-with-maximum-gold/

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


int solve( vector<vector<int>>& grid,int i,int j,vector<vector<int>>& visited){
    if(i==grid.size() or j==grid[0].size() or i==-1 or j==-1)return 0;
    if(grid[i][j]==0)return 0;
    if(visited[i][j]==1)return 0;
    visited[i][j]=1;
    int ans=grid[i][j];
    ans+=max({solve(grid,i,j+1,visited),solve(grid,i,j-1,visited),solve(grid,i+1,j,visited),solve(grid,i-1,j,visited)});
    visited[i][j]=0;
    return ans;
}
class Solution {
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                vector<vector<int>>visited(m,vector<int>(n,0));
                ans=max(ans,solve(grid,i,j,visited));
            }
        }
        return ans;
    }
};


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