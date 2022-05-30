// Created by Nitin kumar singh
// problem link ->  https://cses.fi/problemset/task/1192/

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
    freopen("output3.txt","w",stdout);
    #endif
}




void solve(vector<string>&grid,int i,int j,vector<vector<int>>&visited){
    if(i<0 or j<0 or i>=grid.size() or j>=grid[0].size()){
        return;
    }


     if(visited[i][j]==1)return;
     visited[i][j]=1;
     if(grid[i][j]=='#')return;

     solve(grid,i,j+1,visited);
     solve(grid,i,j-1,visited);
     solve(grid,i+1,j,visited);
     solve(grid,i-1,j,visited);

     return;

 }





int main(int argc, char const *argv[])
{
     //clock_t start=clock();
     init_code();
    
     //write your code here

     int n,m;cin>>n>>m;

     vector<string>grid(n);
     for(int i=0;i<n;i++){
        cin>>grid[i];
     }

     vector<vector<int>>visited(n,vector<int>(m,0));
     int cn=0;

     for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){

            if(visited[i][j]==0 and grid[i][j]=='.'){
                cn++;
                solve(grid,i,j,visited);
            }
        }
     }


         cout<<cn<<endl;


   /*
    #ifndef  ONLINE_JUDGE
     clock_t end=clock();
    cout<<"\n\n\n\nExecuted in: "<<double(end-start)/(CLOCKS_PER_SEC*1000)<<" ms"<<endl;
    #endif
    */
   return 0;



}