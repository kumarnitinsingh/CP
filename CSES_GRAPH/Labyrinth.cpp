// Created by Nitin kumar singh
// problem link -> https://cses.fi/problemset/task/1193/

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


string ans="";



void dfs(vector<string>&grid,int i,int j,vector<vector<int>>&visited,string osf){
    if(i<0 or j<0 or i>=grid.size() or j>=grid[0].size()){
        return;
    }
      if(visited[i][j]==1)return;
       
    if(grid[i][j]=='#')return;
  
    if(grid[i][j]=='B'){
        if(ans.size()>osf.size()){
            ans=osf;
        }
        if(ans.size()==0){
            ans=osf;
        }
        
        return;

    }


      visited[i][j]=1;
     

     dfs(grid,i,j+1,visited,osf+"R");
     dfs(grid,i,j-1,visited,osf+"L");
     dfs(grid,i+1,j,visited,osf+"D");
     dfs(grid,i-1,j,visited,osf+"U");

      visited[i][j]=0;

     return;

 }


 const int max_n=1005;
 const int max_m=1005;
 int n,m;
 vector<vector<char>>grid(max_n,vector<char>(max_m));


vector<vector<char>>dir={{0,1,'R'},{1,0,'D'},{0,-1,'L'},{-1,0,'U'}};

vector<vector<char>>visited(max_n,vector<char>(max_m,'0'));

void bfs(int a,int b){
    queue<pair<int,int>>q;
    q.push({a,b});
    visited[a][b]='-';
    while(!q.empty()){
         pair<int,int>node=q.front();q.pop();

         int x=node.first;
         int y=node.second;

        for(auto d:dir){
            int new_x=x+d[0];
            int new_y=y+d[1];
            if(0<=new_x and new_x<n){
                if(0<=new_y and new_y<m){

                    if(visited[new_x][new_y]=='0' and grid[new_x][new_y]!='#'){
                         visited[new_x][new_y]=d[2];
                         q.push({new_x,new_y});
                    }
                }
            }
        }
    }
}


int main(int argc, char const *argv[])
{
     //clock_t start=clock();
     init_code();
    
     //write your code here

     cin>>n>>m;

     pair<int,int>p1,p2;

     for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];

            if(grid[i][j]=='A')p1={i,j};
            if(grid[i][j]=='B')p2={i,j};
        }
     } 

     bfs(p1.first,p1.second);
     if(visited[p2.first][p2.second]=='0'){cout<<"NO"<<endl;return 0;}

     else{
           string ans="";
           int x=p2.first;
           int y=p2.second;

            while(visited[x][y]!='-'){

                for(auto d:dir){
                    if(d[2]==visited[x][y]){
                        x-=d[0];
                        y-=d[1];
                        ans+=d[2];
                    }
                }
            }

            cout<<"YES"<<endl;
            cout<<ans.size()<<endl;
            reverse(ans.begin(),ans.end());
            cout<<ans<<endl;

     }



    
         


   /*
    #ifndef  ONLINE_JUDGE
     clock_t end=clock();
    cout<<"\n\n\n\nExecuted in: "<<double(end-start)/(CLOCKS_PER_SEC*1000)<<" ms"<<endl;
    #endif
    */
   return 0;



}